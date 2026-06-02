//#include <iostream>
//#include <unordered_map>
//#include <string>
//using namespace std;
//
//void TestUnorderedMap()
//{
//     1. 定义一个键为int、值为string的无序映射
//    unordered_map<int, string> um;
//
//     方式1：使用insert插入键值对
//    um.insert(make_pair(1, "张三"));
//    um.insert(make_pair(2, "李四"));
//
//     方式2：使用[]运算符（最常用）
//     如果key不存在，则插入新的键值对；如果存在，则修改对应的值
//    um[3] = "王五";   // key=3不存在，插入
//    um[2] = "李四改名"; // key=2已存在，修改其值
//
//     2. 遍历容器：遍历键值对
//    cout << "unordered_map 遍历结果：" << endl;
//    for (auto& kv : um)
//    {
//         kv是pair类型，first是key，second是value
//        cout << kv.first << " -> " << kv.second << endl;
//    }
//
//     3. 查找元素：通过key查找
//    auto it = um.find(3);
//    if (it != um.end())
//    {
//        cout << "找到key=3，对应value：" << it->second << endl;
//    }
//
//     4. 删除元素：通过key删除
//    um.erase(3);
//    cout << "删除key=3后：" << endl;
//    for (auto& kv : um)
//    {
//        cout << kv.first << " -> " << kv.second << endl;
//    }
//}
//
//int main()
//{
//    TestUnorderedMap();
//    return 0;
//}
#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // 设定测试数据量：100万条
    const size_t N = 1000000;

    unordered_set<int> us;
    set<int> s;
    vector<int> v;
    v.reserve(N);

    // 设置随机数种子
    srand(time(0));

    // 生成测试数据
    for (size_t i = 0; i < N; ++i)
    {
        v.push_back(rand() + i); // 降低数据重复率
    }

    // ---------------- 插入性能测试 ----------------
    size_t begin1 = clock();
    for (auto e : v) s.insert(e);
    size_t end1 = clock();
    cout << "set insert 耗时：" << end1 - begin1 << endl;

    us.reserve(N); // 提前预留空间，避免多次rehash
    size_t begin2 = clock();
    for (auto e : v) us.insert(e);
    size_t end2 = clock();
    cout << "unordered_set insert 耗时：" << end2 - begin2 << endl << endl;

    // ---------------- 查找性能测试 ----------------
    int m1 = 0, m2 = 0;
    size_t begin3 = clock();
    for (auto e : v) if (s.find(e) != s.end()) m1++;
    size_t end3 = clock();
    cout << "set find 耗时：" << end3 - begin3 << " 命中数：" << m1 << endl;

    size_t begin4 = clock();
    for (auto e : v) if (us.find(e) != us.end()) m2++;
    size_t end4 = clock();
    cout << "unordered_set find 耗时：" << end4 - begin4 << " 命中数：" << m2 << endl << endl;

    // ---------------- 删除性能测试 ----------------
    size_t begin5 = clock();
    for (auto e : v) s.erase(e);
    size_t end5 = clock();
    cout << "set erase 耗时：" << end5 - begin5 << endl;

    size_t begin6 = clock();
    for (auto e : v) us.erase(e);
    size_t end6 = clock();
    cout << "unordered_set erase 耗时：" << end6 - begin6 << endl;

    return 0;
}