CC = gcc
CFLAGS = -Wall -Wextra -Wextra -std=c11 -g

all: 
	gcc s21_smartcalc.c -o calc
	./calc

g:
	git add .
	git commit -m"develop-s21_smartcalc.c"
	git push origin leftrana

t:
	$(CC) $(CFLAGS) s21_smartcalc.c -o calc
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./calc