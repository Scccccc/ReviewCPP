#pragma once
#include "HashTable.h"

namespace sc
{
	template<class K>
	class unordered_set
	{
		struct setkoft
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, K, setkoft>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, setkoft>::const_iterator const_iterator;

		pair<iterator, bool> insert(const K& key)
		{
			 pair<typename hash_bucket::HashTable<K, K, setkoft>::iterator, bool> ret = _ht.insert(key);
			 return pair<iterator, bool>(ret.first, ret.second);
		}

		iterator begin() const 
		{
			return _ht.begin();
		}

		iterator end() const 
		{
			return _ht.end();
		}

		
	private:
		hash_bucket::HashTable<K, K, setkoft> _ht;
	};
}