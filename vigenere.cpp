#include "vigenere.h"
#include "funcs.h"

std::string encryptVigenere(std::string plaintext, std::string keyword) {
	if (keyword.length() <= 0) return plaintext; // No keyword, plaintext won't be changed

	std::string encrypted = plaintext;

	// Iterator over keyword for the character to be used for shifting
	int keywordIterator = -1; // Starts at minus one because it is advanced before it is used
			
	for (int i = 0; i < encrypted.length(); i++) {
		int keywordShift = 0; // Amount to shift the plaintext character, based on the keyword
		
		// Only advance the keyword iterator when the plaintext character is alphabetic
		if (isUpperCase(encrypted[i]) || isLowerCase(encrypted[i])) {
			keywordIterator++;
		}
		else continue; // Don't advance the iterator, and don't modify the non-alphabetic character
	
		keywordIterator = keywordIterator % keyword.length(); // Clamp the value of keywordIterator to within the keyword
		
		// Shift distance is the distance of keyword[keywordIterator] from the first letter of the alphabet
		if (isUpperCase(keyword[keywordIterator])) {
			keywordShift = keyword[keywordIterator] - 'A';
		}
		else if (isLowerCase(keyword[keywordIterator])) {
			keywordShift = keyword[keywordIterator] - 'a';
		}
		// Else, if the keyword character is not alphabetic, the plaintext character won't shift at all
		
		encrypted[i] = shiftChar(encrypted[i], keywordShift);
	}
	
	return encrypted;
}
