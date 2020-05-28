#include <iostream>
#include <string>

using namespace std;

class String {
public:
	String(char const* chars = "");
	String& operator=(String const&);
	String& operator=(char const*);
	String& operator=(char);

	void print();

private:
	char* ptrChars;

};

String& String::operator=(String const& str) {
	if (strlen(ptrChars) != strlen(str.ptrChars)) {
		char* ptrHold = new char[strlen(str.ptrChars) + 1];
		delete ptrChars;
		ptrChars = ptrHold;
	}
	strcpy_s(ptrChars, strlen(str.ptrChars) + 1, str.ptrChars);
	return *this;
}

String& String::operator=(char const* str) {
	delete ptrChars;
	strcpy_s(ptrChars, strlen(str) + 1, str);
	return *this;
}

String& String::operator=(char str) {
	
	return *this;
}

String::String(char const* chars) {
	chars = chars ? chars : "";
	ptrChars = new char[std::strlen(chars) + 1];
	strcpy_s(ptrChars,std::strlen(chars)+1, chars);
}

void String::print() {
	cout << ptrChars << endl;
}

int main() {

	String s("hello");
	String s2("Dog");
	s.print();
	s = s2;
	s.print();

	s = "Cat";
	s.print();

	s = 'A';		//未定义赋值重载运算符
	s.print();


	//cout << "hello" << endl;
	//system("pause");
	return 0;
}
