all: 
	gcc s21_smartcalc.c -o calc
	./calc

g:
	git add .
	git commit -m"develop-s21_smartcalc.c"
	git push origin develop