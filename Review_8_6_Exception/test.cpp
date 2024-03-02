#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

int testing(int i, int j)
{
	if (j == 0)
	{
		throw "exit progeam";
	}
	else
	{
		return i * j;
	}
}

void func()
{
	try
	{
		int i = 0;
		int j = 0;
		//scanf("%d %d", &i, &j);
		cin >> i >> j;
		cout << testing(i, j) << endl;
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
}

int main()
{
	try
	{
		func();
	}
	catch(const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unknow errmsg!"<<endl;
	}
	return 0;
}