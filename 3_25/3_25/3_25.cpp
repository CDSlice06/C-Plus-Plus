#include<iostream>
using namespace std;
//栈:局部变量,函数参数
//堆:动态分配的对象,内存
//数据段:全局,静态变量
//代码段:代码,字符串常量,const
int globalVar = 1;//全局变量,数据段(静态库)

static int staticGlobalVar = 1;//静态全局变量,数据段(静态库)

void Test()

{

	static int staticVar = 1;//静态局部变量,数据段(静态库)

	int localVar = 1;//局部变量,栈



	int num1[10] = { 1, 2, 3, 4 };//num1,数组名,代表栈上的数组空间

	char char2[] = "abcd";//char2是数组名,代表栈上的数组空间,存于栈
	//*char2是数组首元素'a',存储在栈上的数组,存于栈

	const char* pChar3 = "abcd";//*char为"abcd",为代码段(常量区)

	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ptr1,指针变量本身,属于局部变量,存于栈
	//*ptr1是malloc动态申请的堆内存,存于堆

	int* ptr2 = (int*)calloc(4, sizeof(int));//这和上面一样

	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);//这和上面一样

	free(ptr1);

	free(ptr3);

}
