#include <iostream>

using namespace std;

class String {
public:
	String(char const* chars = "");
	String(String& str);
	~String();

	String& operator++();			//前加加
	String const operator++(int);	//后加加

	void display();

private:
	char* ptrChars;
};

void String::display() {
	cout << ptrChars << endl;
}

String::String(char const* chars) {
	chars = chars ? chars : "";
	ptrChars = new char[std::strlen(chars) + 1];
	strcpy_s(ptrChars, std::strlen(chars) + 1, chars);
}

String::String(String& str) {
	ptrChars = new char[std::strlen(str.ptrChars) + 1];
	strcpy_s(ptrChars, std::strlen(str.ptrChars) + 1, str.ptrChars);
}

String::~String() {
	delete[] ptrChars;
}

String& String::operator++() {
	for (std::size_t i = 0; i < std::strlen(ptrChars); ++i) {
		++ptrChars[i];
	}
	return *this;
}

String const String::operator++(int) {
	String copy(*this);
	++(*this);
	return copy;
}


int main() {

	String s("ABC");
	s.display();

	++s;
	s.display();

	s++;
	s.display();

	cout << "=====================" << endl;

	String str1("ABC");
	str1.display();

	String str2(++str1);
	str2.display();

	String str3(str1++);		//此处有问题
	str3.display();
	str1.display();




	//cout << "hello" << endl;
	return 0;
}
