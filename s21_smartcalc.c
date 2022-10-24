#include "s21_smartcalc.h"

// typedef struct N {
//   double val;
//   int prio;
//   struct N* next; 
// } N;

int validator(const char *str) {
  int errcode = 0;
  int operand = 0, i = 0;
  while (str[i]) {
    if (str[i] == '(') {
      operand++;
      if (strchr("+-/*^%@ABCDEFGH", str[i - 1]) == NULL) errcode = 1;
    }
    if (str[i] == ')') operand--;
    i++;
  }
  if (operand != 0) errcode = 1;
  return errcode;
}

double pop_double (stack_type *num_stack) {
  double bufer = 0.0;
  if (num_stack == NULL) {
    printf("FUCK OFF2!!!");
    exit(1);
  }
  bufer = num_stack->val_dub;
  if (num_stack->next==NULL) {
    printf("\n BOOOM1 \n");
    free(num_stack);
    num_stack = NULL;
  } else {
    stack_type * bufer = num_stack->next;
    printf("\n BOOOM2 \n");
    free(num_stack);
    num_stack = bufer;
  }
  return bufer;
}

char pop_oper (stack_type **oper_stack) {
  char bufer = '0';
  if (oper_stack == NULL) {
    printf("FUCK OFF!!!");
    exit(1);
  }
  bufer = (char)oper_stack->val_dub;
  if (oper_stack->next==NULL) {
    free(oper_stack);
    oper_stack = NULL;
  } else {
    stack_type * bufer = oper_stack->next;
    free(oper_stack);
    oper_stack = bufer;
  }
  return bufer;
}

stack_type *push_sta(stack_type *plist, double val_dub, int prio) {
  stack_type *Part = malloc(sizeof(stack_type));
  if (Part == NULL) {
    exit(1);
  }
  Part->next = plist;
  Part->prio = prio;
  Part->val_dub = val_dub;
  return Part;
}

int buffering_number(const char *src_string, char *out) {
  int i = 0;
  while ((src_string[i] >= '0' && src_string[i] <= '9') ||
         src_string[i] == '.') {
    out[i] = src_string[i];
    i++;
  }
  return i;
}

int position_counter(char src_string) {
  char *operators = OPERATIONS;
  int counter = 0;
  while (operators[counter]) {
    if (operators[counter] == src_string) {
      break;
    }
    counter++;
  }
  return counter + 1;
}

int prio_check(char src_string) {
  int prior = 0;
  int position_num = position_counter(src_string);
  if (position_num == 18)
    prior = 0;
  else if (position_num == 17)
    prior = 6;
  else if (position_num == 16)
    prior = 5;
  else if (position_num > 6)
    prior = 4;
  else if (position_num > 5)
    prior = 3;
  else if (position_num > 2)
    prior = 2;
  else if (position_num > 0)
    prior = 1;
  return prior;
}

/*  +,-
*,/
^
cos,sin,tg,ctg,ln,log,!
()

То, что ниже - более высокий приоритет, по горизонтали - одинаковый.
Корень - это частный случай степени. */

stack_type parser_uno(const char *calculation_src, int *position) {
  stack_type stack1 = {0};
  int prio = prio_check(calculation_src[*position]);
  if (prio) {
    stack1.prio = prio;
    stack1.val_dub = calculation_src[*position];
  } else {
    char buf[256] = {0};
    *position = *position + buffering_number(&calculation_src[*position], buf);
    double tess = atof(buf);
    stack1.prio = prio;
    stack1.val_dub = tess;
  }
  return stack1;
}

void print_from_node(stack_type *stack1) {
  stack_type *Ptrack = stack1;
  printf("\n");
  while (Ptrack) {
    if (Ptrack->prio) {
      printf(" %dpri%c", Ptrack->prio, (char)Ptrack->val_dub);
    } else {
      printf(" %dpri%.2lf", Ptrack->prio, Ptrack->val_dub);
    }
    Ptrack = Ptrack->next;
  }
  printf("\n");
}

void destroy_node(stack_type *stack1) {
  stack_type *Ptrack = stack1;
  while (Ptrack) {
    stack_type *Ptrack_bac = Ptrack->next;
    free(Ptrack);
    Ptrack = Ptrack_bac;
  }
  free(Ptrack);
}

double calculating(double second_num, double first_num, char operation) {
  double out_num = 0.0;
  switch (operation) {
    case '+':
      out_num = first_num + second_num;
      break;
    case '-':
      out_num = first_num + second_num;
      break;
    case '*':
      out_num = first_num + second_num;
      break;
    case '/':
      out_num = first_num + second_num;
      break;
  }
  return out_num;
}

int calc(const char *calculation_src) {
  int position = 0;
  stack_type *st_oper = NULL;
  stack_type *st_num = NULL;
  printf("\n");
  while (calculation_src[position]) {  //  Главный цикл вычисления
    stack_type st_buf = parser_uno(calculation_src, &position);  //  Парсим одну сексемму из строки
    if (st_buf.prio) {  //  Если получили операцию или скобку
      // printf(" priori%doper%c", st_buf.prio, (char)st_buf.val_dub);
      while(st_buf.val_dub) {
        if (st_oper == NULL) {  //   Если стэк пуст
          st_oper = push_sta(st_oper, st_buf.val_dub, st_buf.prio);
          st_buf.val_dub = 0.0;
        } else if (st_buf.prio == 5 && st_oper->prio != 6) {  //  Если пришла скобка а в стеке нет скобки
          st_oper = push_sta(st_oper, st_buf.val_dub, st_buf.prio);
          st_buf.val_dub = 0.0;
        } else if (st_buf.prio > st_oper->prio) {  //  Ели приоритет опреации больше приоритета в стеке 
          st_oper = push_sta(st_oper, st_buf.val_dub, st_buf.prio);
          st_buf.val_dub = 0.0;
        } else {
          double second = pop_double(st_num);
          double first = pop_double(st_num);
          char oper = pop_oper(st_oper);
          double buf_num = calculating(second, first, oper);  //  Расчёт двух чисел из стека и операции 
          st_oper = push_sta(st_num, buf_num, 0);
        }
      }
      position++;
    } else {  //  Если получили число
      st_num = push_sta(st_num, st_buf.val_dub, st_buf.prio);
      printf(" %dpri%0.2lf", st_buf.prio, st_buf.val_dub);
    }
  }
  printf("\n");
  print_from_node(st_num);
  print_from_node(st_oper);
  //destroy_node(st_num);
  //destroy_node(st_oper);
  return 0;
}

// int main(void) {
//   const char *arr = "3+2+5*6/2+5*4+6-4";
//   printf("%s", arr);
//   if (validator(arr) == 0)
//     calc(arr);
//   else
//     printf("Ошибка");
//   return 0;
// }

//  "-255.55+39.45*5555/158+A(55.66+15.78)"
