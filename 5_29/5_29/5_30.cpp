//////////#include <iostream>   // 标准输入输出头文件，用于cout、cin
//////////#include <set>      // STL set容器头文件
//////////#include <map>      // STL map容器头文件
//////////#include <typeinfo> // 类型信息头文件，用于获取变量/对象的类型（typeid使用）
//////////using namespace std;
////////
//////////int main()
//////////{
//////////    // ------------------------------
//////////    // 1. 验证 set 的纯 key 模型
//////////    // set特点：元素唯一、自动排序、底层红黑树、元素只读不可修改
//////////    // ------------------------------
//////////    cout << "===== set 纯 key 模型验证 =====" << endl;
//////////    // 初始化set，自动去重+升序排序，重复的1会被过滤
//////////    set<int> s = { 3, 1, 4, 1, 5, 9, 2, 6 };
//////////    cout << "set 元素遍历（自动升序、无重复）：" << endl;
//////////    // 范围for遍历set，输出中序遍历结果（有序）
//////////    for (auto e : s)
//////////    {
//////////        cout << e << " ";
//////////    }
//////////    // 输出set有效元素个数
//////////    cout << "\nset 实际元素个数：" << s.size() << endl;
//////////
//////////    // 验证 set 元素不可修改（解开注释会编译报错）
//////////    // 原因：set元素底层被const修饰，修改会破坏红黑树结构
//////////    // *s.begin() = 100; 
//////////
//////////    // typeid获取迭代器解引用后的元素类型，name()输出类型名字
//////////    // 用于证明：set的元素是const类型，只读不可修改
//////////    cout << "set 元素类型：" << typeid(*s.begin()).name() << endl;
//////////
//////////    // ------------------------------
//////////    // 2. 验证 map 的 key-value 键值对模型
//////////    // map特点：key唯一、按key排序、key不可改、value可改、支持[]运算符
//////////    // ------------------------------
//////////    cout << "\n===== map 键值对模型验证 =====" << endl;
//////////    // 定义map：key是string(水果名)，value是int(数量)
//////////    map<string, int> cnt;
//////////    // []运算符：key不存在则插入默认值0，再++；存在则直接++
//////////    cnt["苹果"]++;
//////////    cnt["西瓜"]++;
//////////    cnt["苹果"]++;
//////////    // 直接赋值：key不存在则插入，存在则修改value
//////////    cnt["香蕉"] = 10;
//////////
//////////    cout << "map 键值对遍历（key升序，key唯一）：" << endl;
//////////    // 遍历map，kv是pair对象，kv.first=key，kv.second=value
//////////    for (auto& kv : cnt)
//////////    {
//////////        cout << kv.first << " : " << kv.second << endl;
//////////    }
//////////
//////////    // find查找key为"苹果"的节点，返回对应迭代器
//////////    auto it = cnt.find("苹果");
//////////    // 迭代器不等于end()，说明找到
//////////    if (it != cnt.end())
//////////    {
//////////        // it->first是key，被const修饰，不能修改（解开注释编译报错）
//////////        // it->first = "桃子"; 
//////////
//////////        // it->second是value，可以任意修改
//////////        it->second = 999;
//////////        cout << "修改后苹果的 value：" << it->second << endl;
//////////    }
//////////
//////////    // ------------------------------
//////////    // 3. 验证底层红黑树特性：高效查找 o(logn)
//////////    // set/map的find是红黑树二分查找，远快于线性遍历
//////////    // ------------------------------
//////////    cout << "\n===== 红黑树底层特性验证 =====" << endl;
//////////
//////////    // 在set中查找元素5，找到返回对应迭代器
//////////    if (s.find(5) != s.end())
//////////        cout << "set 中找到元素 5（红黑树 o(logn) 查找）" << endl;
//////////
//////////    // 在map中查找key为"香蕉"的节点
//////////    if (cnt.find("香蕉") != cnt.end())
//////////        cout << "map 中找到 key 为香蕉的节点（红黑树 o(logn) 查找）" << endl;
//////////
//////////    return 0;
//////////}
//////////
//////////
//////////
//////////int main()
//////////{
//////////    // 1. 无参默认构造
//////////    set<int> s1;
//////////
//////////    // 2. 迭代器区间构造
//////////    int arr[] = { 1,3,5,7 };
//////////    set<int> s2(arr, arr + sizeof(arr) / sizeof(int));
//////////
//////////    // 3. 拷贝构造
//////////    set<int> s3(s2);
//////////
//////////    // 4. 初始化列表构造（c++11）
//////////    set<int> s4 = { 2,4,6,8,2 }; // 自动去重
//////////
//////////    return 0;
//////////}
//////////#include <iostream>
//////////#include <set>
//////////#include <string>
//////////using namespace std;
//////////
//////////int main()
//////////{
//////////     1. 默认升序插入、去重
//////////    set<int> s;
//////////    s.insert(5);
//////////    s.insert(2);
//////////    s.insert(7);
//////////    s.insert(5); // 重复插入，无效
//////////
//////////     迭代器遍历
//////////    auto it = s.begin();
//////////    while (it != s.end())
//////////    {
//////////        cout << *it << " ";
//////////        ++it;
//////////    }
//////////    cout << endl;
//////////
//////////     2. 初始化列表批量插入
//////////    s.insert({ 2,8,3,9 });
//////////    for (auto e : s)
//////////    {
//////////        cout << e << " ";
//////////    }
//////////    cout << endl;
//////////
//////////     3. string类型按ASCII码排序
//////////    set<string> strset = { "sort", "insert", "add" };
//////////    for (auto& e : strset)
//////////    {
//////////        cout << e << " ";
//////////    }
//////////
//////////    return 0;
//////////}
////////#include <iostream>
////////#include <set>
////////#include <algorithm> // 算法库find
////////using namespace std;
////////
////////int main()
////////{
////////    set<int> s = { 4,2,7,2,8,5,9 };
////////    for (auto e : s) cout << e << " ";
////////    cout << endl;
////////
////////    // 1. 删除最小值（迭代器删除）
////////    s.erase(s.begin());
////////    for (auto e : s) cout << e << " ";
////////    cout << endl;
////////
////////    // 2. 按值删除
////////    int x = 7;
////////    int num = s.erase(x);
////////    if (num == 0)
////////        cout << x << " 不存在！" << endl;
////////    else
////////        cout << "删除成功" << endl;
////////
////////    // 3. 先查找再删除（推荐）
////////    cin >> x;
////////    auto pos = s.find(x);
////////    if (pos != s.end())
////////        s.erase(pos);
////////    else
////////        cout << x << " 不存在！" << endl;
////////
////////    // 4. set自带find O(logN)  VS  算法库find O(N)
////////    auto pos1 = find(s.begin(), s.end(), x); // 遍历查找
////////    auto pos2 = s.find(x);                  // 红黑树高效查找
////////
////////    // 5. count间接判断元素是否存在
////////    if (s.count(x))
////////        cout << x << " 存在！" << endl;
////////    else
////////        cout << x << " 不存在！" << endl;
////////
////////    return 0;
////////}
////////#include <iostream>
////////#include <set>
////////using namespace std;
////////
////////int main()
////////{
////////    set<int> myset;
////////    for (int i = 1; i < 10; i++)
////////        myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
////////
////////    for (auto e : myset) cout << e << " ";
////////    cout << endl;
////////
////////     找到 >=30 的位置
////////    auto itlow = myset.lower_bound(30);
////////     找到 >60 的位置
////////    auto itup = myset.upper_bound(60);
////////
////////     删除 [30,60] 区间所有元素
////////    myset.erase(itlow, itup);
////////
////////    for (auto e : myset) cout << e << " ";
////////    return 0;
////////}
//////#include <iostream>
//////#include <set>
//////using namespace std;
//////
//////int main()
//////{
//////    // multiset排序但不去重
//////    multiset<int> s = { 4,2,7,2,4,8,4,5,4,9 };
//////    for (auto e : s) cout << e << " ";
//////    cout << endl;
//////
//////    // 查找第一个4
//////    int x = 4;
//////    auto pos = s.find(x);
//////    // 遍历所有4
//////    while (pos != s.end() && *pos == x)
//////    {
//////        cout << *pos << " ";
//////        ++pos;
//////    }
//////    cout << endl;
//////
//////    // 统计4的个数
//////    cout << "4的个数：" << s.count(x) << endl;
//////
//////    // 删除所有4
//////    s.erase(x);
//////    for (auto e : s) cout << e << " ";
//////
//////    return 0;
//////}
////#include <iostream>
////#include <map>
////#include <string>
////using namespace std;
////
////int main()
////{
////    // 1. 无参构造
////    map<string, string> m1;
////
////    // 2. 初始化列表构造
////    map<string, string> m2 = { {"left", "左边"}, {"right", "右边"} };
////
////    // 3. 拷贝构造
////    map<string, string> m3(m2);
////
////    // 4. 迭代器区间构造
////    map<string, string> m4(m2.begin(), m2.end());
////
////    return 0;
////}
//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//int main()
//{
//    map<string, string> dict;
//
//    // 四种插入方式
//    // 方式1：创建pair对象插入
//    pair<string, string> kv1("first", "第一个");
//    dict.insert(kv1);
//
//    // 方式2：匿名pair对象插入
//    dict.insert(pair<string, string>("second", "第二个"));
//
//    // 方式3：make_pair插入
//    dict.insert(make_pair("sort", "排序"));
//
//    // 方式4：C++11列表初始化（最常用）
//    dict.insert({ "auto", "自动的" });
//
//    // 迭代器遍历
//    map<string, string>::iterator it = dict.begin();
//    while (it != dict.end())
//    {
//        // it->first 访问key，it->second访问value
//        cout << it->first << " : " << it->second << endl;
//        ++it;
//    }
//    cout << endl;
//
//    // 范围for遍历
//    for (const auto& e : dict)
//    {
//        cout << e.first << " : " << e.second << endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, string> dict;

    // 1. key不存在：插入+赋值
    dict["left"] = "左边";
    // 2. key存在：修改value
    dict["left"] = "左边、剩余";
    // 3. 只访问不赋值：插入空默认值
    dict["insert"];

    // 4. 单词查找
    string str;
    while (cin >> str)
    {
        auto ret = dict.find(str);
        if (ret != dict.end())
            cout << "翻译：" << ret->second << endl;
        else
            cout << "无此单词" << endl;
    }

    return 0;
}