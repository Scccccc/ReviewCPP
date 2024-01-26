#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


class A
{
public:
	A(){}
private:
	int _a;
};
class sc
{
public:
	sc(int a, int& ref)
		:_a(a)
		,_ref(ref)
	{}
private:
	const int _a;
	int& _ref;
	A _aa;
};

class Love
{
public:
	Love(int x)
		:_a(x)
	{}
private:
	int _a;
};

class Sum
{
public:
	Sum()
	{
		_ret += _i;
		++_i;
	}
	//静态成员函数
	static int Getret()
	{
		return _ret;
	}
private:
	//静态成员变量
	static int _i;
	static int _ret;
};

int Sum::_i = 1;
int Sum::_ret = 0;


int main()
{
	int n = 1;
	sc s1(10, n);
	Love l1(1);
	Love l2 = 2;//隐式类型转换，整形整形转换成自定义类型
	//整型提升或者截断会产生临时变量，临时变量具有常性，需要const修饰
	int i = 0;
	const double& b = i;
	int i = 0;
	double a = 1.1;
	const int& ii = a;
	return 0;
}
