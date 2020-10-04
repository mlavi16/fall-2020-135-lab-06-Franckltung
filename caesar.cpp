#include "caesar.h"
#include "funcs.h"

std::string encryptCaesar(std::string plaintext, int rshift) {
	std::string encrypted = plaintext;
	for (int i = 0; i < encrypted.length(); i++) {
		encrypted[i] = shiftChar(encrypted[i], rshift);
	}
	
	return encrypted;
}
