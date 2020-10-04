#include "decrypt.h"
#include "caesar.h"
#include "funcs.h"

std::string decryptCaesar(std::string ciphertext, int rshift) {
	return encryptCaesar(ciphertext, -rshift); // Get the opposite shift of the orignal encryption
}

std::string decryptVigenere(std::string ciphertext, std::string keyword) {
	// Same process as encryption, but with the opposite character shift for each letter in keyword
	if (keyword.length() <= 0) return ciphertext;

	std::string plaintext = ciphertext;

	int keywordIterator = -1;
			
	for (int i = 0; i < plaintext.length(); i++) {
		int keywordShift = 0;
		
		if (isUpperCase(plaintext[i]) || isLowerCase(plaintext[i])) {
			keywordIterator++;
		}
		else continue;
	
		keywordIterator = keywordIterator % keyword.length();
		
		if (isUpperCase(keyword[keywordIterator])) {
			keywordShift = keyword[keywordIterator] - 'A';
		}
		else if (isLowerCase(keyword[keywordIterator])) {
			keywordShift = keyword[keywordIterator] - 'a';
		}
		
		plaintext[i] = shiftChar(plaintext[i], -keywordShift); // Inverse keywordShift
	}
	
	return plaintext;
}
