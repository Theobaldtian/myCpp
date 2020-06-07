#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename elementType>
class CMultiply {	//乘法
public:
	elementType operator()(const elementType& elem1, const elementType& elem2) {
		return elem1 * elem2;
	}
};

int main() {
	
	vector<int> a;
	for (int i = 0; i < 10; ++i)
		a.push_back(i);

	vector<int> b;
	for (int j = 100; j < 110; ++j)
		b.push_back(j);

	vector<int> vecResult;
	vecResult.resize(10);

	//STL算法
	transform(a.begin(), a.end(), b.begin(), vecResult.begin(), CMultiply<int>());
	
	for (size_t nIndex = 0; nIndex < vecResult.size(); ++nIndex)
		cout << vecResult[nIndex] << ' ';
	cout << endl;

	cout << "hello 二元函数对象" << endl;
	return 0;
}
