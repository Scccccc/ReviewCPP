#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Stack
{
public:
	Stack(int capacity = 4)
		:_top(0)
		, _capacity(0)
	{
		cout << "Stack(int capacity = 4)" << endl;

		_array = (int*)malloc(sizeof(int) * capacity);
		if (_array == nullptr)
		{
			perror("malloc fail");
			return;
		}
	}
	~Stack()
	{
		cout << "~Stack()" << endl;

		free(_array);
		_array = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _array;
	int _top;
	int _capacity;
};

//int main()
//{
//	Stack* p1 = new Stack;
//	delete p1;
//	return 0;
//}

//int main()
//{
//	Stack* p = (Stack*)malloc(sizeof(Stack) * 10);
//	//定位new-显示调用构造函数
//	new(p)Stack;
//
//	p->~Stack();
//	free(p);
//	return 0;
//}
//

//函数模板
template<typename T>
void Swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}


int main()
{
	int a = 0;
	int b = 1;
	Swap(a, b);
	return 0;
}