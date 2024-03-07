#define _CRT_SECURE_NO_WARNINGS 1

#include"RBTree.h"

int main()
{
	int arr[] = { 87, 23, 65, 42, 9, 31, 56, 74, 18};
	RBTree<int, int> rbt;

	for (auto& e : arr)
	{
		if (e == 18)
			int i = 0;
		rbt.Insert(make_pair(e, e));
		cout << e << " ";
	}
	cout << endl;

	cout << rbt.Isbalance() << endl;
	return 0;
}