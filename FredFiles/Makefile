all: main
	./Trabalho
main: countFortran.o main.o
	gfortran -o Trabalho countFortran.o main.o
main.o: main.c
	gcc -c main.c
countFortran.o: countFortran.f95
	gfortran -c countFortran.f95
