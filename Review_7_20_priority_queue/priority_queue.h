#pragma once

namespace sc
{
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	private:
		void AdJustDown(int parent)
		{
			Compare com;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				//先判断越界没有，不然会报错
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}

			}
		}

		void AdJustUp(int child)
		{
			Compare com;

			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}

			}
		}
	public:
		template<class Inputiterator>
		priority_queue(Inputiterator first, Inputiterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				AdJustDown(i);
			}
		}

		void push(const T& val)
		{
			_con.push_back(val);
			AdJustUp(_con.size()-1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size()-1]);
			_con.pop_back();

			/*for (int i = _con.size() - 1; i > 0; --i)
			{
				AdJustUp(i);
			}*/

			AdJustDown(0);
		}

		T& top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;
	};
}