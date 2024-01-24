#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"


//int main()
//{
//	Date d1(2023, 1, 23);
//	Date d2(d1);
//	Date d3;
//
//	d1 = d2 = d3;
//
//	return 0;
//}

void Test1()
{
	Date d1(2023, 1, 1);
	Date d2(2023, 2, 2);

	cout << (d1 < d2) << endl;

}

void Test2()
{
	Date d1(2023, 1, 1);
	d1 += 100;
	d1.Print();

	Date d2(2024, 1, 1);
	d2 = d2 + 100;
	d2.Print();

	++d2;
	d2.Print();
}

int main()
{
	//Test1();
	Test2();
	return 0;
}