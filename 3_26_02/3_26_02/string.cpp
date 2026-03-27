#include"string.h"
// modify

namespace CD
{
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

	}

	void string::append(const char* str)
	{

		}

	string& string::operator+=(const char* str)
	{

	}

	void clear()
	{

	}

	void string::swap(string& s)
	{

	}

	const char* string::c_str()const
	{

	}
}