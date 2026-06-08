//#include <iostream>
//using namespace std;
//
//int main() {
//    int a = 10;  // a 是左值
//
//    // 左值引用：绑定左值
//    int& ref = a;
//    ref = 20;    // 修改引用 = 修改原变量
//
//    cout << a << endl;   // 输出 20
//    cout << &a << endl;  // 和 ref 地址一样
//    cout << &ref << endl;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    // 右值引用：绑定临时值（右值）
//    int&& rref = 10;
//
//    rref = 20;  // 临时值被“续命”了，可以修改
//
//    cout << rref << endl;  // 输出 20
//}
void func(int& x) {
    x = 100;
}

int main() {
    int a = 1;
    func(a);    // 左值可以传
    // func(10); // 临时值不能传
}
void func(int&& x) {
    x = 100;
}

int main() {
    // func(a); //  左值不能传
    func(10);   //  临时值可以传
}