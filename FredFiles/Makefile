all: main
	./TrabalhoExe
main: count.o main.o
	gfortran -o TrabalhoExe main.o count.o
main.o: main.c
	gcc -o main.o main.c
#	@echo "Compila main"
count.o: countFortran.f03
	gfortran -o count.o countFortran.f03
#	@echo "Compila count"
