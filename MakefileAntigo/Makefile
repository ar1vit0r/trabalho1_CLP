CC=gcc
CX=gFortran

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 
F90FLAGS= -Wall -Wextra -lowercase alignments 

.PHONY: all

all: grade

testC.o: testC.c

trabalho: testC.o trabalho.f90
	$(CX) testC.o trabalho.f90 -o trabalho

grade: trabalho
	./trabalho
