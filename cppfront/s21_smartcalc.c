#include "s21_smartcalc.h"

int validator(const char *str) {
  int errcode = 0;
  int operand = 0, i = 0;
  while (str[i]) {
    if (str[i] == 'Q') {
      operand++;
      if (strchr("+-/*^M@ABCDEFGHX", str[i - 1]) == NULL)
        errcode = 1;
    }
    if (str[i] == 'Q')
      operand--;
    i++;
  }
  if (operand != 0)
    errcode = 1;
  return errcode;
}

double pop_val(stack_type **stack) {
  stack_type *oper_stack = *stack;
  double bufer = 0.0;
  if (oper_stack == NULL) {
      oper_stack = NULL;
//    exit(1);
  } else {
    bufer = (double)oper_stack->val_dub;
    *stack = oper_stack->next;
    free(oper_stack);
  }
  return bufer;
}

stack_type *push_sta(stack_type *plist, double val_dub, int prio) {
  stack_type *Part = malloc(sizeof(stack_type));
  if (Part == NULL) {
    exit(1);
  } else {
    Part->next = plist;
    Part->prio = prio;
    Part->val_dub = val_dub;
  }
  return Part;
}

int buffering_number(
    const char *src_string,
    char *out) { //  Сборка числа в строку, возвращает длинну числа
  int i = 0;
  while ((src_string[i] >= '0' && src_string[i] <= '9') ||
         src_string[i] == '.') {
    out[i] = src_string[i];
    i++;
  }
  return i;
}

int position_counter(
    char src_string) { //  Подсчёт позиции операции строке приоритетов
  char *operators = OPERATIONS;
  int counter = 0;
  while (operators[counter]) {
    if (operators[counter] == src_string) {
      break;
    }
    counter++;
  }
  return counter;
}

//  012 345 6 789      16
//  )+- /*M ^ @ABCDEFGH(
//  1   2   3 4        5

int prio_check(char src_string) { //  Определение приоритета опреатора
  int prior = 0;
  int position_num = position_counter(src_string);
  if (position_num > 16)
    prior = 0;
  else if (position_num == 16)
    prior = 5;
  else if (position_num > 6)
    prior = 4;
  else if (position_num == 6)
    prior = 3;
  else if (position_num > 2)
    prior = 2;
  else if (position_num >= 0) //  Низкий приоритет для закрывающей скобки
    prior = 1; //  запустит подсчёт
  return prior;
}

/*   1: +,-
     2: *,/,mod(остаток от деления)
     3: ^
     4: cos,sin,tg,ctg,ln,log,!
     5: ()
     0: X Это фактически число, просто подставим его в парсере

То, что ниже - более высокий приоритет, по горизонтали - одинаковый.
Корень - это частный случай степени. */

