#include "s21_smartcalc.h"

int main(void) {
  double result = 0.0, X = 1.0;
  
  const char *arr = "-3.5556*@29-5+4*6+5.51*(+6/(2+5)*(+4+(-3^6)))-4*3/2";
  if (validator(arr) == 0) {
    result = calc(arr, X);
  }
  else
    printf("Ошибка");
  printf("%s \n", arr);
  printf("Равно %0.7lf\n", result);
  return 0;
}
