#include <iostream>
#include <fstream>
#include "funcs.h"

void test_ascii(std::string text) {
	for (int i = 0; i < text.length(); i++) {
		// Print character and ascii code
		std::cout << text[i] << " " << (int)text[i] << "\n";
	}
}

bool isLowerCase(char c) {
	// Check if the character is within the range of a to z
	if (c >= 'a' && c <= 'z') return true;
	// Else
	return false;
}

bool isUpperCase(char c) {
	if (c >= 'A' && c <= 'Z') return true;
	
	return false;
}

char shiftChar(char cAlphabetic, int rshift) {
	char firstLetter; // Stores the first letter of the alphabet, it can be upper case A or lower case a
	if (isLowerCase(cAlphabetic)) {
		firstLetter = 'a';
	}
	else if (isUpperCase(cAlphabetic)) { 
		firstLetter = 'A';
	}
	else return cAlphabetic; // Don't shift non-alphabetics

	// Clamp the value of rshift to within the alphabetic range
	rshift = rshift % 26;

	// Get the distance as an integer of cAlphabetic from the first letter of the alphabet
	int cIndex = cAlphabetic - firstLetter;
	
	// Get index of character plus offset
	cIndex += rshift;

	// Wrap index around if it exceeds the alphabetical characters, which are from 0 to 25
	if (cIndex >= 26) {
		cIndex -= 26;
	}
	else if (cIndex < 0) {
		cIndex += 26;
	}

	return firstLetter + cIndex; // Return the first character of the alphabet plus the clamped shift
}

std::string fileToString(std::string filename) {
	std::string str;
	
	std::ifstream file(filename);
	if (!file) {
		std::cout << "Error opening \"" << filename << "\".\n";
		return "";
	}
	
	std::string line;
	while (getline(file, line)) {
		str += line + "\n";
	}

	file.close();

	return str;
}
