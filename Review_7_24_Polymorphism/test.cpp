#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicks()
//	{
//		cout << "全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	void BuyTicks() override
//	{
//		cout << "半价" << endl;
//	}
//};
//
////必须是引用或者指针
//void Func(Person& p)
//{
//	p.BuyTicks();
//}
//
//int main()
//{
//	Person William;
//	William.BuyTicks();
//	Student sc;
//	sc.BuyTicks();
//
//	Func(sc);
//
//	return 0;
//}


class Person
{
public:
	virtual void Buytickts()
	{
		cout << "全价" << endl;
	}
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Func2()" << endl;
	}
};

class Student : public Person
{
	virtual void Buytickts()
	{
		cout << "半价" << endl;
	}
	virtual void Func3()
	{
		cout << "Func3()" << endl;
	}
};
//函数指针
typedef void (*FUNC_PTR)();
//依次打印虚表里虚函数地址
void PrintVFT(FUNC_PTR* table)
{
	//vs环境下，虚表的最后一个一个值是全0（空指针），所以这里判断条件可以这样写
	for (int i = 0; table[i] != nullptr; i++)
	{
		printf("table[%d]->%p\n", i, table[i]);
		FUNC_PTR f = table[i];
		f();
	}
	printf("\n");
}

int main()
{
	Person ps;
	Student st;
	//int*一次取4个字节，再解引用
	int vft1 = *((int*)&ps);
	PrintVFT((FUNC_PTR*)vft1);

	int vft2 = *((int*)&st);
	PrintVFT((FUNC_PTR*)vft2);

	return 0;
}