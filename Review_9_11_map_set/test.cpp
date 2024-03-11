#define _CRT_SECURE_NO_WARNINGS 1

#include"Map.h"
#include"Set.h"
#include <string>

void test1()
{
	sc::set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);

	sc::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(3, 3));

	sc::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e <<" ";
	}
	cout << endl;

	sc::map<int, int>::iterator mit = m.begin();
	while (mit != m.end())
	{
		cout << mit->first << ":" << mit->second << endl;
		++mit;
	}
	cout << endl;


	for (auto& kv : m)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

void func(const sc::map<int, int>& m)
{
	//const迭代器：key和value都不能修改
	sc::map<int, int>::const_iterator mit = m.begin();
	while (mit != m.end())
	{
		/*mit->first = 2;
		mit->second = 2;*/
		cout << mit->first << " " << mit->second << endl;
		++mit;
	}
}

void test2()
{
	sc::set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);

	sc::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		/*if(*sit == 1)
			*sit += 1;*/
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	sc::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(3, 3));

	//func(m);
	//map的普通迭代器：value可以修改
	sc::map<int, int>::iterator mit = m.begin();

	while (mit != m.end())
	{
		//mit->first = 2;
		mit->second = 9;
		cout << mit->first << " " << mit->second << endl;
		++mit;
	}
}

void test3()
{
	sc::set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);

	sc::set<int>::iterator sit = s.begin();
	if(sit != s.end())
	{
		/*if(*sit == 1)
			*sit += 1;*/
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	cout << *sit << endl;
	--sit;
	cout << *sit<< endl;

	cout << endl;

}

void test4()
{
	sc::map<string, string> m;
	m["string"];
	m["left"] = "左边";
	m["insert"] = "插入";
	m["string"] = "字符串";

	for (const auto& kv : m)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	sc::set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test4();
	return 0;
}