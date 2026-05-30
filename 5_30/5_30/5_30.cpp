//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//int main()
//{
//    map<string, string> dict;
//
//     1. key不存在：插入+赋值
//    dict["left"] = "左边";
//     2. key存在：修改value
//    dict["left"] = "左边、剩余";
//     3. 只访问不赋值：插入空默认值
//    dict["insert"];
//
//     4. 单词查找
//    string str;
//    while (cin >> str)
//    {
//        auto ret = dict.find(str);
//        if (ret != dict.end())
//            cout << "翻译：" << ret->second << endl;
//        else
//            cout << "无此单词" << endl;
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
    string arr[] = { "苹果", "西瓜", "苹果", "香蕉", "苹果", "西瓜" };
    map<string, int> countMap;

    // 一行代码完成统计
    for (const auto& str : arr)
    {
        countMap[str]++;
        // 原理：不存在则插入默认0，再++；存在则直接++
    }

    // 遍历输出统计结果
    for (const auto& e : countMap)
    {
        cout << e.first << " 出现次数：" << e.second << endl;
    }

    return 0;
}