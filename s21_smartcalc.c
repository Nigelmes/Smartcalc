#include "s21_smartcalc.h"

typedef struct N {
  double value;
  int priority;
  struct N* next;
} N;

typedef struct Node_stack {
  double value;
  int priority;
  struct Node_stack* next;
} stack_type;

int validator(const char* str) {
  int errcode = 0;
  int operand = 0, dot = 0, i = 0;
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

stack_type *push_my(stack_type *plist , double value, int priority) {
  stack_type *Part = malloc(sizeof(stack_type));
  if (Part == NULL) {
    exit(1);
  }
  Part->next = plist;
  Part->priority = priority;
  Part->value = value;
  return Part;
}

int is_operator(char src_string) {
  int errcode;
  char* operators = "+-/*^%()@ABCDEFGH";
  char* res = strchr(operators, src_string);
  if (res) {
    errcode = true;
  } else
    errcode = false;
  return errcode;
}

int buffering_number(const char* src_string, char* out) {
  int i = 0;
  while (src_string[i] >= '0' && src_string[i] <= '9' || src_string[i] == '.') {
    out[i] = src_string[i];
    i++;
  }
  return i;
}

int priority_check(char src_string){
 return 1;
}

stack_type * parser(const char* calculation_src) {
  int i = 0;
  stack_type* stack1 = NULL;
  while (calculation_src[i]) {
    if (is_operator(calculation_src[i])) {
      int priority = priority_check(calculation_src[i]);
      stack1 = push_my(stack1, calculation_src[i], priority);
      printf(" oper%c", (char)stack1->value);
      i++;
    } else {
      double tess = 0.0;
      char buf[256] = {0};
      i = i + buffering_number(&calculation_src[i], buf);
      tess = atof(buf);
      stack1 = push_my(stack1, tess, 0);
      printf(" %.2lf", stack1->value);
    }
  }
  return stack1;
}

void print_from_node(stack_type* stack1) {
  if (stack1 == NULL) printf("click");
  else printf("%c", (char)stack1->value);
}

int calc(const char* calculation_src) {
  stack_type* stack1 = NULL;
  stack1 = parser(calculation_src);
  print_from_node(stack1);
  return 0;
}

int main(void) {
  const char* arr = "-255.55+39.45*5555/158+A(55.66+15.78)";
  if (validator(arr) == 0)
    calc(arr);
  else
    printf("Ошибка");
  return 0;
}
