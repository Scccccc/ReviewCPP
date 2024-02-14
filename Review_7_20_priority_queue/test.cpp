#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include"priority_queue.h"

void test_priority_queue()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	sc::priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());

	pq.push(10);
	pq.push(100);
	cout << pq.size() << endl;


	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	cout << pq.size() << endl;
}

int main()
{
	test_priority_queue();
	return 0;
}