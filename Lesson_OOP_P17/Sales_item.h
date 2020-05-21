#pragma once

#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include <iostream>
#include <string>

class Sales_item {
	friend bool operator==(const Sales_item&, const Sales_item&);
public:
	Sales_item(std::string book, unsigned units, double amount) :
		isbn(book), units_sold(units), revenue(amount) {}
	Sales_item() :units_sold(0), revenue(0.0) {}

	friend std::ostream& operator<<(std::ostream&, const Sales_item&);
public:
	double avg_price() const;
	bool same_isbn(const Sales_item& rhs) const {
		return isbn == rhs.isbn;
	}
	
private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

double Sales_item::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

inline bool operator==(const Sales_item& lhs, const Sales_item& rhs) {
	return lhs.isbn == rhs.isbn &&
		lhs.units_sold == rhs.units_sold &&
		lhs.same_isbn(rhs);
}

inline bool operator!= (const Sales_item & lhs, const Sales_item & rhs){
	return !(lhs == rhs);
}

inline std::ostream& operator<<(std::ostream& out, const Sales_item& s) {
	out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue << "\t" << s.avg_price();
	return out;
}




#endif
