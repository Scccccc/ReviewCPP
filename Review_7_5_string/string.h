#pragma once

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

namespace sc
{
	class string
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return begin()+_size;
		}

		string(const char* s = "")
		{
			_size = strlen(s);
			_capacity = strlen(s);
			_str = new char[_capacity + 1];
			strcpy(_str, s);
		}

		string(const string& str)
		{
			char* tmp = new char[str._capacity+1];
			memcpy(tmp, str._str, str._capacity+1);
			_str = tmp;
			_size = str._size;
			_capacity = str._capacity;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//string& operator=(const string& s)
		//{
		//	if (*this != s)
		//	{
		//		string tmp(s);
		//		swap(tmp);
		//	}
		//	return *this;
		//}

		string& operator=(string s)
		{
			swap(s);
			return *this;
		}

		char* c_str()
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		string& operator+= (char c)
		{
			push_back(c);
			return *this;
		}


		string& operator+= (const char* s)
		{
			append(s);
			return *this;
		}


		size_t size() const
		{
			return _size;
		}


		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char c = '\0')
		{
			if (n < _capacity)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = c;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		void push_back(const char ch)
		{
			if (_capacity == _size)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
				_str[_size++] = ch;
				_str[_size] = '\0';
		}

		string& append(const char* s)
		{
			size_t len = strlen(s);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}

			for (size_t i = 0; i < len; ++i)
			{
				_str[_size++] = s[i];
			}
			_str[_size] = '\0';
			return *this;
		}

		void insert(size_t pos, size_t n, const char ch)
		{
			assert(pos <= _size);

			size_t len = n;
			if (len + _size > _capacity)
			{
				reserve(_size+len);
			}

			//挪动数据
			int end = _size;
			while ((int)pos <= end)
			{
				_str[end + len] = _str[end];
				--end;
			}

			for (size_t i = 0; i < len ; ++i)
			{
				_str[pos + i] = ch;
			}
			_size += len;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(_size + len);
			}

			int end = _size;
			while ((int)pos <= end)
			{
				_str[end + len] = _str[end];
				--end;
			}

			for (size_t i = 0; i < len; ++i)
			{
				_str[pos + i] = str[i];
			}
			_size += len;
		}

		void erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t end = pos + len;
				while (pos <= _size - len)
				{
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* s, size_t pos = 0) const
		{
			assert(pos < _size);
			const char* ptr = strstr(_str, s);
			if (ptr)
			{
				return ptr - _str;
			}
			else
			{
				return npos;
			}
		}

		string substr(size_t pos = 0, size_t len = npos) const
		{
			size_t n = len;
			if (len == npos || pos+len >= _size)
			{
				n = _size - pos;
			}

			string tmp;
			tmp.reserve(n);
			for (size_t i = pos; i < pos - n; ++i)
			{
				tmp += _str[i];
			}

			return tmp;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		//bool operator<(const string& s) const
		//{
		//	size_t i1 = 0;
		//	size_t i2 = 0;
		//	while (i1 < _size && i2 < s._size)
		//	{
		//		if (_str[i1] < s._str[i2])
		//		{
		//			return true;
		//		}
		//		else if (_str[i1] > s._str[i2])
		//		{
		//			return false;
		//		}
		//		else
		//		{
		//			i1++;
		//			i2++;
		//		}
		//	}

		//	/*if (i1 == _size && i2 != s._size)
		//	{
		//		return true;
		//	}
		//	else
		//	{
		//		return false;
		//	}*/

		//	return i1 == _size && i2 != s._size;
		//}

		bool operator<(const string& s) const
		{
			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);

			//hello      //helloxxx
			//helloxxx   //hello
			return ret == 0 ? _size < s._size : ret < 0;
		}

		bool operator==(const string& s) const
		{
			return _size == s._size && memcmp(_str, s._str, _size) == 0;
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s)const
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s) const
		{
			return  !(*this < s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		static size_t npos;
	};
	size_t string::npos = -1;


	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch = in.get();
		//清理空格和换行
		while (ch == ' ' || ch == '\n')
		{
			ch = in.get();
		}

		char buff[128];
		size_t i = 0;
		while (ch != '\n')
		{
			buff[i++] = ch;
			ch = in.get();
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
		}
		if (i != 0)
		{
			buff[i] = '\0'; 
			s += buff;
		}
		return in;



		/*char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;*/
	}
}