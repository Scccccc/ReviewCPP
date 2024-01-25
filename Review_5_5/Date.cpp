#define _CRT_SECURE_NO_WARNINGS 1


#include "Date.h"

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<=(const Date& d) const
{
	return *this < d && *this == d;
}

bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

int Date::GetMonthDay(int year, int month)
{
	int Dayarr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		return 29;
	}
	else
	{
		return Dayarr[month];
	}
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day) const
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator++()
{
	return *this += 1;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
		
	}
	return *this;
}

Date Date::operator-(int day) const
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (max != min)
	{
		++min;
		++n;
	}

	return n * flag;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	int year, month, day;
	in >> year >> month >> day;

	if ((month > 0 && month < 13) && (day > 0 && day < d.GetMonthDay(year, day)))
	{
		d._year = year;
		d._month = month;
		d._day = day;
	}
	else
	{
		cout << "非法操作" << endl;
	}
	return in;

}
