#pragma once

#include "RBTree.h"

namespace sc
{
	template<class K, class V>
	class map
	{
	public:
		struct KeyOfMap
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

		typedef typename RBTree<K, pair<const K, V>, KeyOfMap>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, KeyOfMap>::const_iterator const_iterator;


		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}

		const_iterator begin() const
		{
			return _t.begin();
		}
		const_iterator end() const 
		{
			return _t.end();
		}

	private:
		RBTree<K, pair<const K, V>, KeyOfMap> _t;
	};
}