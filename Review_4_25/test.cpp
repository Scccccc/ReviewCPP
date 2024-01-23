#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Stack
{
public:
	Stack()
	{
		_a = (int*)malloc(sizeof(int) * 4);
		if (_a == nullptr)
		{
			perror("malloc fail");
			return;
		}
		_top = 0;
		_capacity = 4;
	}
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _a = nullptr;
	int _top = 0;
	int _capacity = 0;
};

class Queue
{
private:
	Stack _pushstack;
	Stack _popstack;
};


class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2023, 1, 1);
	Date d2(d1);
	return 0;
}