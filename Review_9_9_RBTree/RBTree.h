#pragma once

#include <iostream>
using namespace std;

enum Col
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Col _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(RED)
	{}

};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
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
		return true;
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