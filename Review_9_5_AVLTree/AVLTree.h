#pragma once


#include <iostream>
#include <assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while(cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
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

		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		//控制平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if(parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			//不平衡了，需要旋转
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//右旋
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				//左旋
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				//右左双旋
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				//左右双旋
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
			}
			else
			{
				assert(false);
			}
		}

		return true;
	}
private:

	void RotateRL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		int bf = curleft->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 0)
		{
			parent->_bf = 0;
			cur->_bf = 0;
			curleft->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			cur->_bf = 1;
			curleft->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			cur->_bf = 0;
			curleft->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateLR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		int bf = curright->_bf;
		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 0)
		{
			parent->_bf = 0;
			cur->_bf = 0;
			curright->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			cur->_bf = 1;
			curright->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			cur->_bf = 0;
			curright->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

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
		if (ppNode == nullptr)
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

		cur->_bf = parent->_bf = 0;
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
		if (ppNode == nullptr)
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
		cur->_bf = parent->_bf = 0;
	}
private:
	Node* _root = nullptr;
};