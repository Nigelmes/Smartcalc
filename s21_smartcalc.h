#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPERATIONS  "+-/*%^@ABCDEFGH()"

enum truefalse {
  false,
  true,
  COS = '@',
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG
};

#endif  // SRC_S21_SMARTCALC_H_
