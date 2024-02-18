#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//	string _name = "sc";
//	short _age = 18;
//};
//
//class Student :public Person
//{
//public:
//	//与父类同名函数构成隐藏/重定义
//	/*void Print(int i = 10)
//	{
//		cout << i << endl;
//	}*/
////protected:
//	int _id;
//};
//
//
//int main()
//{
//	Person p;
//	p.Print();
//
//	Student s;
//	s._name = "zhang";
//	s._age = 16;
//	s._id = 16689;
//	s.Print();
//	//s.Print(1);
//
//	return 0;
//}

//class A
//{
//public:
//	int _a = 1;
//};
//
//class B : public A
//{
//public:
//	int _b = 1;
//};
//
//
//int main()
//{
//	int i = 0;
//	//类型转换会产生临时变量，临时变量具有常属性
//	const double& d = i;
//
//	B b;
//	A a;
//	b._a = 10;
//	//切割/切片
//	a = b;
//	//虽然是不同的类型，但是切割不会产生临时变量
//	A& aa = a;
//	cout << a._a << endl;
//	cout << b._a << endl;
//	cout << aa._a << endl;
//	return 0;
//}


//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//	string _name = "sc";
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _name << " " << _age << endl;
//	}
//	int _age = 18;
//};
//
//int main()
//{
//	Student s;
//	//父类和子类中有同名函数，子类会去隐藏父类的同名函数
//	//如果想访问，需要通过访问限定符
//	s.Print();
//	s.Person::Print();
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name)
//	{
//		_name = new char;
//		cout << "Person()" << endl;
//	}
//	void Print()
//	{
//		cout << _name << endl;
//	}
//	~Person()
//	{
//		delete _name;
//		cout << "~Person()" << endl;
//	}
//	//string _name;
//	char* _name;
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name = "张三", int age = 18)
//		//父类如果没有提供默认构造缺省值，那么子类需要手动初始化（有点像匿名对象）
//		:Person(name)
//		,_age(age)
//	{
//		//cout << "Student()" << endl;
//	}
//
//	~Student()
//	{
//		//子类会先调用自己的析构，然后再去调用父类的析构，先子后父
//		//因为子类可能会用到父类的成员，如果父类先析构，那么子类再去访问父类成员就会报错
//		cout << "~Student()" << endl;
//		/*Person::~Person();
//		Person::Print();*/
//	}
//
//	int _age;
//};
//
//int main()
//{
//	Student s;
//	Person p("sc");
//	//cout << s._name << endl;
//	//cout << p._name << endl;
//
//	
//	return 0;
//}

//菱形虚拟继承
class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

class C : virtual public A
{
public:
	int _c;
};

class D : public B , public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 10;
	d.C::_a = 20;
	return 0;
}