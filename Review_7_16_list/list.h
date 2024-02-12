#pragma once

#include <iostream>
#include <list>
#include <assert.h>
using namespace std;

namespace sc
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _val;
		_list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef _list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*() 
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &_node->_val;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);

			_node = _node->_next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);

			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& lt) const
		{
			return _node != lt._node;
		}

		bool operator==(const self& lt) const
		{
			return _node == lt._node;
		}

	};

	 
	template<class T>
	class list
	{
		typedef _list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;


		iterator begin()
		{
			//单参数的构造函数支持隐式类型的转换
			return iterator(_head->_next);
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return _head;
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
			_size = 0;
		}
		//lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		//lt3 = lt2
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		~list()
		{
			clean();
			delete _head;
			_head = nullptr;
		}
		void push_back(const T& x)
		{
			/*Node* tail = _head->_prev;
			Node*newnode = new Node(x);

			tail->_next = newnode;
			newnode->_prev = tail;

			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(val);

			prev->_next = newnode;
			newnode->_next = cur;

			newnode->_prev = prev;
			cur->_prev = newnode;

			_size++;

			return newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;

			--_size;

			return next;
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		size_t size()
		{
			return _size;
		}

		void clean()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
			_size = 0;
		}
		
	private:
		Node* _head;
		size_t _size;
	};

	class A
	{
	public:
		A(const int a1 = 1, const int a2 = 2)
			:_a1(a1)
			,_a2(a2)
		{}

		int _a1;
		int _a2;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(4);
		lt.push_back(4);

	/*	list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;*/

		/*for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;*/
	}

	//const迭代器要匹配const类型
	void Print(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it += 10;
			cout << *it << " ";
			*it++;
		}
		cout << endl;
	}

	void test_list2()
	{
		list<A> lt;
		lt.push_back(A(1, 1));
		lt.push_back(A(2, 2));
		lt.push_back(A(3, 3));
		lt.push_back(A(4, 4));

		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1 << " " << (*it)._a2;
			cout << it->_a1 << " " << it->_a2;
			++it;
			cout << endl;
		}

		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int>::iterator it1 = lt1.begin();
		while (it1 != lt1.end())
		{
			//*it1 += 1;
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
		Print(lt1);
	}

	void test_list3()
	{
		list<int> lt;
		lt.insert(lt.begin(), 3);
		for (auto& e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		for (auto& e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.clean();

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		lt.pop_back();
		lt.pop_front();

		lt.push_front(20);
		lt.push_front(30);
		lt.push_front(40);

		for (auto& e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list4()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(1);
		lt1.push_back(1);
		lt1.push_back(1);
		for (auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2(lt1);
		for (auto& e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt3;

		lt3 = lt2;
		for (auto& e : lt3)
		{
			cout << e << " ";
		}
		cout << endl;

		cout << lt1.size() << endl;
	}
}

