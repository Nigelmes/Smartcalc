#include "s21_smartcalc.h"

double pop(stack_type **plist) {
  stack_type *p = *plist;
  double res = p->val_dub;
  *plist = p->next;
  free(p);
  return res;
}

double math_operations(stack_type **num, stack_type **oper) {
  stack_type *oper_st = *oper;
  stack_type *num_st = *num;
  double buf_num;
  if (oper_st->prio < 3) {
    double second = pop_val(&num_st);
    double first = pop_val(&num_st);
    char oper = (char)pop_val(&oper_st);
    //  Расчёт двух чисел из стека и операции
    buf_num = simple_math(second, first, oper);
  }
  return buf_num;
}

double pop_from_stack(stack_type **stack) {
  stack_type *oper_stack = *stack;
  double bufer = 0.0;
  if (oper_stack == NULL) {
    exit(1);
  }
  bufer = (double)oper_stack->val_dub;
  *stack = oper_stack->next;
  free(oper_stack);
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

int main(void) {
  stack_type *st = NULL;
  st = push_sta(st, '*', 2);
  st = push_sta(st, '/', 2);
  double i = pop_oper(&st);
  printf("\n %lf \n", i);
  i = pop_oper(&st);
  printf("\n %lf \n", i);
  return 0;
}