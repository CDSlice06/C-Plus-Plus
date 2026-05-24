#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (auto e : nums)
            total += e;
        int target = total - x;
        int sum = 0, len = -1, n = nums.size();
        if (target < 0)return -1;
        for (int left, right = 0; right < n; right++)
        {
            sum += nums[right];
            while (sum > target)
                sum -= nums[left++];
            if (sum == target)
                len = max(len, right - left + 1);
        }
        if (len == -1)return len;
        else return n - len;
    }
};