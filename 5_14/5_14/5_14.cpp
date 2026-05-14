#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();)
        {
            if (nums[i] > 0)break;
            int left = i + 1, right = nums.size() - 1, target = -nums[i];
            while (left < right)
            {
                int Sum = nums[left] + nums[right];
                if (Sum < target) left++;
                else if (Sum > target) right--;
                else
                {
                    arr.push_back({ nums[left],nums[i],nums[right] });
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;
        }

        return arr;

    }
};
