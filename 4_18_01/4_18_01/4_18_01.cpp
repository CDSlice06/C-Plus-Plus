//#include <iostream>
//using namespace std;
//
//// 日期类（方便比较）
//struct Date
//{
//    int _year, _month, _day;
//
//    Date(int y, int m, int d) : _year(y), _month(m), _day(d) {}
//
//    // 重载 < 让日期能比较
//    bool operator<(const Date& d) const
//    {
//        if (_year != d._year) return _year < d._year;
//        if (_month != d._month) return _month < d._month;
//        return _day < d._day;
//    }
//};
//
//// 函数模板：通用比较
//template<class T>
//bool Less(T left, T right)
//{
//    cout << "使用【通用模板】比较：";
//    return left < right;
//}
//
// //特化：专门处理指针！！！（解决错误）
////template<>
////bool Less<Date*>(Date* left, Date* right)
////{
////    cout << "使用【指针特化】比较（解引用后比较）：";
////    return *left < *right;
////}
//
//int main()
//{
//    // 1. 普通 int
//    cout << Less(1, 2) << endl;
//
//    // 2. Date 对象：先定义大日期，再定义小日期
//    Date d2(2022, 7, 8); // 大日期，先定义，地址低
//    Date d1(2022, 7, 7); // 小日期，后定义，地址高
//
//    cout << Less(d1, d2) << endl; // 对象比较，仍然是 1（正确）
//
//    // 3. Date 指针
//    Date* p1 = &d1; // 高地址
//    Date* p2 = &d2; // 低地址
//    cout << Less(p1, p2) << endl; // 地址比较：高地址 < 低地址 → 0（错误！）
//
//    return 0;
//}
#include <iostream>
using namespace std;

struct Date {
    int _year, _month, _day;
    Date(int y, int m, int d) : _year(y), _month(m), _day(d) {}
    bool operator<(const Date& d) const { return true; }
};

// 1. 【通用模板】
template<class T>
bool Less(T left, T right)
{
    cout << "通用模板\n";
    return left < right;
}

// 2. 【模板特化】
template<>
bool Less<Date*>(Date* left, Date* right)
{
    cout << "模板特化\n";
    return *left < *right;
}

// 3. 【普通函数】（非模板！）
//bool Less(Date* left, Date* right)
//{
//    cout << "普通函数\n";
//    return *left < *right;
//}
int main()
{
    Date d1(2022, 7, 7), d2(2022, 7, 8);
    Less(&d1, &d2); 
}