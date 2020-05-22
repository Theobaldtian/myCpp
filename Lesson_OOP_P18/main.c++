#include <iostream>
#include "Sales_item.h"

using namespace std;

class Date {
public:
	Date(int y = 0, int m = 0, int d = 0) :year(y), month(m), day(d) {}

	int operator==(const Date&) const;
	int operator!=(const Date&) const;
	int operator<(const Date&) const;
	int operator>=(const Date&) const;
	//int operator>(const Date&) const;
	//int operator<=(const Date&) const;

private:
	int year, month, day;
};

int Date::operator==(const Date& dt) const {
	return this->year == dt.year &&
		month == dt.month &&
		day == dt.day;
}
int Date::operator!=(const Date& dt) const {
	return !(*this == dt);
}
int Date::operator<(const Date& dt) const {
	if (this->year == dt.year) {
		if (this->month == dt.month)
			return this->day < dt.day;
	return this->month < dt.month;
	}
	else {
		return this->year < dt.year;
	}	
}
int Date::operator>=(const Date& dt) const {
	return !(*this < dt);
}

int main() {
	
	Date d1(2019, 5, 20);
	Date d2(2020, 5, 20);
	Date d3(2020, 5, 20);

	if (d1 < d2)
		cout << "d1 小于 d2" << endl;
	if (d2 == d3)
		cout << "d2 等于 d3" << endl;
	if (d1 != d2)
		cout << "d1 不等于 d2" << endl;

	system("pause");
	return 0;
}
