#include<iostream>
#include<string>
using namespace std;
void test_string1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	cout << s1 << s2 << endl;
	s2[5] = '6';
	cout << s1 << s2 << endl;

	//1.下标+[]
	for (size_t i = 0; i < s2.size(); i++)
	{
		cout << s2[i]<<" ";
	}
	
	cout<< endl;

	//2.迭代器
	//string::iterator it = s2.begin();
	auto it = s2.begin();
	while (it != s2.end())
	{
		*it += 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//3.字符赋值,自动迭代,自动判断结束
	//auto& ch:s3  不能修改s3里面的内容
	for (auto& ch : s3)//可以修改里面的内容
	{
		ch -= 2;
		cout << ch << " ";
	}
	cout << endl;
	cout << s3 << endl;
}
int main()
{
	test_string1();
	return 0;
}
