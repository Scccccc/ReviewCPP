#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

struct ListNode
{
	int _val;
	struct ListNode* _next;

	ListNode(int x)
		:_val(x)
		,_next(nullptr)
	{}

};

struct ListNode* BuyListNode(int x)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->_next = NULL;
	node->_val = x;
	return node;
}

int main()
{
	struct ListNode* n1 = BuyListNode(1);
	ListNode* n2 = new ListNode(2);

	int* p1 = new int;
	delete p1;

	int* p2 = new int(1);
	delete p2;

	int* p3 = new int[10];
	delete[] p3;

	int* p4 = new int[10]{ 1,2,3 };
	delete[] p4;
	return 0;
}