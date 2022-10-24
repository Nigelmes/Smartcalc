#include "s21_smartcalc.h"

char pop_oper (stack_type *oper_stack) {
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

int main(void) {
    stack_type * st = NULL;
    st = push_sta(st, 2.0, 0);
    printf("\n %lf \n", st->val_dub);
    st = push_sta(st, 2.0, 0);
    printf("\n %lf \n", st->val_dub);
    pop_oper(st);
    printf("\n %lf \n", st->val_dub);
  return 0;
}