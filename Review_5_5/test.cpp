#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

void test1()
{
	Date d1(2024, 1, 25);
	d1 -= 100;
	d1.Print();
}

void test2()
{
	Date d1(2024, 1, 25);
	Date d2(1949, 10, 1);
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;

	Date d3 = d1 - 100;
}

void test3()
{
	Date d1(2024, 1, 1);
	Date d2(2023, 2, 1);
	//cout << d1 << endl;
	//cout << d1 << d2 << endl;
	cin >> d1 >> d2;
	cout << d1 << d2 << endl;
}

int main()
{
	test1();
	test2();
	test3();
	return 0;
}