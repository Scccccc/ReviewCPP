#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main()
//{
//	int a = 1;
//	int& b = a;
//	int& c = b;
//
//	int x = 10;
//	c = x;
//	return 0;
//}


//引用作参数可以提高效率
//typedef struct A
//{
//	int a[10000];
//}A;
//
//void func1test(A a) {}
//
//void func2test(A& a) {}
//
//int main()
//{
//	A a;
//	int begin1 = clock();
//	for (int i = 0; i < 10000; i++)
//	{
//		func1test(a);
//	}
//	int end1 = clock();
//
//
//	int begin2 = clock();
//	for (int i = 0; i < 10000; i++)
//	{
//		func2test(a);
//	}
//	int end2 = clock();
//
//	cout << "func1test(A)=" << end1 - begin1 << endl;
//	cout << "func2test(A&)=" << end2 - begin2 << endl;
//
//	return 0;
//}

//
////引用的错误使用
//int& func(int x)
//{
//	int n = x;
//	n++;
//	return n;
//}
//
//int main()
//{
//	//ret是n的别名，但是n出了作用域就没有使用权了，n是局部变量，引用作为返回，ret就指向n，只是栈帧没有销毁，看起来没有问题
//	int& ret = func(10);
//	cout << ret << endl;
//
//	func(20);//再次调用函数，n变成了21。那么ret也就被修改了，说明了引用是真真正正存在的，
//	cout << ret << endl;
//	return 0;
//}

//范围for
int main()
{
	int arr[5] = { 1,2,3,4,5 };

	for (auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}