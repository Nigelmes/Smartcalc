CC = gcc
CFLAGS = -Wall -Wextra -Wextra -std=c11 -g
LFLAG = -lm

all: clean
	gcc s21_smartcalc.c -o calc $(LFLAG)
	./calc

g: clean
	git add .
	git commit -m"develop-s21_smartcalc.c"
	git push origin leftrana

test: clean
	$(CC) $(CFLAGS) t.c -o t $(LFLAG)
	./t

t: clean
	$(CC) $(CFLAGS) s21_smartcalc.c -o calc $(LFLAG)
	./calc

v: clean
	$(CC) $(CFLAGS) s21_smartcalc.c -o calc $(LFLAG)
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./calc

c:
	clang-format -i *.c
	make t

clean:
	rm -rf calc.dSYM calc t *.o

s21_smartcalc.a: s21_smartcalc.o
	ar -rc ./s21_smartcalc.a s21_smartcalc.o
	ranlib ./s21_smartcalc.a

s21_smartcalc.o:
	$(CC) $(CFLAGS) -c s21_smartcalc.c -lm