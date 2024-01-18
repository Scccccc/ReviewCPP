#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
using namespace std;

////缺省参数
//void func(int a = 0)
//{
//	std::cout << a << std::endl;
//}
//
//int main()
//{
//	func();
//	func(10);
//	return 0;
//}

//typedef int STDatatype;
//struct stack
//{
//	STDatatype* data;
//	int top;
//	int capacity;
//};
//
//void StackInit(struct stack* ps, int defaultecapacity = 4)
//{
//	ps->data = (STDatatype*)malloc(sizeof(STDatatype) * defaultecapacity);
//	if (ps->data == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	ps->top = 0;
//	ps->capacity = defaultecapacity;
//}
//
//int main()
//{
//	struct stack st;
//	StackInit(&st);
//	return 0;
//}

//指针
//void swap(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//int main()
//{
//	int x = 1;
//	int y = 2;
//	swap(&x, &y);
//	cout << x << " " << y << endl;
//	return 0;
//}

//引用
//void swap(int& pa, int& pb)
//{
//	int tmp = pa;
//	pa = pb;
//	pb = tmp;
//}
//
//void swap(int*& pa, int*& pb)
//{
//	int* tmp = pa;
//	pa = pb;
//	pb = tmp;
//}
//
//int main()
//{
//	int x = 1;
//	int y = 2;
//	swap(x, y);
//	cout << x << " " << y << endl;
//
//	int* px = &x;
//	int* py = &y;
//	cout << px << " " << py << endl;
//	swap(px, py);
//	cout << px << " " << py << endl;
//
//	return 0;
//}

//引用
typedef struct LTNode
{
	int data;
	struct LTNode* next;
}LTNode;

LTNode* Buylistnode(int x)
{
	LTNode* ret = (LTNode*)malloc(sizeof(LTNode));
	if (ret == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	ret->data = x;
	ret->next = NULL;
	return ret;
}

void Listpushback(LTNode*& phead, int x)
{
	//assert(phead);
	LTNode* newnode = Buylistnode(x);
	if (phead == NULL)
	{
		phead = newnode;
	}
	else//找尾
	{
		LTNode* tail = phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

int main()
{
	LTNode* plist = NULL;
	Listpushback(plist, 1);

	return 0;
}