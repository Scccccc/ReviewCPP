#pragma once

#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	/*Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}*/
	Date(int year, int month, int day)
	{
		if ((month > 0 && month < 13) && (day > 0 && day < GetMonthDay(year, day)))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法操作" << endl;
		}
	
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

	bool operator<(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator!=(const Date& d) const;

	int GetMonthDay(int year, int month);

	Date& operator+=(int day);
	Date operator+(int day) const;

	Date& operator-=(int day);
	Date operator-(int day) const;

	int operator-(const Date& d) const;

	Date& operator++();
	Date operator++(int);


private:
	int _year;
	int _month;
	int _day;
};


ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);


