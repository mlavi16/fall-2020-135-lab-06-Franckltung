

main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o 
	g++ -o tests tests.o 


funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h


tests.o: tests.cpp  doctest.h

clean:
	rm -f main.o tests.o funcs.o

help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests

