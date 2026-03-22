#include<iostream>
#include<string>
using namespace std;
void test_string1()
{
	string s1;
	string s2("hello world");

	//正序打印
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//逆序打印
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	//加了const s3的内容无法修改
	const string s3(s2);
	//string::const_iterator cit=s3.begin();下面的方法等价于这种写法
	// string::const_iterator 这个就是类型名
	//auto让编译器根据变量的初始化值,自动判断并确定变量的类型,不用手动写冗长的类型名
	auto cit = s3.begin();
	while (cit != s3.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	//string::const_reverse_iterator it = s3.rbegin();
	auto rcit = s3.rbegin();
	while (rcit != s3.rend())
	{
		cout << *rcit << " ";
		++rcit;
	}
	cout << endl;

}
void test_string2()
{
	string s2 = { "hello world" };//string s2("hellow world");
	cout << s2 << endl;
	cout << endl;
	//检验字符串长度
	cout << s2.length() << endl;
	cout << s2.size() << endl;

	//返回当前编译器下,这个string对象理论上能容纳的最大字符数
	cout << s2.max_size() << endl;
	//返回当前对象的能够存储的空间大小
	cout << s2.capacity() << endl;

	//返回string对象的内存布局,跟我存入的内容没关系
	string s3("oooooooooooooooooooooooooo");
	cout << sizeof(s3) << endl;
	cout << sizeof(s2) << endl;
}
int main()
{
	//test_string1();
	test_string2();
	return 0;
}