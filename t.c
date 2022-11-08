#include "s21_smartcalc.h"

int main(void) {
  double result = 0.0, X = 1.0;
  
  const char *arr = "5+X+5";
  if (validator(arr) == 0) {
    result = calc(arr, X);
  }
  else
    printf("Ошибка");
  printf("%s \n", arr);
  printf("Равно %0.7lf\n", result);
  return 0;
}
