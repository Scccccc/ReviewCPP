#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template <class T, size_t N>
class A
{
public:
private:
	T _arr[N];
};

template<class T>
class Less
{
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T1, class T2>
class AA
{
public:
	AA()
	{
		cout << "T1, T2" << endl;
	}
};

template<class T1, class T2>
class AA<T1*, T2>
{
public:
	AA()
	{
		cout << "T*, T2" << endl;
	}
};

int main()
{
	AA<int, int> a1;
	AA<int*, double> a2;
	return 0;
}