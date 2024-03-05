#define _CRT_SECURE_NO_WARNINGS 1

#include "AVLTree.h"

int main()
{
	int arr[] = { 23, 48, 12, 36, 7, 30, 41, 19, 44, 5 };
	AVLTree<int, int> t;

	for (auto e : arr)
	{
		t.Insert(make_pair(e, e));
	}

	return 0;
}