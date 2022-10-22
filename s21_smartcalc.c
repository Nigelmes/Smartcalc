#include "s21_smartcalc.h"

// typedef struct N {
//   double value;
//   int priority;
//   struct N* next;
// } N;

typedef struct Node_stack {
  double value;
  int priority;
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
void push(N** head, double value, int prior) {
  N* tmp = malloc(sizeof(N));
  if (tmp == NULL) {
    exit(1);
  }
  tmp->next = *head;
  tmp->value = value;
  tmp->priority = prior;
  *head = tmp;
}

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

stack_type *push_my(stack_type *plist, double value, int priority) {
  stack_type *Part = malloc(sizeof(stack_type));
  if (Part == NULL) {
    free(Part);
    exit(1);
  }
  Part->next = plist;
  Part->priority = priority;
  Part->value = value;
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
  int counter = 0, triger = 0;
  while (operators[counter]) {
    if (operators[counter] == src_string) {
      triger = 1;
      break;
    }
    counter++;
  }
  return triger ? counter + 1 : 0;
}

int priority_check(char src_string) {
  int prior = 0;
  int position_num = position_counter(src_string);
  if (position_num == 0)
    prior = 0;
  else if (position_num > 15)
    prior = 5;
  else if (position_num > 6)
    prior = 4;
  else if (position_num > 5)
    prior = 3;
  else if (position_num > 2)
    prior = 2;
  else if (position_num >= 1)
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

/*  Резерв
stack_type * parser(const char* calculation_src) {
  int i = 0;
  stack_type* stack1 = NULL;
  while (calculation_src[i]) {
    int priority = priority_check(calculation_src[i]);
    if (priority) {
      stack1 = push_my(stack1, calculation_src[i], priority);
      i++;
    } else {
      char buf[256] = {0};
      i = i + buffering_number(&calculation_src[i], buf);
      double tess = atof(buf);
      stack1 = push_my(stack1, tess, priority);
    }
  }
  return stack1;
}
*/

stack_type parser_uno(const char *calculation_src, int *position) {
  stack_type stack1 = {0};
  int priority = priority_check(calculation_src[*position]);
  if (priority) {
    stack1.priority = priority;
    stack1.value = calculation_src[*position];
  } else {
    char buf[256] = {0};
    *position = *position + buffering_number(&calculation_src[*position], buf);
    double tess = atof(buf);
    stack1.priority = priority;
    stack1.value = tess;
  }
  return stack1;
}

void print_from_node(stack_type *stack1) {
  stack_type *Ptrack = stack1;
  printf("\n");
  while (Ptrack) {
    if (Ptrack->priority) {
      printf(" %dpri%c", Ptrack->priority, (char)Ptrack->value);
    } else {
      printf(" %dpri%.2lf", Ptrack->priority, Ptrack->value);
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
  stack_type *stack_operations = NULL;
  stack_type *stack_numbers = NULL;
  printf("\n");
  while (calculation_src[position]) {  //  Главный цикл вычисления
    stack_type stack_buf = parser_uno(calculation_src, &position);
    if (stack_buf.priority) {  //  Если получили операцию или скобку

      printf(" pri%doper%c", stack_buf.priority, (int)stack_buf.value);
      position++;
    } else {  //  Если получили число
      stack_numbers =
          push_my(stack_numbers, stack_buf.value, stack_buf.priority);
      printf(" %dpri%0.2lf", stack_buf.priority, stack_buf.value);
    }
  }
  printf("\n");

  print_from_node(stack_numbers);
  destroy_node(stack_numbers);
  destroy_node(stack_operations);
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
