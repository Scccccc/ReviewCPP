#pragma once

namespace sc
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
		T& top()
		{
			return _con.back();
		}
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_back();
		}
	private:
		Container _con;
	};
}