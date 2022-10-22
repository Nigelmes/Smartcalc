#include "s21_smartcalc.h"

// typedef struct N {
//   double val_dub;
//   int prio;
//   struct N* next;
// } N;

typedef struct Node_stack {
  double val_dub;
  int prio;
  struct Node_stack *next;
} stack_type;

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

/*  Резерв

N* pop1(N** head) {
  N* out;
  if ((*head) == NULL) {
    exit(2);
  }
  out = *head;
  *head = (*head)->next;
  return out;
}

N* peek(N** head) {
  if ((*head) == NULL) {
    exit(2);
  }
  return *head;
}
*/

stack_type *push_sta(stack_type *plist, double val_dub, int prio) {
  stack_type *Part = malloc(sizeof(stack_type));
  if (Part == NULL) {
    free(Part);
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

int calc(const char *calculation_src) {
  int position = 0;
  stack_type *st_oper = NULL;
  stack_type *st_num = NULL;
  printf("\n");
  while (calculation_src[position]) {  //  Главный цикл вычисления
    stack_type st_buf = parser_uno(calculation_src, &position);
    if (st_buf.prio) {  //  Если получили операцию или скобку
      if (st_oper == NULL) {
        st_oper = push_sta(st_oper, st_buf.val_dub, st_buf.prio);
      } else if (st_buf.prio >= st_oper->prio){

      }
      printf(" pri%doper%c", st_buf.prio, (int)st_buf.val_dub);
      position++;
    } else {  //  Если получили число
      st_num = push_sta(st_num, st_buf.val_dub, st_buf.prio);
      printf(" %dpri%0.2lf", st_buf.prio, st_buf.val_dub);
    }
  }
  printf("\n");
  print_from_node(st_num);
  print_from_node(st_oper);
  destroy_node(st_num);
  destroy_node(st_oper);
  return 0;
}

int main(void) {
  const char *arr = "-255.55+39.45*5555/158+A(55.66+15.78)";
  printf("%s", arr);
  if (validator(arr) == 0)
    calc(arr);
  else
    printf("Ошибка");
  return 0;
}

//  "-255.55+39.45*5555/158+A(55.66+15.78)"
