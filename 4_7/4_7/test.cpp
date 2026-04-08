#include"list.h"
void test1()
{
	CD::list <int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	print_container(lt);
}
int main()
{
	test1();
	return 0;
}