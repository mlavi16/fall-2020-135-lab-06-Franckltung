// Franck Limtung
// CSCI135
// 9 Oct 2020
#ifndef VIGENERE_HPP
#define VIGENERE_HPP

#include <string>

// Shifts the characters in the plaintext based on the code of the character in the keyword
// keyword wraps around when it runs out of characters
std::string encryptVigenere(std::string plaintext, std::string keyword);

#endif
