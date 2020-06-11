#include <iostream>
#include <string>
#include "Sales_item.h"

using namespace std;

class Dog {
public:
	Dog(string n, int a, double w) :name(n), age(a), weight(w) {}
	operator int() const {
		return age;
	}
	operator double() const {
		return weight;
	}
private:
	int age;
	double weight;
	string name;
};

int main() {

	int a, b;
	a = 10;
	b = a;

	Dog d("Bill", 4, 12.5);
	b = d;
	cout << b << endl;

	Sales_item item("6-123-2345-X", 10, 120.0);
	double m;
	m = item;
	cout << m << endl;

	std::string str = item;
	cout << str << endl;

	cout << item << endl;

	//cout << "hello" << endl;
	return 0;
}

/*
转换函数：
operator int() const;

注意：
1、必须是成员函数
2、不能指定返回类型 operator前没有数据类型
3、形参表必须是空的 int()括号中没有参数
4、必须显示的返回一个指定类型的值 必须ruturn，且类型需要相匹配
5、不应该改变被转换对象，通常定义为const
*/
