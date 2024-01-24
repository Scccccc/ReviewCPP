#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		cout << "Date(const Date & d)" << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符重载
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator!=(const Date& d);

	int GetMonthDay(int year, int month);

	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator++();
	Date operator++(int);


private:
	int _year;
	int _month;
	int _day;
};
