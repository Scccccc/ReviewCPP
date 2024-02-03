#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

void test1()
{
	sc::string s1;
	cout << s1.c_str() << endl;

	sc::string s2("hello world");
	cout << s2.c_str() << endl;

	//sc::string::iterator it = s2.begin();
	//while (it != s2.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	cout << endl;

	for (auto& e : s2)
	{
		cout << e;
	}
	cout << endl;

}

void test2()
{
	sc::string s1("hello world");
	cout << s1.c_str() << endl;
	s1.push_back('x');
	cout << s1.c_str() << endl;

	s1.append("yyyyyyyyyyyyyyyyyyyyyyyyyyyyy");
	cout << s1.c_str() << endl;

}

void test3()
{
	sc::string s1("helloworld");
	cout << s1.c_str() << endl;

	//s1.insert(11, 3, '#');
	//cout << s1.c_str() << endl;

	//s1.insert(14, "!!!!");
	//cout << s1.c_str() << endl;

	s1.erase(3, 3);
	cout << s1.c_str() << endl;

}
void test4()
{
	sc::string s1("hello world");
	cout << s1.c_str() << endl;

	cout << s1.find("worxx") << endl;
}

void test5()
{
	sc::string s1("hello world");
	cout << s1.c_str() << endl;

	cout<<s1.substr(6).c_str()<<endl;
}
void test6()
{
	sc::string s1("hello world");
	cout << s1.c_str() << endl;

	sc::string s2(s1);
	cout << s2.c_str() << endl;

	s1.resize(8);
	cout << s1.c_str() << endl;
	s1.resize(13, '#');
	cout << s1.c_str() << endl;
	s1.resize(100, '\0');
	cout << s1 << endl;

}

void test7()
{
	sc::string s1;
	cin >> s1;
	cout << s1 << endl;
	cin >> s1;
	cout << s1 << endl;

}

void test8()
{
	sc::string s1("hello");
	sc::string s2("helloxxx");

	sc::string s3("helloxxx");
	sc::string s4("hello");

	sc::string s5("hello");
	sc::string s6("hello");

	cout << (s1 < s2) << endl;
	cout << (s3 == s4) << endl;
	cout << (s5 <= s6) << endl;

}

void test9()
{
	sc::string s1("hello");
	sc::string s2("helloxxx");

	s1 = s2;
	cout << s1 << endl;
	cout << s2 << endl;

}

int main()
{
	test9();
	return 0;
}