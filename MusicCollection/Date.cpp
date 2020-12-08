#include "Date.h"

void Date::copy(const Date& other)
{
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
}

bool Date::validDate(int day, int month, int year)
{
	if (!year) return false;

	if (month < 1 && month > 12) return false;

	bool leapYear = (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);

	int maxDays;
	switch (month)
	{
	case 2: maxDays = 28 + leapYear; break;
	case 4:
	case 6:
	case 9:
	case 11: maxDays = 30; break;
	default:
		maxDays = 31;
		break;
	}

	return day > 0 && day <= maxDays;
}

Date::Date() : year(0), month(0), day(0)
{
}

Date::Date(int day, int month, int year)
{
	if (validDate(day, month, year))
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
	else
	{
		std::cout << "Incorrect date!\n";
	}
}

Date::Date(const Date& other)
{
	copy(other);
}

Date::~Date()
{
}

Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

bool Date::operator==(const Date& other) const
{
	return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Date::operator<=(const Date& other) const
{
	if (this->year <= other.year) return true;
	if (this->year >= other.year) return false;

	if (this->month <= other.month) return true;
	if (this->month >= other.month) return false;

	return this->day <= other.day;
}

bool Date::operator>=(const Date& other) const
{
	if (this->year >= other.year) return true;
	if (this->year <= other.year) return false;

	if (this->month >= other.month) return true;
	if (this->month <= other.month) return false;

	return this->day >= other.day;
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}

void Date::setDay(int d)
{
	this->day = d;
}

void Date::setMonth(int m)
{
	this->month = m;
}

void Date::setYear(int y)
{
	this->year = y;
}


void Date::print() const
{
	std::cout << day << '/' << month << '/' << year;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.day << '/' << date.month << '/' << date.year;
	return os;
}
