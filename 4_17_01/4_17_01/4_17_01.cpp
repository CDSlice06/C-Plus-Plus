#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left, right;
        int sum = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            left = 0, right = nums.size() - i;
            int max = nums[right + 1];
            while (left < right)
            {
                if (nums[left] + nums[right] > max)
                {
                    sum += right - left;
                    right--;
                }
                else left++;
            }
        }
        return sum;
    }
};