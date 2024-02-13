#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<time.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

#include "queue.h"
#include "stack.h"

void test_op()
{
	srand(time(0));
	size_t N = 100000;
	vector<int> v;
	vector<int> copy;
	v.reserve(N);
	copy.reserve(N);
	deque<int> dq;
	for (size_t i = 0; i < N; ++i)
	{
		auto e = rand();
		v.push_back(e);
		dq.push_back(e);
	}

	clock_t start1 = clock();
	////拷贝到vector
	//for (auto& e : dq)
	//{
	//	copy.push_back(e);
	//}
	////排序
	//sort(copy.begin(), copy.end());
	////拷贝回去
	//size_t i = 0;
	//for (auto& e : dq)
	//{
	//	e = copy[i++];
	//}
	sort(dq.begin(), dq.end());

	clock_t end1 = clock();

	clock_t start2 = clock();
	sort(v.begin(), v.end());
	clock_t end2 = clock();

	printf("deque copy sort:%d\n", end1 - start1);
	printf("vector sort:%d\n", end2 - start2);

}

void test_stack()
{
	sc::stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);

	st.pop();
	cout << st.empty() << endl;

	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.empty() << endl;
}

void test_queue()
{
	sc::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	q.pop();

	cout << q.front() << endl;
	cout << q.back() << endl;
}

int main()
{
	//test_op();
	//test_stack();
	test_queue();


	return 0;
}