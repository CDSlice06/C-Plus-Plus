#include <iostream>
#include <string>
#include <utility>   // std::move 头文件
using namespace std;

int main()
{
    int b = 1;
    int* p = new int(0);
    string s("111111");

    // ========== 1. 普通左值引用 T&  ==========
    int& r1 = b;         // 合法：绑定普通左值
    int*& r2 = p;        // 合法：绑定指针左值
    int& r3 = *p;        // 合法：绑定解引用后的左值
    string& r4 = s;      // 合法：绑定字符串左值

    // 错误示例：普通左值引用 不能绑定右值（取消注释编译报错）
    // int& rx_err = 10;

    // ========== 2. const 左值引用 const T& ==========
    const int& rx1 = 10;                // 合法：绑定字面量右值
    const double& rx2 = 1.1 + 2.2;      // 合法：绑定表达式右值
    const string& rx4 = string("temp"); // 合法：绑定匿名临时对象

    // ========== 3. 右值引用 T&& ==========
    int&& rr1 = 10;                     // 合法：绑定字面量右值
    double&& rr2 = 1.1 + 2.2;           // 合法：绑定表达式右值
    string&& rr4 = string("temp");      // 合法：绑定匿名临时对象

    // 错误示例：右值引用 不能直接绑定左值（取消注释编译报错）
    // int&& rrx_err = b;

    // ========== 4. std::move：左值转右值 ==========
    int&& rrx1 = move(b);    // move 将左值转为右值，合法绑定
    int*&& rrx2 = move(p);
    string&& rrx4 = move(s);

    // ========== 5. 易错点：右值引用变量本身是左值 ==========
    // int&& rrx6 = rr1;   // 报错：rr1 是具名左值，不能直接绑定
    int&& rrx6 = move(rr1); // 解决方案：再次 move 转为右值

    // 验证：所有具名变量都可以取地址（左值特征）
    cout << "变量b 地址：" << &b << endl;
    cout << "左值引用r1 地址：" << &r1 << endl;
    cout << "右值引用rr1 地址：" << &rr1 << endl;

    // ========== 6. 引用延长临时对象生命周期 ==========
    string s1 = "Test";
    const string& r2 = s1 + s1;  // const引用延长生命周期，只读
    cout << "const引用延长对象：" << r2 << endl;

    string&& r3 = s1 + s1;       // 右值引用延长生命周期，可修改
    r3 += "Test";
    cout << "右值引用延长对象：" << r3 << '\n';

    delete p;
    return 0;
}