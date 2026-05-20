#include<iostream>
#include<vector>
//第二次修改
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        int sum = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                len = min(len, right - left + 1);
                sum -= nums[left++];
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};
//第一次尝试

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        int left = 0, right = 0;
        int sum = nums[0];
        while (right < n)
        {
            for (; right < n;)
            {
                if (sum >= target)
                {
                    int tmp_len = right - left + 1;
                    if (tmp_len < len)
                        len = tmp_len;
                    sum -= nums[left++];
                }
                else
                {
                    right++;
                    if (right < n)
                        sum += nums[right];
                }
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};