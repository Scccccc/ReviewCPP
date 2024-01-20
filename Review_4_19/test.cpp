#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

////宏函数：不需要建立栈帧，提高效率
////缺点：不能调试，可读性变差
//#define Add(x, y) ((x)+(y))
//
//int main()
//{
//	cout << Add(10, 20) << endl;
//
//	return 0;
//}

//inline int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	cout << Add(10, 20) << endl;
//	return 0;
//}

typedef int Datatype;
class Stack
{
public:
	void Init(int defaultcapacity = 4)
	{
		_val = (Datatype*)malloc(sizeof(Datatype) * defaultcapacity);
		if (nullptr == _val)
		{
			perror("malloc fail");
			return;
		}
		_top = 0;
		_capacity = defaultcapacity;
	}

	void push(Datatype x)
	{
		if (_top == _capacity)
		{
			Datatype* tmp = (Datatype*)realloc(_val, sizeof(Datatype) * 2);
			if (tmp == nullptr)
			{
				perror("realloc fail");
				return;
			}
			_val = tmp;
			_capacity *= 2;
		}
		_val[_top++] = x;
	}

	void Destroy()
	{
		free(_val);
		_val = nullptr;
		_top = 0;
		_capacity = 0;
	}
private:
	Datatype* _val;
	int _top;
	int _capacity;
};

int main()
{
	Stack st1;
	st1.Init();
	st1.push(1);
	st1.push(1);
	st1.push(1);
	st1.Destroy();
	return 0;
}