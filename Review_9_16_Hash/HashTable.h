#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;


template<class K>
struct DefaultHash
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct DefaultHash<string>
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto ch : str)
		{
			hash *= 131;
			hash += ch;
		}
		return hash;
	}
};

namespace open_address
{
	enum State
	{
		EXSITS,
		EMPTY,
		DELETE
	};
	template<class K, class V>
	struct HashDate
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};



	template<class K, class V, class Default = DefaultHash<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_table.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			//控制负载因子扩容
			if ((double)_n / (double)_table.size() >= 0.7)
			{
				size_t newsize = _table.size() * 2;
				HashTable<K, V> newht;
				newht._table.resize(newsize);
				for (size_t i = 0; i < _table.size(); ++i)
				{
					if (_table[i]._state == EXSITS)
					{
						newht.Insert(_table[i]._kv);
					}
				}
				_table.swap(newht._table);
			}
			Default dh;
			size_t hashi = dh(kv.first) % _table.size();

			if (_table[hashi]._state == EXSITS)
			{
				++hashi;
				hashi %= _table.size();
			}
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXSITS;
			++_n;
			return true;
		}

		HashDate<const K, V>* Find(const K& key)
		{
			Default dh;
			size_t hashi = dh(key) % _table.size();

			if (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXSITS && _table[hashi]._kv.first == key)
				{
					return (HashDate<const K, V>*) & _table[hashi];
				}
				++hashi;
				hashi %= _table.size();
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			auto ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			return false;
		}

	private:
		vector<HashDate<K, V>> _table;
		size_t _n = 0;
	};
}


namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};

	template<class K, class T, class KOfT, class Default>
	class HashTable;

	template<class K, class T, class Ptr, class Ref, class KOfT, class Default>
	struct _Htiterator
	{
		typedef HashNode<T> Node;
		typedef _Htiterator<K, T, Ptr, Ref, KOfT, Default> self;
		typedef _Htiterator<K, T, T*, T&, KOfT, Default> iterator;
		Node* _node;
		const HashTable<K, T, KOfT, Default>* _ptr;

		_Htiterator(Node* node, const HashTable<K, T, KOfT, Default>* ptr)
			:_node(node)
			,_ptr(ptr)
		{}

		_Htiterator(const iterator& it)
			:_node(it._node)
			,_ptr(it._ptr)
		{}

		Ref  operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		self operator++()
		{
			KOfT kot;
			//当前桶还没完
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				Default df;
				size_t hashi = df(kot(_node->_data)) % _ptr->_table.size();
				++hashi;
				while (hashi < _ptr->_table.size())
				{
					Node* cur = _ptr->_table[hashi];
					if (cur)
					{
						_node = cur;
						return *this;
					}
					else
					{
						++hashi;
					}
				}
				_node = nullptr;
			}
			
			return *this;
		}

		bool operator!=(const self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const self& s) const
		{
			return _node == s._node;
		}


	};

	template<class K, class T, class KOfT, class Default = DefaultHash<K>>
	class HashTable
	{
		typedef HashNode<T> Node;
	public:
		typedef _Htiterator<K, T, T*, T&, KOfT, Default> iterator;
		typedef _Htiterator<K, T, const T*, const T&, KOfT, Default> const_iterator;


		template<class K, class T, class Ptr, class Ref, class KOfT, class Default>
		friend struct _Htiterator;

		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				if(cur)
				{
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}
		
		iterator end()
		{
			return iterator(nullptr, this);
		}



		const_iterator begin() const 
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return const_iterator(cur, this);
				}
			}
			return const_iterator(nullptr, this);
		}

		const_iterator end() const 
		{
			return const_iterator(nullptr, this);
		}

		HashTable()
		{
			_table.resize(10, nullptr);
		}

		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;

					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}

		pair<iterator, bool> insert(const T& data)
		{
			KOfT kot;
			Default dh;

			iterator it = find(kot(data));
			if (it != end())
			{
				return make_pair(it, false);
			}

			if (_n == _table.size())
			{
				size_t newsize = _table.size() * 2;
				vector<Node*> newtable;
				newtable.resize(newsize, nullptr);
				//遍历旧表，顺手牵羊
				for (size_t i = 0; i < _table.size(); ++i)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = dh(kot(cur->_data)) % newsize;
						newtable[hashi] = cur;
						cur = next;
					}
					_table[i] = nullptr;
				}
				_table.swap(newtable);
			}

			size_t hashi = dh(kot(data)) % _table.size();
			Node* newnode = new Node(data);

			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;
			return make_pair(iterator(newnode, this), true);
		}

		iterator find(const K& key)
		{
			Default dh;
			KOfT kot;
			size_t hashi = dh(key) % _table.size();
			
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}
				cur = cur->_next;
			}
			return iterator(nullptr, this);
		}


		bool erase(const K& key)
		{
			Default dh;
			KOfT kot;
			size_t hashi = dh(key) % _table.size();

			Node* cur = _table[hashi];
			Node* prev = nullptr;

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		void print()
		{

			for (size_t i = 0; i < _table.size(); ++i)
			{
				printf("bucket[%d]->", i);
				Node* cur = _table[i];
				while (cur)
				{
					cout << cur->_data.first << ":" << cur->_data.second<<" ";
					cur = cur->_next;
				}
				cout << endl;
			}
			cout << endl;
		}
	private:
		vector<Node*> _table;
		size_t _n;
	};
}