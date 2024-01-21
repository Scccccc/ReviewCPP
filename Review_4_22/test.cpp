#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;



class Date
{
public:
	//构造
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
	void Print()
	{
		//this指针，this不能在实参和形参显示传递，但是可以在函数内部显示使用
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}
	//析构
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Print();
	Date d2(2024, 1, 1);
	d2.Print();
	return 0;
}