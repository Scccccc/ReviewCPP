#pragma once

#include <iostream>
using namespace std;

enum Col
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Col _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_col(RED)
	{}

};

template<class T, class Ptr, class Ref>
class __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T, Ptr, Ref> Self;
	typedef __TreeIterator<T, T*, T&> iterator;
public:
	__TreeIterator(Node* node)
		:_node(node)
	{}

	__TreeIterator(const iterator& x)
		:_node(x._node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self operator++()
	{
		if (_node->_right)
		{
			Node* subleft = _node->_right;
			while (subleft->_left)
			{
				subleft = subleft->_left;
			}
			_node = subleft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent)
			{
				if (parent->_left == cur)
				{
					break;
				}
				else
				{
					cur = parent;
					parent = parent->_parent;
				}
			}
			_node = parent;
		}
		
		return *this;
	}

	Self operator--()
	{
		if (_node->_left)
		{
			Node* subright = _node->_left;
			while (subright->_right)
			{
				subright = subright->_right;
			}
			_node = subright;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			
			while (parent)
			{
				if (parent->_right == cur)
				{
					break;
				}
				else
				{
					cur = parent;
					parent = parent->_parent;
				}
			}
		}
		return *this;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;

	}

	bool operator!=(const Self& s) const
	{
		return _node!= s._node;
	}

//private:
	Node* _node;
};


template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T, T*, T&> iterator;
	typedef __TreeIterator<T, const T*, const T&> const_iterator;

	iterator begin()
	{
		Node* leftmin = _root;
		while (leftmin->_left)
		{
			leftmin = leftmin->_left;
		}
		return iterator(leftmin);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	const_iterator begin() const 
	{
		Node* leftmin = _root;
		while (leftmin->_left)
		{
			leftmin = leftmin->_left;
		}
		return const_iterator(leftmin);
	}

	const_iterator end() const
	{
		return const_iterator(nullptr);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		KeyOfT kot;
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		cur->_col = RED;
		Node* newnode = cur;
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//控制颜色
		while (parent && parent->_col == RED)
		{
		
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//uncle存在且为红色：把父亲结点和叔叔结点变黑，爷爷结点变红，然后继续向上更新
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else//uncle不存在或者uncle存在且为黑：旋转+变色
				{
					//单旋
					//      g
					//   p
					//c
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//双旋
					//      g
					//   p
					//      c
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				//uncle存在且为红色：把父亲结点和叔叔结点变黑，爷爷结点变红，然后继续向上更新
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else//uncle不存在或者uncle存在且为黑：旋转+变色
				{
					
					//单旋
					//  g
					//     p
					//        c
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//双旋
					//      g
					//         p
					//      c
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(newnode), true);
	}

	bool Isbalance()
	{
		return Isbalance(_root);
	}
private:
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		parent->_right = curleft;
		if (curleft)
		{
			curleft->_parent = parent;
		}
		cur->_left = parent;
		Node* ppNode = parent->_parent;

		parent->_parent = cur;
		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = cur;
			}
			else
			{
				ppNode->_right = cur;
			}
			cur->_parent = ppNode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;

		parent->_left = curright;
		if (curright)
		{
			curright->_parent = parent;
		}
		cur->_right = parent;
		Node* ppNode = parent->_parent;

		parent->_parent = cur;
		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = cur;
			}
			else
			{
				ppNode->_right = cur;
			}
			cur->_parent = ppNode;
		}
	}

	bool CheckColor(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blacknum != benchmark)
				return false;

			return true;
		}

		if (root->_col == BLACK)
		{
			++blacknum;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << "root: " << root->_kv.first << " parent: " << root->_parent->_kv.first << " Continuous red nodes" << endl;
			return false;
		}

		return CheckColor(root->_left, blacknum, benchmark) && CheckColor(root->_right, blacknum, benchmark);
	}

	bool Isbalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		if (root->_col != BLACK)
		{
			return false;
		}

		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;
			cur = cur->_left;
		}
		return CheckColor(root, 0, benchmark);
	}

private:
	Node* _root = nullptr;
};