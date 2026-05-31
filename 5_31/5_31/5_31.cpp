#include <iostream>
#include <unordered_set>
using namespace std;

void TestUnorderedSet()
{
    // 1. 定义一个存储int类型的无序集合
    unordered_set<int> us;

    // 2. 插入元素：重复的元素会被自动忽略
    us.insert(5);
    us.insert(2);
    us.insert(8);
    us.insert(5); // 插入失败，因为5已经存在

    // 3. 遍历容器：注意，输出顺序是无序的
    cout << "unordered_set 遍历结果：";
    for (auto val : us)
    {
        cout << val << " ";
    }
    cout << endl;

    // 4. 查找元素：find()返回迭代器，找到则指向该元素，否则返回end()
    auto it = us.find(2);
    if (it != us.end())
    {
        cout << "找到了元素：" << *it << endl;
    }
    else
    {
        cout << "未找到该元素" << endl;
    }

    // 5. 删除元素：可以通过值或迭代器删除
    us.erase(2);
    cout << "删除元素2后：";
    for (auto val : us)
    {
        cout << val << " ";
    }
    cout << endl;

    // 6. 获取容器大小和判空
    cout << "有效元素个数：" << us.size() << endl;
    cout << "容器是否为空：" << us.empty() << endl;
}

int main()
{
    TestUnorderedSet();
    return 0;
}