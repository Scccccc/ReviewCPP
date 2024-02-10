#pragma once

#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

namespace sc
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const 
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
		{}

		vector(size_t n, const T& val = T())
		{
			resize(n, val);
		}
		//解决调用奇异，如果实参传过来的是两个int类型，不会走上面的构造
		//因为上面一个是size_t一个是模板类型，两个int类型会去调用更适合自己胃口的拷贝构造
		vector(int n, const T& val = T())
		{
			resize(n, val);
		}

		template<class Inputiterator>
		vector(Inputiterator first, Inputiterator last)
		{
			
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//v1 = v2
		vector(const vector<T>& s)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storege(nullptr)
		{
			_start = new T[s.capacity()];
			//memcpy(_start, s._start, sizeof(T) * s.size());
			for (size_t i = 0; i < s.size(); i++)
			{
				_start[i] = s._start[i];
			}
			_finish = _start + s.size();
			_end_of_storege = _start + s.capacity();
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storege, v._end_of_storege);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storege = nullptr;
			}
		}


		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();

				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storege = _start + n;
			}
			
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start+n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		
		void push_back(const T& x)
		{
			/*if (_finish == _end_of_storege)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;*/
			insert(end(), x);
		}

		void pop_back()
		{
			erase(end()-1);
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_of_storege)
			{
				size_t len = pos - _start;

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				//解决迭代器失效问题
				pos = _start + len;
				
			}

			iterator end = _finish-1;
			while (pos <= end)
			{
				*(end+1) = *end;
				end--;
			}
			*pos = val;
			_finish++;
			return pos;
			
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);

			iterator it = pos;
			while (it != _finish)
			{
				//*(it-1) = *it;
				*it = *(it + 1);
				++it;
			}
			--_finish;
			return pos;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storege - _start;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storege = nullptr;
	};

	void test_vector1()
	{
		sc::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (auto e : v)
		{
			cout << e;
		}
		cout << endl;
	}

	void test_vector2()
	{
		vector<string> v;
		v.push_back("111111111");
		v.push_back("222222222");
		v.push_back("333333333");
		v.push_back("444444444");
		v.push_back("555555555");
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<string> v1;
		v1 = v;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

	}
	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);

		auto it = v.begin();
		v.insert(it, 2);
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.end()-1);
		for (auto& e : v)
		{
			cout << e << " ";
		}
	}
	void test_vector4()
	{
		vector<string> v1;
		v1.push_back("11111");
		v1.push_back("22222");
		v1.push_back("33333");
		v1.push_back("44444");
		v1.push_back("55555");
		v1.resize(10, "1");

		vector<string> v2(v1);

		for (auto& e : v2)
		{
			cout << e << " ";
		}
	}

	void test_vector5()
	{
		vector<string> v1;
		v1.push_back("11111");
		v1.push_back("22222");
		v1.push_back("33333");
		v1.push_back("44444");
		v1.push_back("55555");
		vector<string> v2(v1);

		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		vector<string> v1;
		v1.push_back("11111");
		v1.push_back("22222");
		v1.push_back("33333");
		v1.push_back("44444");
		v1.push_back("55555");
		vector<string> v2;

		v2 = v1;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		v2.pop_back();
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector7()
	{
		vector<int> v(10, 1);
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v1(v.begin(), v.end());
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

}