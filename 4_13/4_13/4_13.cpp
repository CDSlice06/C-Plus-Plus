#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

namespace CD
{

class string

{

public:
	friend ostream& operator<<(ostream& out, const string& s);
	
	string(const char* str = "")
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	string(const string& s)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
	}

	string& operator=(const string& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
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
};
}
ostream& operator<<(ostream& out, const string& s)
{
	for (auto ch : s)
	{
		out << ch;
	}

	return out;
}
int main()
{
	string s1("hello world");
	cout << s1 << endl;
	string s2(s1);
	cout << s2 << endl;
	string s3 = s1;
	cout << s3 << endl;
	return 0;
}
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int cur = 1, dest = 0;
		while (cur != nums.size())
		{
			if (nums[cur] != nums[dest])nums[++dest] = nums[cur];
			cur++;
		}
		return dest + 1;
	}
};