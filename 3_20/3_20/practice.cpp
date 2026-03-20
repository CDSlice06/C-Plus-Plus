#include<iostream>
#include<string>
using namespace std;
int main()
{
	//default(1): string()
	string s1;
	//copy(2): string(const string & str)
	string s2("hello world");
	string s3(s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;


	//遇到空白字符就停止,比如你打
	//hello world 就只能出现hello
	// cin >> s1

	//用这种方式可以直接读取一行
	/*getline(cin, s1);
	cout << s1 << endl;*/


	//substring(3):	string(const string & str, size_t pos, size_t len = npos)
	string s4(s2, 6, 10);
	cout << s4 << endl;
	//最后一个不传参数,就会是缺省值,这个npos=-1,在size_t下就是int的最大值
	string s6(s2, 6);
	cout << s6 << endl;


	//from sequence(5): string(const char* s, size_t n)
	string s5("hello world", 5);
	cout << s5 << endl;

	//fill(6): string(size_t n, char c)
	string s7(10, 'x');
	cout << s7 << endl;

	//有string::operator[],我们可以仿照数组的访问方式了
	cout << s6[0] << endl;
	cout << s6[1] << endl;
	cout << s6[2] << endl;
	cout << s6[3] << endl;
	cout << s6[4] << endl;
	//我们同样也可以修改
	s7[0] = '6';
	s7[1] = '6';
	cout << s7 << endl;
	
	return 0;
}