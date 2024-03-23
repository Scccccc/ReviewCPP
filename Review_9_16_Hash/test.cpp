#define _CRT_SECURE_NO_WARNINGS 1

#include "HashTable.h"
#include "unordered_map.h"
#include "unordered_set.h"

//
//void test1()
//{
//	hash_bucket::HashTable<int, int> ht;
//	ht.insert(make_pair(1, 1));
//	ht.insert(make_pair(2, 2));
//	ht.insert(make_pair(3, 3));
//	ht.insert(make_pair(4, 4));
//	ht.insert(make_pair(5, 1));
//	ht.insert(make_pair(6, 2));
//	ht.insert(make_pair(7, 3));
//	ht.insert(make_pair(8, 4));
//	ht.insert(make_pair(9, 1));
//	ht.insert(make_pair(10, 2));
//	ht.insert(make_pair(11, 3));
//	ht.insert(make_pair(18, 18));
//
//	ht.print();
//
//	ht.insert(make_pair(11, 11));
//	ht.print();
//	hash_bucket::HashTable<string, string> dict;
//
//	dict.insert(make_pair("insert", "插入"));
//	dict.insert(make_pair("left", "左"));
//	dict.insert(make_pair("operator", "大狙"));
//	dict.print();
//
//
//}
//
//void test2()
//{
//	hash_bucket::HashTable<int, int> ht;
//	ht.insert(make_pair(1, 1));
//	ht.insert(make_pair(2, 2));
//	ht.insert(make_pair(3, 3));
//	ht.insert(make_pair(4, 4));
//	hash_bucket::HashTable<int, int>::iterator it = ht.begin();
//	while (it != ht.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	//open_address::HashTable<int, int> ht;
//	//ht.Insert(make_pair(1, 1));
//	//auto ret = ht.Find(1);
//	////ret->_kv.first = 2;
//	//ret->_kv.second = 2;
//	//ht.Erase(1);
//
//	//open_address::HashTable<string, string> dict;
//	//dict.Insert(make_pair("insert", "插入"));
//	//dict.Insert(make_pair("left", "左"));
//	//dict.Insert(make_pair("rotate", "旋转"));
//
//	test1();
//	test2();
//
//	return 0;
//}


void test1()
{
	sc::unordered_set<int> s;
	s.insert(1);
	sc::unordered_map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 1));
	m.insert(make_pair(3, 1));
	m.insert(make_pair(4, 1));
	m.insert(make_pair(5, 1));
	m.insert(make_pair(11, 1));
	m.insert(make_pair(6, 1));

	sc::unordered_map<int, int>::iterator it = m.begin();
	for (auto& kv : m)
	{
		cout << kv.first << ":" << kv.second;
		cout << endl;
	}
	cout << endl;

}

void test2()
{
	sc::unordered_set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);

	for (auto& e : s)
	{
		//e += 1;
		cout << e << " ";
	}
	cout << endl;

	sc::unordered_map<string, string> dict;
	dict.insert(make_pair("shit", "屎"));
	dict.insert(make_pair("left", ""));
	dict.insert(make_pair("right", "右"));

	for (auto& kv : dict)
	{
		//kv.first = "xx";
		//kv.second = "xx";
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	dict["left"] = "左";
	dict["handsome"] = "帅";
	dict["xxx"];
	for (auto& kv : dict)
	{
		//kv.first = "xx";
		//kv.second = "xx";
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

int main()
{
	//test1();
	test2();
	return 0;
}