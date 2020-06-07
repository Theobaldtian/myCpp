#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//class absInt {
//public:
//	int operator()(int val) {
//
//	}
//};

struct absInt {
	//重载操作符：函数调用操作符
	int operator()(int val) {
		return val < 0 ? -val : val;
	}
};

//作为对比，写一个普通的模板函数
template<typename elementType>
void FuncDisplayElement(const elementType& element) {
	cout << element << ' ';
}

template<typename elementType>
struct DisplayElement {
	//存储状态
	int m_nCount;
	DisplayElement() {
		m_nCount = 0;
	}
	void operator() (const elementType & element)// const 
	{
		++m_nCount;
		cout << element << ' ';
	}
};

int main() {

	int i = -42;
	absInt absObj;
	unsigned int ui = absObj(i);
	cout << ui << endl;

	vector<int> a;
	for (int n = 0; n < 10; ++n)
		a.push_back(n);

	list<char> b;
	for (char c = 'a'; c < 'k'; ++c)
		b.push_back(c);

	//STL算法
	//for_each(a.begin(), a.end(), DisplayElement<int>());
	DisplayElement<int> mResult;
	mResult = for_each(a.begin(), a.end(), mResult);
	cout << endl;
	cout << "数量：" << mResult.m_nCount << endl;

	cout << endl;

	for_each(b.begin(), b.end(), DisplayElement<char>());
	cout << endl;

	cout << "hello 函数对象" << endl;

	return 0;
}
