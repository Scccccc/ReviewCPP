#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//函数模板
template<typename T>
T Add(const T& x, const T& y)
{
	return  x + y;
}

//类模板
template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
		:_top(0)
		,_capacity(capacity)
	{
		_a = new T[_capacity];
	}
private:
	T* _a;
	int _top;
	int _capacity;
};

//int main()
//{
//	Stack<int> st;
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	double y = 10.1;
//	//有些地方需要加上const，因为类型转换会产生临时变量，具有常属性
//	cout << Add<int>(x, y) << endl;
//	cout << Add<double>(x, y) << endl;
//	return 0;
//}



//int main()
//{
//	string s1 = "hello world";
//	s1 += '!';
//	cout << s1 << endl;
//
//	string s2(s1, 0, 11);
//	cout << s2 << endl;
//
//	string s3(10, '*');
//	cout << s3 << endl;
//	return 0;
//}


class B
{
public:
	B(int a, int& ref)
		:_n(a)
		,_ref(ref)
	{
		
	}
private:
	int& _ref;
	const int _n;
};

//int main()
//{
//	int x = 10;
//	B bb1(10, x);
//	return 0;
//}

//class A
//{
//public:
//	A(int x)
//		:_a(x)
//	{
//		cout << "A(int x)" << endl;
//	}
//	A(const A& a)
//	{
//		cout << "A(const A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1);
//	aa1 = 2;
//	
//	return 0;
//}

//class A
//{
//public:
//	A(int x)
//	{
//		cout << "A(int x)" << endl;
//	}
//	A(const A& a)
//	{
//		cout << "A(const A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	static int _a;
//};
//
//int A::_a = 0;


//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	~A() { --_scount; }
//	//静态成员函数
//	static int GetACount() { return _scount; }
//private:
//	//静态成员变量
//	static int _scount;
//};
//
//int A::_scount = 0;
//
//void TestA()
//{
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
//
//A aa1;
//
//int main()
//{
//	A aa2;
//	TestA();
//	cout << A::GetACount() << endl;
//
//	return 0;
//}

class Time
{
public:
	//友元类
	friend class Date;
private:
	int _hour;
	int _min;
	int _sec;
};

class Date
{
public:
	 Date(int year, int month, int day)
		 : _year(year)
		 , _month(month)
		 , _day(day)
	 {}
	 //友元函数
	 friend ostream& operator<<(ostream& out, const Date d);

	 void SetTimeOfDate(int hour, int min, int sec)
	 {
		 _t._hour = hour;
		 _t._min = min;
		 _t._sec = sec;
	 }
	
private:
	 int _year;
	 int _month;
	 int _day;
	 Time _t;
};
								//d对象不会进行修改可以加上const
ostream& operator<<(ostream& out, const Date d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}


//class A
//{
//public:
//	class B // B天生就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	};
//private:
//	static int k;
//	int h = 2;
//};
//
//int A::k = 1;


class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	void Print()
	{
		cout << "void Print()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int k = 1;
	int h = 2;
};

int main()
{
	const A& ra = A();//const引用延长生命周期
	A();//匿名对象,即用即销毁
	A a;//有名对象

	return 0;
}

//int main()
//{
//	Date d1(2023, 1, 1);
//	cout << d1;
//	return 0;
//}
