#pragma once
#include "HashTable.h"


namespace sc
{
	template<class K, class V>
	class unordered_map
	{
		struct mapkoft
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, mapkoft>::iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, mapkoft>::const_iterator const_iterator;

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
			return ret.first->second;
		}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		const_iterator begin() const 
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}


	private:
		hash_bucket::HashTable<K, pair<const K, V>, mapkoft> _ht;
	};
}