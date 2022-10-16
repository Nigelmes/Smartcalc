#include "s21_smartcalc.h"

typedef struct N {
  double value;
  int priority;
  struct N* next;
} N;

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

void parser(const char* calculation_src, N* stack) {
  int i = 0;
  while (calculation_src[i]) {
    if (is_operator(calculation_src[i])) {
      // push(&stack);
      printf(" oper%c", calculation_src[i]);
      i++;
    } else {
      double tess = 0.0;
      char buf[256] = {0};
      i = i + buffering_number(&calculation_src[i], buf);
      tess = atof(buf);
      push(&stack, tess, 0);
      printf(" %.2lf", tess);
    }
  }
}

void print_from_list(N* stack) {
  if (stack == NULL) printf("click");
  // printf("%.2lf", stack->value);
}

int calc(const char* calculation_src) {
  N* stack = NULL;
  parser(calculation_src, stack);
  // print_from_list(stack);
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
