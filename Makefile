main: main.o funcs.o caesar.o vigenere.o decrypt.o decode.o
	g++ -o main main.o funcs.o caesar.o vigenere.o decrypt.o decode.o

tests: tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o
	g++ -o tests tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o


funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h caesar.h vigenere.h decrypt.h decode.h

tests.o: tests.cpp  doctest.h funcs.h caesar.h vigenere.h decrypt.h decode.h

caesar.o: caesar.cpp caesar.h funcs.h

vigenere.o: vigenere.cpp vigenere.h funcs.h

decrypt.o: decrypt.cpp decrypt.h funcs.h caesar.h

decode.o: decode.cpp decode.h funcs.h caesar.h


clean:
	rm -f main.o tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o

help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests

