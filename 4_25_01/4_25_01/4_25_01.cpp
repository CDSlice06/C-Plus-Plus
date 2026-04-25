////#include <iostream>
////using namespace std;
////
////// 基类：Person
////class Person {
////public:
////    // 虚函数：买票行为
////    virtual void buyTicket() {
////        cout << "普通人：全价买票" << endl;
////    }
////};
////
////// 派生类：Student
////class Student : public Person {
////public:
////    // 重写买票行为
////    virtual void buyTicket() override {
////        cout << "学生：半价优惠买票" << endl;
////    }
////};
////
////// 派生类：Soldier
////class Soldier : public Person {
////public:
////    // 重写买票行为
////    virtual void buyTicket() override {
////        cout << "军人：优先买票" << endl;
////    }
////};
////
////// 多态场景：统一接口调用
////void doBuy(Person& p) {
////    p.buyTicket();
////}
////
////int main() {
////    Person p;
////    Student s;
////    Soldier so;
////
////    // 同一接口，不同对象，表现不同行为
////    doBuy(p);   // 普通人调用基类实现
////    doBuy(s);   // 学生调用派生类实现
////    doBuy(so);  // 军人调用派生类实现
////
////    return 0;
////}
#include <iostream>
using namespace std;
//
//class Person {
//public:
//    virtual void buyTicket() {
//        cout << "普通人：全价买票" << endl;
//    }
//};
//
//class Student : public Person {
//public:
//    // ✅ 派生类没写 virtual，但依然构成重写
//    // 因为基类的虚函数属性会被继承下来
//    void buyTicket() override { // override 关键字依然有效
//        cout << "学生：半价买票" << endl;
//    }
//};
//
//int main() {
//    Person* p = new Student();
//    p->buyTicket(); // 依然触发多态，输出“学生：半价买票” ✅
//    delete p;
//    return 0;
//}
class Person {
public:
    void buyTicket() { // 基类：不是虚函数
        cout << "普通人：全价买票" << endl;
    }
};

class Student : public Person {
public:
    void buyTicket() { // 派生类：同名同参数，但只是隐藏，不是重写
        cout << "学生：半价买票" << endl;
    }
};

int main() {
    Person* p = new Student();
    p->buyTicket(); // ❌ 调用基类版本，不触发多态
    delete p;
}