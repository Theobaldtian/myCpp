#include <iostream>
#include "plain-ptr.h"
#include "value-ptr.h"
#include "smart-ptr.h"

using namespace std;

void test_AHasPtr() {
	//cout << "hello" << endl;

	int i = 42;
	AHasPtr p1(&i, 42);
	AHasPtr p2 = p1;
	cout << p2.get_ptr_val() << endl;

	p1.set_ptr_val(0);
	cout << p2.get_ptr_val() << endl;

	int* ip = new int(42);
	AHasPtr ptr(ip, 0);
	cout << ptr.get_ptr_val() << endl;
	delete ip;
	cout << ptr.get_ptr_val() << endl;
}

void test_CHasPtr() {
	int obj = 0;

	CHasPtr ptr1(obj, 42);
	CHasPtr ptr2(ptr1);
	cout << ptr1.get_ptr_val() << "," << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << "," << ptr2.get_int() << endl;
	
	ptr2.set_ptr_val(6);
	ptr2.set_int(48);
	cout << "修改后的结果" << endl;
	cout << ptr1.get_ptr_val() << "," << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << "," << ptr2.get_int() << endl;
}

void test_BHasPtr() {
	int obj = 0;
	BHasPtr ptr1(&obj, 42);
	BHasPtr ptr2(ptr1);
	cout << ptr1.get_ptr_val() << "," << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << "," << ptr2.get_int() << endl;

	ptr2.set_ptr_val(2);
	ptr2.set_int(22);
	cout << "修改后的结果" << endl;
	cout << ptr1.get_ptr_val() << "," << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << "," << ptr2.get_int() << endl;
}

int main() {
	cout << endl << "常规指针(浅复制)" << endl;
	test_AHasPtr();
	//void test_AHasPtr(); it will error, define a new function, not call

	cout << endl << "值型类(深复制)" << endl;
	test_CHasPtr();

	cout << endl << "智能指针" << endl;
	test_BHasPtr();

	return 0;
}
