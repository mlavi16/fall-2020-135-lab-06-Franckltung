// Franck Limtung
// CSCI135
// 9 Oct 2020
#include <iostream>

#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{	
	std::cout << "test_ascii:\n";
	test_ascii("Test ascii");
	
	std::string plaintext = "Hello, World!";
	std::cout << "\nPlaintext: " << plaintext << "\n";
	std::cout << "\n= Caesar =\n";
	std::cout << "Shift: 10\n";
	std::cout << "Ciphertext: " << encryptCaesar(plaintext, 10) << "\n";
	std::cout << "Decrypted: " << decryptCaesar(encryptCaesar(plaintext, 10), 10) << "\n";

	std::cout << "\n= Vigenere =\n";
	std::cout << "Keyword: cake\n";
	std::cout << "Ciphertext: " << encryptVigenere(plaintext, "cake") << "\n";
	std::cout << "Decrypted: " << decryptVigenere(encryptVigenere(plaintext, "cake"), "cake") << "\n";

	return 0;
}
