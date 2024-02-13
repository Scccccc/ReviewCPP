#pragma once


namespace sc
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		bool empty()
		{
			return _con.empty();
		}
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_front();
		}
		size_t size()
		{
			return _con.size();
		}
		T& back()
		{
			return _con.back();
		}
		T& front()
		{
			return _con.front();
		}
	private:
		Container _con;
	};
}