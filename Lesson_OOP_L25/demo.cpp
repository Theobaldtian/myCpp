#include <iostream>
#include <string>

using namespace std;

class Item_base {		//基类
public:
	Item_base(const std::string& book = "", double sales_price = 0.0) :
		isbn(book), price(sales_price) {}

	virtual double net_price(size_t n) const {
		return n * price;
	}

	std::string book() const {
		return isbn;
	}
public:
	int x;
private:
	string isbn;
protected:	//受保护的
	double price;
};

class Bulk_item : public Item_base {		//派生类
public:
	Bulk_item(const std::string& book = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0) :
		Item_base(book, sales_price), min_qty(qty), discount(disc_rate) {}

	double net_price(size_t cnt) const {
		if (cnt > min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}

public:
	void test() {
		cout << x << endl;
		//cout << isbn << endl;
		cout << price << endl;
	}
	void test2(const Bulk_item& d, const Item_base& b) {
		cout << d.x << endl;
		cout << d.price << endl;
		//cout << d.isbn << endl;
		cout << b.x << endl;
		//cout << b.price << endl;
	}
private:
	size_t min_qty;
	double discount;
};

int main() {

	Item_base item("0-12-345-6789", 9.9);
	cout << item.book() << ',' << item.net_price(10) << endl;
	////cout << item.x << endl;
	//cout << item.isbn << endl;
	//cout << item.price << endl;

	Bulk_item item2("0-12-789-3456", 9.9, 10, 0.12);
	cout << item2.book() << ',' << item2.net_price(19) << endl;
	////cout << item2.x << endl;		//继承
	//cout << item2.isbn << endl;
	//cout << item2.price << endl;
	//cout << item2.min_qty << endl;
	//cout << item2.discount << endl;
	
	//item2.test();
	//item2.test2(item2, item);

	//cout << "hello world!" << endl;
	return 0;
}
