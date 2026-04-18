#include <iostream>
using namespace std;
#include <vector>
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	return 0;
//}
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//			++it;
//	}
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}
//两个参数偏特化为指针类型
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
////两个参数偏特化为引用类型
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		: _d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//void test2()
//{
//	Data<double, int> d1; // 调用特化的int版本
//	Data<int, double> d2; // 调用基础的模板
//	Data<int*, int*> d3; // 调用特化的指针版本
//	Data<int&, int&> d4(1, 2); // 调用特化的指针版本
//}
#include <iostream>
#include <typeinfo>
using namespace std;

// 主模板（通用版本）
template <typename T1, typename T2>
class Data {
public:
    Data() {
        cout << "通用版本 Data<T1, T2>" << endl;
        cout << "T1: " << typeid(T1).name() << endl;
        cout << "T2: " << typeid(T2).name() << endl;
    }
};

// 偏特化版本：第一个参数是引用，第二个是指针
template <typename T1, typename T2>
class Data <T1&, T2*> {
public:
    Data() {
        cout << "特化版本 Data<T1&, T2*>" << endl;
        int a = 0;
        T1& x = a;   // 等价于 int& x = a;
        T2* y = &a;  // 等价于 int* y = &a;
        T1 z = a;    // 等价于 int z = a;

        cout << "x 的类型: " << typeid(x).name() << endl;
        cout << "y 的类型: " << typeid(y).name() << endl;
        cout << "z 的类型: " << typeid(z).name() << endl;
    }
};

int main() {
    // 匹配通用版本
    Data<int, double> d1;
    cout << "---------------------" << endl;
    // 匹配偏特化版本
    Data<int&, int*> d2;
    return 0;
}