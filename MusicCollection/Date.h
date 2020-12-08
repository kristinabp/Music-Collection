#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
	int day;
	int month;
	int year;

	void copy(const Date& other);
	bool validDate(int day, int month, int year);

public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& other);
	~Date();

	Date& operator=(const Date& other);
	bool operator==(const Date& other)const;
	bool operator<=(const Date& other) const;
	bool operator>=(const Date& other)const;

	friend std::ostream& operator<<(std::ostream& os, const Date& date);

	int getDay()const;
	int getMonth()const;
	int getYear()const;

	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	void print()const;
};

#endif // !DATE_H
