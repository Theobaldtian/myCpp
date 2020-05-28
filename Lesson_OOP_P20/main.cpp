#include <iostream>

using namespace std;

class String {
public:
	String(char const *chars = "");

	char &operator[](std::size_t index) throw(String);		//可变成员函数
	char operator[](std::size_t index) const throw(String);		//常量成员函数

	void print();
private:
	char* ptrChars;
	static String errorMessage;
};

String String::errorMessage("Subscript out of range");

String::String(char const *chars) {
	chars = chars ? chars : "";
	ptrChars = new char[std::strlen(chars) + 1];
	strcpy_s(ptrChars, std::strlen(chars) + 1, chars);
}

char &String::operator[](std::size_t index) throw(String){
	cout << "no const" << endl;		//用于检测是否调用
	if (index >= std::strlen(ptrChars))
		throw errorMessage;
	return ptrChars[index];
}

char String::operator[](std::size_t index) const throw(String) {
	cout << "const" << endl;		//用于检测是否调用
	if (index >= std::strlen(ptrChars))
		throw errorMessage;
	return ptrChars[index];
}

void String::print() {
	cout << ptrChars << endl;
}

int main() {

	string a("Alice");
	cout << a[2] << endl;
	
	String s("Hello");
	cout << s[0] << endl;

	s[0] = 'A';		//	若下标操作符没有 & 符号，则此处赋值不成立，请注意

	s.print();

	String const s2("Dog");
	cout << s2[2] << endl;
	//s2.print();	//会报错，因为常量成员函数不支持左值赋值


	//cout << "hello" << endl;
	return 0;
}
