#include <iostream>
#include <cstring>
#include "string.h"

String::String(char const *chars) {
	chars = chars ? chars : "";
	ptrChars = new char[std::strlen(chars) + 1];
	strcpy_s(ptrChars, std::strlen(chars) + 1, chars);
}

String::String(String const& str) {
	ptrChars = new char[std::strlen(str.ptrChars) + 1];
	strcpy_s(ptrChars, std::strlen(str.ptrChars) + 1, str.ptrChars);
}

String::~String() {
	delete[] ptrChars;
}

void String::display() const {
	std::cout << ptrChars << std::endl;

}
