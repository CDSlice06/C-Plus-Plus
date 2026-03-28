#include"string.h"
// modify

namespace CD
{
	const size_t string::npos = -1;

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			//cout << "reserve:" << n << endl;

			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	// capacity

	size_t string::size()const
	{
		return _size;
	}

	size_t string::capacity()const
	{
		return _capacity;
	}

	bool string::empty()const
	{
		if (_size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void string::resize(size_t n, char c)
	{
		if (n == _size)
		{
			return;
		}
		if (n < _size)
		{
			_str[n] = '\0';
			_size = n;
		}
		else
		{
			if (n > _capacity)
			{
				reserve(n > 2 * _capacity ? n : 2 * _capacity);
			}
			for (size_t i = _size; i < n; i++)
				_str[i] = c;
			_str[n] = '\0';
			_size = n;
		}

	}

	void string::push_back(char c)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = c;
		++_size;
		_str[_size] = '\0';
	}

	string& string::operator+=(char c)
	{
		/*if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = c;
		_size++;
		_str[_size] = '\0';*/
		push_back(c);
		return *this;
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			//大于两倍需要多少开多少,小于两倍按2倍扩
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}
		strcpy(_str, str);
		_size += len;
	}

	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	void string::clear()//把字符串清空,同时不释放堆内存(复用空间,避免频繁申请释放)
	{
		_str[0] = '\0';
		_size = 0;
		//以上不建议反着写,因为反着写时,先把长度改成 0，再写\0，中间会出现一个短暂的 “不一致状态”：_size=0，但_str[0]还是原来的字符
	}

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
		
	}
	//这两种都是一样的,等效,下面这个直接调用我们写的那个
	void swap(string& a, string& b)
	{
		a.swap(b);  
	}

	const char* string::c_str()const
	{
		return _str;
	}

	// access

	char& string::operator[](size_t index)
	{
		return _str[index];
	}

	const char& string::operator[](size_t index)const
	{
		return _str[index];
	}

	// 返回c在string中第一次出现的位置

	size_t string::find(char c, size_t pos) const
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] = c)
			{
				return i;
			}
		}
		return npos;
	}

	// 返回子串s在string中第一次出现的位置

	size_t string::find(const char* s, size_t pos) const
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, s);
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
		
	}

	// 在pos位置上插入字符c/字符串str，并返回该字符的位置

	string& string::insert(size_t pos, char c)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		_size++;
		return *this;
	}

	string& string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size+len > _capacity)
		{
			reserve(_size + len > _capacity * 2 ? _size + len : _capacity);
		}
		size_t end = _size + len;
		//_size表示实际的有效字符个数,不包括\0,但是_size的数值正好使指针指向\0
		//加上一个len,表示我们最后预期的长度
		while (end>=pos+len)
		{
			_str[end] = _str[end-len];
			end--;
		}
		for (size_t i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}
		_size += len;
		return *this;
	}



	// 删除pos位置上的元素，并返回该元素的下一个位置

	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len > _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
			return *this;
		}
		else
		{
			for (size_t i = pos + len; i < _size; i++)
			{
				_str[i - len] = _str[i];
				_str++;
			}
			_size -= len;
			return *this;
		}
	}

	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len > _size - pos)
		{
			len = _size - pos;
		}
		string sub;
		sub.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			sub += _str[pos + i];
		}
		return sub;
	}

	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		out << s._str;
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		const int N = 256;
		char buff[N];
		int i = 0;
		char ch;
		ch = in.get();
		//如果这里用in>>ch,由于cin读取数据读不了空格和换行,会自动忽略,因此就不知道什么时候停止
		//而get()不会忽略任何字符,空格,换行都会读进去
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
}