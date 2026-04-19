#include<iostream>
#include<string>
using namespace std;
//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//	{
//	}
//
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _num(num)
//	{
//	}
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//public:
//	Teacher(const char* name, int id)
//		:Person(name)
//		, _id(id)
//	{
//	}
//protected:
//	int _id; // 职工编号
//};
//
//// 不要去玩菱形继承
//class Assistant : public Student, public Teacher
//{
//public:
//	Assistant(const char* name1, const char* name2, const char* name3)
//		:Person(name3)
//		, Student(name1, 1)
//		, Teacher(name2, 2)
//	{
//	}
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 思考一下这里a对象中_name是"张三", "李四", "王五"中的哪一个？
//	Assistant a("张三", "李四", "王五");
//	cout << a._name << endl;
//
//	return 0;
//}
#include <iostream>
using namespace std;

class Base1 { public: int _b1; };
class Base2 { public: int _b2; };
class Derive : public Base1, public Base2 { public: int _d; };

int main()
{
    Derive d;
    Base1* p1 = &d;
    Base2* p2 = &d;
    Derive* p3 = &d;
    cout << "p1(Base1*) 地址: " << p1 << endl;
    cout << "p2(Base2*) 地址: " << p2 << endl;
    cout << "p3(Derive*)地址: " << p3 << endl;

     return 0;
}