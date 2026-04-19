#include<iostream>
using namespace std;
//class Person
//{
//public:
//    // 默认构造函数（无参）
//    Person()
//    {
//        cout << "Person()" << endl;
//    }
//};
//
//class Student : public Person
//{
//public:
//    // 派生类构造
//    Student()
//    {
//        cout << "Student()" << endl;
//    }
//};
//class Person
//{
//public:
//    // 只有带参构造，没有无参构造
//    Person(const char* name)
//    {
//        cout << "Person()" << endl;
//    }
//};
//
//class Student : public Person
//{
//public:
//    // 必须显式调用基类构造
//    Student()
//        : Person("张三")  // 必须写在初始化列表！
//    {
//        cout << "Student()" << endl;
//    }
//};
//int main()
//{
//    Student s;
//    return 0;
//}
class Person
{
public:
    ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person
{
public:
    ~Student() { cout << "~Student()" << endl; }
};

int main()
{
    Student s;
    return 0;
}