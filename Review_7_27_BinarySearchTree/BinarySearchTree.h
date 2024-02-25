#pragma once

namespace key
{
	template<class K>
	struct BSTNoode
	{
		BSTNoode<K>* _left;
		BSTNoode<K>* _right;
		K _key;

		BSTNoode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};


	template<class K>
	class BSTree
	{
		typedef BSTNoode<K> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}
		//t2(t1)
		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		BSTree<K>& operator=(BSTree<K> t)
		{
			std::swap(_root, t._root);
			return *this;
		}


		~BSTree()
		{
			Destory(_root);
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key);

			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		bool erase(const K& key)
		{
			Node* cur = _root;
			Node* parent = cur;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//左为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_right == cur)
							{
								parent->_right = cur->_right;
							}
							else
							{
								parent->_left = cur->_right;
							}
						}
					}
					//右为空
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_right == cur)
							{
								parent->_right = cur->_left;
							}
							else
							{
								parent->_left = cur->_left;
							}
						}
					}
					//都不为空
					else
					{
						//找替代值
						Node* leftmax = _root->_left;
						Node* parent = nullptr;
						while (leftmax->_right)
						{
							parent = leftmax;
							leftmax = leftmax->_right;
						}

						//替代值和要删除的值交换
						swap(cur->_key, leftmax->_key);

						if (parent->_left == leftmax)
						{
							parent->_left = leftmax->_left;
						}
						else
						{
							parent->_right = leftmax->_left;
						}
						cur = leftmax;
					}
					delete cur;
					return true;
				}
			}
			return false;
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

	private:
		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copyroot = new Node(root->_key);
			copyroot->_left = Copy(root->_left);
			copyroot->_right = Copy(root->_right);

			return copyroot;
		}
		void Destory(Node*& root)
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);
			delete root;

			root = nullptr;
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key == key)
			{
				return true;
			}

			return _FindR(root->_left, key)
				|| _FindR(root->_right, key);
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}
			if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root;
				//左为空
				//右为空
				//两边都不为空
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					//找替代结点
					Node* leftmax = root->_left;
					while (leftmax->_right)
					{
						leftmax = leftmax->_right;
					}

					swap(root->_key, leftmax->_key);

					return _EraseR(root->_left, key);
				}

				delete del;
				return true;
			}
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

	private:
		Node* _root;
	};


	void test1()
	{
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		BSTree<int> t;
		for (auto& e : a)
		{
			t.Insert(e);
		}
		t.InOrder();

		//cout << t.FindR(14) << endl;

		t.InsertR(0);
		t.InOrder();

		t.EraseR(8);
		t.InOrder();

		t.EraseR(10);
		t.InOrder();

		t.EraseR(6);
		t.InOrder();
		t.EraseR(13);
		t.InOrder();

		t.EraseR(14);
		t.InOrder();

	}

	void test2()
	{
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		BSTree<int> t1;
		for (auto& e : a)
		{
			t1.Insert(e);
		}
		t1.InOrder();

		BSTree<int> t2(t1);
		t2.InOrder();

		BSTree<int> t3;
		t3 = t2;
		t3.InOrder();

	}
}

/// <summary>
/// //////////////////////////////////////
/// </summary>
namespace key_value
{
	template<class K, class V>
	struct BSTNoode
	{
		BSTNoode<K, V>* _left;
		BSTNoode<K, V>* _right;
		K _key;
		V _value;

		BSTNoode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{}
	};


	template<class K, class V>
	class BSTree
	{
		typedef BSTNoode<K, V> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}
		//t2(t1)


		~BSTree()
		{
			Destory(_root);
		}

		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key, const V& value)
		{
			return _InsertR(_root, key, value);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

	private:
		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* copyroot = new Node(root->_key);
			copyroot->_left = Copy(root->_left);
			copyroot->_right = Copy(root->_right);

			return copyroot;
		}
		void Destory(Node*& root)
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);
			delete root;

			root = nullptr;
		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return root;
			}
		}

		bool _InsertR(Node*& root, const K& key, const V& value)
		{
			if (root == nullptr)
			{
				root = new Node(key, value);
				return true;
			}
			if (root->_key < key)
			{
				return _InsertR(root->_right, key, value);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key, value);
			}
			else
			{
				return false;
			}
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root;
				//左为空
				//右为空
				//两边都不为空
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					//找替代结点
					Node* leftmax = root->_left;
					while (leftmax->_right)
					{
						leftmax = leftmax->_right;
					}

					swap(root->_key, leftmax->_key);

					return _EraseR(root->_left, key);
				}

				delete del;
				return true;
			}
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << " "<<root->_value<<" ";
			_InOrder(root->_right);
		}

	private:
		Node* _root;
	};


	void test1()
	{
		BSTree<string, string> dict;

		dict.InsertR("insert", "插入");
		dict.InsertR("left", "左边");
		dict.InsertR("right", "右边");
		dict.InsertR("delete", "删除");

		string str;
		while (cin >> str)
		{
			BSTNoode<string, string>* ret = dict.FindR(str);
			if (ret)
			{
				cout << ret->_value << endl;
			}
		}
	}

	void test2()
	{
		BSTree<string, int> treecount;

		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜","苹果", "香蕉", "苹果", "香蕉" };

		for (auto& str : arr)
		{
			BSTNoode<string, int>* ret = treecount.FindR(str);
			if (ret == nullptr)
			{
				treecount.InsertR(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}

		treecount.InOrder();

	}
}