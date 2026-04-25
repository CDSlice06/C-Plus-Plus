#include <iostream>
using namespace std;

//class A {
//public:
//    ~A() { // 基类析构函数 不加 virtual
//        cout << "调用 ~A()" << endl;
//    }
//};
//
//class B : public A {
//public:
//    ~B() {
//        cout << "调用 ~B()" << endl;
//    }
//};
//
//int main() {
//    A* p = new B(); // 基类指针指向派生类对象
//    delete p;       // 直接 delete 基类指针
//    return 0;
//}

class A {
public:
    virtual ~A() { // 基类析构函数 加 virtual
        cout << "调用 ~A()" << endl;
    }
};

class B : public A {
public:
    ~B() override { // 自动构成重写，加 override 更规范
        cout << "调用 ~B()" << endl;
    }
};

int main() {
    A* p = new B();
    delete p;
    return 0;
}