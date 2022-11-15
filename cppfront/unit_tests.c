#include "s21_smartcalc.h"

int main(void) {
  const char *arr = "1234567890";
  int str_len = strlen(arr), i = 0;
  while(arr[i]) {
  if (is_nums(arr[i]))
    printf("Good\n");

  printf("Str_len = %d Arr = %c \n",str_len, arr[i]);
  i++;
  }
  return 0;
}
