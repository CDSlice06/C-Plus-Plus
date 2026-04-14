#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//排序法
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here
        sort(numbers.begin(), numbers.end());
        int middle = numbers[numbers.size() / 2];
        int count = 0;
        for (auto n : numbers)
            if (n == middle)count++;
        if (count > numbers.size() / 2)return middle;
        return 0;

    }
};
//方法二
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int cond = -1;
        int cnt = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (cnt == 0) {
                cond = numbers[i];
                ++cnt;
            }
            else {
                if (cond == numbers[i]) ++cnt;
                else --cnt;
            }

        }
        cnt = 0;
        for (const int k : numbers) {
            if (cond == k) ++cnt;
        }
        if (cnt > numbers.size() / 2) return cond;
        return 0;
    }
};
