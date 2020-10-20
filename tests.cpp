#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "decode.h"

TEST_CASE("Test isLowerCase") {
	CHECK(isLowerCase('a') == true);
	CHECK(isLowerCase('z') == true);
	CHECK(isLowerCase('f') == true);
	CHECK(isLowerCase('A') == false);
	CHECK(isLowerCase('Z') == false);
	CHECK(isLowerCase(' ') == false);
	CHECK(isLowerCase(0) == false);
	CHECK(isLowerCase(127) == false);
}

TEST_CASE("Test isUpperCase") {
	CHECK(isUpperCase('A') == true);
	CHECK(isUpperCase('Z') == true);
	CHECK(isUpperCase('F') == true);
	CHECK(isUpperCase('a') == false);
	CHECK(isUpperCase('z') == false);
	CHECK(isUpperCase(' ') == false);
	CHECK(isUpperCase(0) == false);
	CHECK(isUpperCase(127) == false);
}

TEST_CASE("Test shiftChar") {
	// Lots of things to test
	CHECK(shiftChar('a', 1) == 'b');
	CHECK(shiftChar('a', 25) == 'z');
	CHECK(shiftChar('a', 0) == 'a');
	CHECK(shiftChar('a', -1) == 'z');
	CHECK(shiftChar('a', -25) == 'b');
	CHECK(shiftChar('a', 26) == 'a');
	CHECK(shiftChar('a', -26) == 'a');
	// Wrap around test
	CHECK(shiftChar('a', 40) == 'o');
	CHECK(shiftChar('a', 41) == 'p');
	CHECK(shiftChar('a', 52) == 'a');
	CHECK(shiftChar('a', 260) == 'a');

	// Another character
	CHECK(shiftChar('f', 1) == 'g');
	CHECK(shiftChar('f', -1) == 'e');
	CHECK(shiftChar('f', 25) == 'e');
	CHECK(shiftChar('f', 26) == 'f');

	// Upper case
	CHECK(shiftChar('A', 1) == 'B');
	CHECK(shiftChar('A', -1) == 'Z');
	CHECK(shiftChar('A', 25) == 'Z');
	CHECK(shiftChar('A', 26) == 'A');
	CHECK(shiftChar('A', 41) == 'P');

	// Not a character
	CHECK(shiftChar(' ', 10) == ' ');
	CHECK(shiftChar(0, 1) == 0);
	CHECK(shiftChar(127, 1) == 127);
}

TEST_CASE("Test encryptCaesar") {
	CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
	CHECK(encryptCaesar("Unchanged", 0) == "Unchanged");
	CHECK(encryptCaesar("Unchanged2", 26) == "Unchanged2");
	CHECK(encryptCaesar("Unchanged3", 52) == "Unchanged3");
	CHECK(encryptCaesar("lowercase", 5) == "qtbjwhfxj");
	CHECK(encryptCaesar("UPPERCASE", 5) == "ZUUJWHFXJ");
	CHECK(encryptCaesar(".234./;';}]", 10) == ".234./;';}]");
	CHECK(encryptCaesar("negativeShift", -5) == "izbvodqzNcdao");
	CHECK(encryptCaesar("limit", 25) == "khlhs");
	CHECK(encryptCaesar("limit2", 1) == "mjnju2");
	CHECK(encryptCaesar("a", 1) == "b");
	CHECK(encryptCaesar("", 10) == "");
	CHECK(encryptCaesar("wraparound", 30) == "avetevsyrh");
	CHECK(encryptCaesar("wraparound2", -30) == "snwlwnkqjz2");
	CHECK(encryptCaesar("Thequickbrownfoxjumpsoverthelazydog", 10) == "Droaesmulbygxpyhtewzcyfobdrovkjinyq");
}

