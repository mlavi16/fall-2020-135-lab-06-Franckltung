// Franck Limtung
// CSCI135
// 9 Oct 2020
#ifndef DECRYPT_HPP
#define DECRYPT_HPP

#include <string>

// Reverse the encryptCaesar function
std::string decryptCaesar(std::string ciphertext, int rshift);

// Reverse the encryptVigenere function
std::string decryptVigenere(std::string ciphertext, std::string keyword);

#endif