stack_type parser_uno(const char *calculation_src, int *position,
                      double X_num) { //  Парсер одной лексеммы
  stack_type stack1 = {0};
  int prio = prio_check(calculation_src[*position]);
  if (prio) {
    stack1.prio = prio;
    stack1.val_dub = calculation_src[*position];
  } else {
    if (calculation_src[*position] == 'X') {
      stack1.prio = 0;
      stack1.val_dub = X_num;
      *position += 1;
    } else {
      char buf[256] = {0};
      *position =
          *position + buffering_number(&calculation_src[*position], buf);
      double tess = atof(buf);
      stack1.prio = prio;
      stack1.val_dub = tess;
    }
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
      printf(" %.7lf", Ptrack->val_dub);
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

stack_type *del_point(stack_type *stack1) { //  Удалит последний элемент списка
  stack_type *Ptrack_bac = stack1->next;
  free(stack1);
  return Ptrack_bac;
}

//  Простые бинарные мат операции (вычисление)
double simple_math(double second_num, double first_num, char operation) {
  double out_num = 0.0;
  switch (operation) {
  case '+':
    out_num = first_num + second_num;
    break;
  case '-':
    out_num = first_num - second_num;
    break;
  case '*':
    out_num = first_num * second_num;
    break;
  case '/':
    out_num = first_num / second_num;
    break;
  case '^':
    out_num = pow(first_num, second_num);
    break;
  case 'M':
    out_num = fmod(first_num, second_num);
    break;
  }
  return out_num;
}

//  Вычисление тригонометрии
double trigon_calc(double x, char operation) {
  double buf_num = 0.0;
  switch (operation) {
  case COS:
    buf_num = cos(x);
    break;
  case SIN:
    buf_num = sin(x);
    break;
  case TAN:
    buf_num = tan(x);
    break;
  case ACOS:
    buf_num = acos(x);
    break;
  case ASIN:
    buf_num = asin(x);
    break;
  case ATAN:
    buf_num = atan(x);
    break;
  case SQRT:
    buf_num = sqrt(x);
    break;
  case LN:
    buf_num = log(x);
    break;
  case LOG:
    buf_num = log10(x);
    break;
  }
  return buf_num;
}

//  Выполнение операции подсчета
double math_operations(stack_type **num_sta, stack_type **oper_sta) {
  double buf_num = 0.0;
  if ((*oper_sta)->prio < 4) {
    double second = pop_val(num_sta);
    double first = pop_val(num_sta);
    char operat = (char)pop_val(oper_sta);
    buf_num = simple_math(second, first, operat);
  } else if ((*oper_sta)->prio < 5) {
    buf_num = pop_val(num_sta);
    char oper_buf = pop_val(oper_sta);
    buf_num = trigon_calc(buf_num, oper_buf);
  }
  return buf_num;
}

//  Проверка унарного плюса
int unar_check(char check, const char *oper_st, int position) {
  int unar_minus_find = 0;
  if ((check == '-' || check == '+') && !position)
    unar_minus_find = 1;
  if ((check == '-' || check == '+') && position > 0)
    if (oper_st[position - 1] == '(')
      unar_minus_find = 1;
  return unar_minus_find;
}

//  Определение открывающей скобки с защитой попадания на NULL
int bracket_finder(stack_type *oper) {
  int finded = 0;
  if (oper != NULL)
    if (oper->val_dub == '(')
      finded = 1;
  return finded;
}

double calc(const char *calculation_src, double X_num) {
  int position = 0;
  stack_type *st_oper = NULL;
  stack_type *st_num = NULL;
  while (calculation_src[position]) { //  Главный цикл вычисления
    stack_type st_buf =
        parser_uno(calculation_src, &position, X_num); //  Парсим одну лексемму
    if (st_buf.prio) { //  Если получили операцию или скобку
      while (st_buf.val_dub) {
        if (st_buf.val_dub == ')' && bracket_finder(st_oper)) {
          //  Если пришла скобка закр а в стеке скобка откр
          st_oper = del_point(st_oper);
          st_buf.val_dub = 0.0;
        } else if (unar_check(st_buf.val_dub, calculation_src, position)) {
          st_oper = push_sta(st_oper, st_buf.val_dub, st_buf.prio);
          st_num = push_sta(st_num, 0.0, 0); //  Получили унарный знак
          st_buf.val_dub = 0.0;
        } else if (st_oper == NULL || st_oper->val_dub == '(') {
          // Если стэк пуст или в нём скобка
          st_oper = push_sta(st_oper, st_buf.val_dub, st_buf.prio);
          st_buf.val_dub = 0.0;
        } else if (st_buf.prio > st_oper->prio) { //  Если приоритет опреации
          st_oper = push_sta(st_oper, st_buf.val_dub,
                             st_buf.prio); //  больше приоритета
          st_buf.val_dub = 0.0;            //  в стеке
        } else {
          double buf_num = math_operations(&st_num, &st_oper);
          st_num = push_sta(st_num, buf_num, 0); //  Выполнить расчёт
        } //  т.к. остальные условия не прошли
      }
      position++;
    } else { //  Если получили число
      st_num = push_sta(st_num, st_buf.val_dub, st_buf.prio);
    }
  }
  while (st_oper != NULL) { //  Расчёт оставшегося содержимого стеков
    if (bracket_finder(st_oper)) {
      st_oper = del_point(st_oper);
      //  Если забыли поставить скобки в конце уравнения
      continue;
    }
    //  Если пришло число, просто отправляем в стек чисел
    double buf_num = math_operations(&st_num, &st_oper);
    st_num = push_sta(st_num, buf_num, 0);
  }
  double result = 0.0;
  if (st_num != NULL) {
    result = st_num->val_dub;
  }
  destroy_node(st_num);
  return result;
}

double start_calc(const char *src, double X_num) {
  double result = 0.0;
  //  printf("resourse %s ", src);
  if (validator(src) == 0)
    result = calc(src, X_num);
  else
    printf("Ошибка");
  return result;
}

int in_line_start(const char *str, int str_len) {
  int in_start = FALSE;
  if (str[0] == '0' && str_len == 1)
    in_start = TRUE;
  return in_start;
}

int is_simp_oper(char oper) {
  int it_oper = FALSE;
  int oper_string = position_counter(oper);
  if (oper_string > 0 && oper_string < 7)
    it_oper = TRUE;
  return it_oper;
}

int char_counter(const char *str_line, char res) {
  int counter = 0, i = 0;
  while (str_line[i]) {
    if (str_line[i] == res)
      counter++;
    i++;
  }
  return counter;
}

int is_nums(char num) {
  int is_num = FALSE;
  if (('0' <= num && num <= '9') || num == '.')
    is_num = TRUE;
  return is_num;
}

int last_is(char res) {
  int is_number = FALSE;
  if (is_nums(res) || res == '.' || res == ')' || res == 'X')
    is_number = TRUE;
  return is_number;
}

int smart_bracket(const char *str_line) {
  int closed_bracket = FALSE;
  int len = strlen(str_line);
  int open_bracket_val = char_counter(str_line, '(');
  int close_bracket_val = char_counter(str_line, ')');
  int last_sym = last_is(str_line[len - 1]);

  if ((open_bracket_val > close_bracket_val) && last_sym) {
    closed_bracket = TRUE;
  } else if (in_line_start(str_line, len) || is_simp_oper(str_line[len - 1]) ||
             str_line[len - 1] == '(') {
    closed_bracket = FALSE;
  } else {
    closed_bracket = ERROR;
  }
  return closed_bracket;
}

int valid_simp_oper(const char * str_line) {
  int valid_oper = FALSE;
  int len = strlen(str_line);
  char lastch = str_line[len - 1];
  int last = last_is(lastch);
  if(last && !in_line_start(str_line, len))
    valid_oper = TRUE;
  return valid_oper;
}

int valid_func(const char * str_line) {
  int validfunc = FALSE;
  int len = strlen(str_line);
  if(is_simp_oper(str_line[len - 1]) || str_line[len - 1] == '(' || in_line_start(str_line, len))
    validfunc = TRUE;
  return validfunc;
}

int valid_nums(const char * str_line) {
  int validfunc = FALSE;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if((is_simp_oper(lastchar) || lastchar == '(' || in_line_start(str_line, len) || is_nums(lastchar)) && lastchar != 'X')
    validfunc = TRUE;
  return validfunc;
}

int valid_equals(const char * str_line) {
  int validequals = FALSE;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if(lastchar == ')' || is_nums(lastchar) || lastchar == 'X')
    validequals = TRUE;
  return validequals;
}

int valid_unar(const char * str_line) {
  int validunar = FALSE;
  int len = strlen(str_line);
  char lastchar = str_line[len - 1];
  if(lastchar == '(' || in_line_start(str_line, len))
    validunar = TRUE;
  return validunar;
}

int valid_dot(const char * str_line) {
  int validdot = TRUE;
  int i = 0;
  int len = strlen(str_line);
  while (is_nums(str_line[len-1-i])) {
    if(str_line[len-1-i] == '.') {
      validdot = FALSE;
    break;
    }
    i++;
  }
  return validdot;
}

int valid_dot_line(const char * str_line) {
  int validdot = TRUE;
  int i = 0;
  int len = strlen(str_line);
  while (is_nums(str_line[len-1-i])) {
    if(str_line[len-1-i] == '.') {
      validdot++;
    }
    i++;
  }
  if (validdot > 2) validdot = FALSE;
  return validdot;
}

int valid_input_line(double maxval, double minval, const char * str_line) {
    int validline = TRUE;
    int len = strlen(str_line);
    char lastchar = str_line[len-1];
    if(str_line[1] == '\0' && lastchar == '-') {
        validline = TRUE;
    } else if (lastchar == '.') {
      validline = valid_dot_line(str_line);
    } else if (validline) {
      validline = is_nums(lastchar);
    }
    if (validline) {
      double test = atof(str_line);
      if(minval > test || test > maxval)
        validline = FALSE;
    }
    return validline;
}
