#include <iostream>
using namespace std;

// 1. 用 final 修饰基类，表示这个类不能被继承
//class Person final
//{
//public:
//    void print()
//    {
//        cout << "我是 Person 类" << endl;
//    }
//};

// 2. 尝试继承 final 修饰的类
// 下面这行代码编译时会直接报错！
//class Student : public Person
//{
//};
//
//int main()
//{
//    Student s;
//    return 0;
//}
//class Person
//{
//public:
//    string _name;
//    static int _count;
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//    int _stuNum;
//};
//
//int main()
//{
//    Person p;
//    Student s;
//
//    // 这里的运行结果可以看到非静态成员_name的地址是不一样的
//    // 说明派生类继承下来了，父派生类对象各有一份
//    cout << &p._name << endl;
//    cout << &s._name << endl;
//
//    // 这里的运行结果可以看到静态成员_count的地址是一样的
//    // 说明派生类和基类共用同一份静态成员
//    cout << &p._count << endl;
//    cout << &s._count << endl;
//
//    // 公有的情况下，父派生类指定类域都可以访问静态成员
//    cout << Person::_count++ << endl;
//    cout << Student::_count << endl;
//
//    return 0;
//}
//
//