TEST_CASE("Test encryptVigenere") {
	CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
	CHECK(encryptVigenere("Hello, World!", "cake1") == "Jevpo, Yobpd!");
	CHECK(encryptVigenere("Unchanged", "") == "Unchanged");
	CHECK(encryptVigenere("Unchanged2", "a") == "Unchanged2");
	CHECK(encryptVigenere("lowercase", "cake") == "nogitckwg");
	CHECK(encryptVigenere("uppercase", "CAKE") == "wpzitckwg");
	CHECK(encryptVigenere(",./123", "cake") == ",./123");
	CHECK(encryptVigenere("", "cake") == "");
	CHECK(encryptVigenere("caesar", "bbb") == "dbftbs");
	CHECK(encryptVigenere("Thequickbrownfoxjumpsoverthelazydog", "cake") == "Vhouwimodryapfybluwtuofittrinajcfoq");
	CHECK(encryptVigenere("cake", "Thequickbrownfoxjumpsoverthelazydog") == "vhou");
}

TEST_CASE("Test decryptCaesar") {
	CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
	CHECK(decryptCaesar("Unchanged", 0) == "Unchanged");
	CHECK(decryptCaesar("Unchanged2", 26) == "Unchanged2");
	CHECK(decryptCaesar("Unchanged3", 52) == "Unchanged3");
	CHECK(decryptCaesar("qtbjwhfxj", 5) == "lowercase");
	CHECK(decryptCaesar("ZUUJWHFXJ", 5) == "UPPERCASE");
	CHECK(decryptCaesar(".234./;';}]", 10) == ".234./;';}]");
	CHECK(decryptCaesar("izbvodqzNcdao", -5) == "negativeShift");
	CHECK(decryptCaesar("khlhs", 25) == "limit");
	CHECK(decryptCaesar("mjnju2", 1) == "limit2");
	CHECK(decryptCaesar("b", 1) == "a");
	CHECK(decryptCaesar("", 10) == "");
	CHECK(decryptCaesar("avetevsyrh", 30) == "wraparound");
	CHECK(decryptCaesar("snwlwnkqjz2", -30) == "wraparound2");
	CHECK(decryptCaesar("Droaesmulbygxpyhtewzcyfobdrovkjinyq", 10) == "Thequickbrownfoxjumpsoverthelazydog");
}

TEST_CASE("Test decryptVigenere") {
	CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
	CHECK(decryptVigenere("Jevpo, Yobpd!", "cake1") == "Hello, World!");
	CHECK(decryptVigenere("Unchanged", "") == "Unchanged");
	CHECK(decryptVigenere("Unchanged2", "a") == "Unchanged2");
	CHECK(decryptVigenere("nogitckwg", "cake") == "lowercase");
	CHECK(decryptVigenere("wpzitckwg", "CAKE") == "uppercase");
	CHECK(decryptVigenere(",./123", "cake") == ",./123");
	CHECK(decryptVigenere("", "cake") == "");
	CHECK(decryptVigenere("dbftbs", "bbb") == "caesar");
	CHECK(decryptVigenere("Vhouwimodryapfybluwtuofittrinajcfoq", "cake") == "Thequickbrownfoxjumpsoverthelazydog");
	CHECK(decryptVigenere("vhou", "Thequickbrownfoxjumpsoverthelazydog") == "cake");
}

TEST_CASE("Test decodeCaesar") {
	CHECK(decodeCaesar("Unchanged") == "Unchanged");
	CHECK(decodeCaesar("") == "");
	CHECK(decodeCaesar("z") == "e");
	CHECK(decodeCaesar("0") == "0");
	CHECK(decodeCaesar(fileToString("testZCoded.txt")) == fileToString("testZDecoded.txt"));
	CHECK(decodeCaesar(encryptCaesar(fileToString("testZCoded.txt"), 0)) == fileToString("testZDecoded.txt"));
	CHECK(decodeCaesar(encryptCaesar(fileToString("testZCoded.txt"), 25)) == fileToString("testZDecoded.txt"));	
	CHECK(decodeCaesar(fileToString("testZDecoded.txt")) == fileToString("testZDecoded.txt"));
	CHECK(decodeCaesar(fileToString("testClassCoded.txt")) == fileToString("testClassDecoded.txt"));
	CHECK(decodeCaesar(fileToString("testDescCoded.txt")) == fileToString("testDescDecoded.txt"));
}
