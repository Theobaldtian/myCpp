#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class CCompareStringNoCase {
public:
	bool operator()(const string& str1, const string& str2) const {	//最后一个const很重要
		string str1LowerCase;
		str1LowerCase.resize(str1.size());
		transform(str1.begin(), str1.end(), str1LowerCase.begin(), tolower);

		string str2LowerCase;
		str2LowerCase.resize(str2.size());
		transform(str2.begin(), str2.end(), str2LowerCase.begin(), tolower);

		return (str1LowerCase < str2LowerCase);
	}
};

int main() {

	set<string, CCompareStringNoCase> names;
	names.insert("Tina");
	names.insert("jim");
	names.insert("Jack");
	names.insert("Sam");
	names.insert("hello");
	
	set<string, CCompareStringNoCase>::iterator iNameFound = names.find("SAM");
	if (iNameFound != names.end())
		cout << "找到了" << *iNameFound << endl;
	else
		cout << "没找到" << endl;

	cout << "hello 二元谓词" << endl;
	return 0;
}
