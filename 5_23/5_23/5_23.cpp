#include<iostream>
#include<vector>
using namespace std;
//µÚÒ»´Î³¢ÊÔ
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (auto e : nums)
            total += e;
        int left = 0, right = 0, target = total - x;
        int sum = 0, len = 0, n = nums.size();
        while (right < n)
        {
            sum += nums[right++];
            if (sum > target)
            {
                sum -= nums[left++];
                if (sum == target)
                    len = max(len, right - left + 1);
                if (sum < target)
                    right++;

            }
            if (sum == target)
                len = max(len, right - left + 1);

        }
        return n - len;
    }
};