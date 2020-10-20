// Franck Limtung
// CSCI135 
// 9 Oct 2020

#pragma once

#include <string>

// Outputs the characters and their ascii codes for the input string
void test_ascii(std::string text);

// Returns if the character is a lower case alphabetic character
bool isLowerCase(char c);

bool isUpperCase(char c);

// Shifts alphabetic characters by rshift, ignores non-alphabetics
char shiftChar(char cAlphabetic, int rshift);

std::string fileToString(std::string filename);
