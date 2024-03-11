#pragma once

#include "RBTree.h"

namespace sc
{
	template<class K>
	class set
	{
	public:
		struct KeyOfSet
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		typedef typename RBTree<K, K, KeyOfSet>::const_iterator iterator;
		typedef typename RBTree<K, K, KeyOfSet>::const_iterator const_iterator;

		
		pair<iterator, bool> insert(const K& key)
		{
			pair<typename RBTree<K, K, KeyOfSet>::iterator, bool> ret = _t.Insert(key);
			return pair<iterator, bool>(ret.first, ret.second);
		}

		iterator begin() const
		{
			return _t.begin();
		}

		iterator end() const
		{
			return _t.end();
		}

	private:
		RBTree<K, K, KeyOfSet> _t;
	};
}