//#include <iostream>
//using namespace std;
//
//class test
//{
//public:
//    // 两个参数，无explicit
//    test(int a, int b)
//    {
//        cout << "多参构造执行: a=" << a << ",b=" << b << endl;
//    }
//};
//
//int main()
//{
//    test t1{ 10,20 };   // ?直接列表初始化，所有版本合法
//    test t2 = { 10,20 };  // ?c++11允许！拷贝列表隐式转换，c++98报错
//    // test t3 = (10,20); // ?永远报错，逗号表达式=20，单参不匹配
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//class test
//{
//public:
//    // explicit修饰双参数构造（c++11新语法支持）
//    explicit test(int a, int b)
//    {
//        cout << "多参构造执行: a=" << a << ",b=" << b << endl;
//    }
//};
//
//int main()
//{
//    test t1{ 10,20 };    // ?【直接列表初始化】explicit不拦截，正常调用构造
//    // test t2={10,20}; // ?【拷贝列表初始化】explicit生效，禁止隐式转换，编译报错
//
//    test t3(10, 20);    // ?圆括号显式调用构造，不受explicit影响
//    return 0;
//}
#include <iostream>
using namespace std;

int main()
{
    // C++11 new[] + {}列表初始化：堆上开辟5个int空间
    // 前3个元素手动赋值：1、2、3；剩余第4、5位自动值初始化置0
    int* p2 = new int[5] {1, 2, 3};

    // 循环遍历打印5个堆数组元素
    cout << "数组全部元素：";
    for (int i = 0; i < 5; ++i)
    {
        cout << p2[i] << " ";
    }
    cout << endl;

    // 堆内存必须手动释放，避免内存泄漏
    delete[] p2;
    p2 = nullptr; // 置空野指针，规范写法

    return 0;
}
