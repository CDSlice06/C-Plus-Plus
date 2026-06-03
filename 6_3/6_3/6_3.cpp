////////
////////// C++98 初始化：乱！
////////int arr[] = { 1,2,3 };        // 数组可以用 {}
////////struct A { int x; int y; };
////////A a = { 1,2 };                // 结构体可以用 {}
////////
////////// 类不行！
////////class Date
////////{
////////public:
////////    Date(int year, int month, int day) {}
////////};
////////// Date d = {2025,1,1};     ? C++98 报错
////////
////////// 容器更麻烦，不能批量初始化
////////vector<int> v;
////////v.push_back(1);
////////v.push_back(2);
////////v.push_back(3);
//////#include <iostream>
//////using namespace std;
//////
//////int main()
//////{
//////    // 1. 普通 int 初始化
//////    int a = { 10 };     // 写法1：= + {}  C++11 支持
//////    int b{ 20 };        // 写法2：直接 {} 最推荐！现代 C++ 风格
//////    int c{};            // 空 {}：默认值初始化，c = 0
//////
//////    // 2. double 类型
//////    double d{ 3.14 };   // 直接初始化
//////
//////    // 打印验证
//////    cout << a << endl;
//////    cout << b << endl;
//////    cout << c << endl;
//////    cout << d << endl;
//////
//////    return 0;
//////}
////#include <iostream>
////using namespace std;
////
////// 结构体（聚合类型）
////struct Point
////{
////    int x;
////    int y;
////};
////
////// 类
////class Date
////{
////public:
////    // 构造函数
////    Date(int year, int month, int day)
////    {
////        _year = year;
////        _month = month;
////        _day = day;
////    }
////
////    // 打印函数
////    void Print()
////    {
////        cout << _year << "-" << _month << "-" << _day << endl;
////    }
////
////private:
////    int _year;
////    int _month;
////    int _day;
////};
////
////int main()
////{
////    // 1. 结构体 C++11 列表初始化
////    Point p{ 10, 20 };       // 直接 {}，不需要 =
////    cout << p.x << " " << p.y << endl;
////
////    // 2. 类 C++11 列表初始化（C++98 做不到！）
////    Date d1{ 2025, 1, 1 };   // 直接调用构造函数
////    d1.Print();
////
////    Date d2 = { 2024, 12, 25 }; // 加 = 也可以
////    d2.Print();
////
////    return 0;
////}
//#include <iostream>
//#include <vector>
//#include <map>
//#include <string>
//using namespace std;
//
//int main()
//{
//    // vector 直接用 {} 批量初始化
//    vector<int> v{ 1,2,3,4,5 };
//
//    // 遍历打印
//    for (auto e : v)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//
//    // map 嵌套 {} 初始化
//    map<string, string> dict{
//        {"apple", "苹果"},
//        {"book", "书"},
//        {"student", "学生"}
//    };
//
//    // 遍历 map
//    for (auto& kv : dict)
//    {
//        cout << kv.first << " : " << kv.second << endl;
//    }
//
//    return 0;
//}
#include<iostream>
using namespace std;
int main()
{
    int* p1 = new int{};   //堆内存int值初始化为0
    int* p2 = new int[5] {1, 2, 3};//前3赋值，剩余自动0
    cout << "数组全部元素：";
    for (int i = 0; i < 5; ++i)
    {
        cout << p2[i] << " ";
    }
    cout << endl;
    cout << *p1 << endl;
    delete[] p2;
    delete p1;
    return 0;
}