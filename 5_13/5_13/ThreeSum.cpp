#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



//class Solution
//{
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> arr;
//        if (nums.size() == 0)
//            return arr;
//        sort(nums.begin(), nums.end());
//        int fix = 0;
//        while (fix < nums.size() - 4)
//        {
//            while (1)
//            {
//                if (fix > 0 && nums[fix] == nums[fix - 1])
//                    fix++;
//            }
//            int left = fix + 1, right = nums.size() - 1;
//            while (left < right)
//            {
//                int Sum = nums[left] + nums[right] + nums[fix];
//                if (Sum < 0) left++;
//                else if (Sum > 0) right--;
//                else
//                {
//                    arr.push_back({ nums[left],nums[fix],nums[right] });
//                    left++;
//                    while (left < right && nums[left] == nums[left + 1]) left++;
//                    right--;
//                    while (left < right && nums[right] == nums[right - 1]) right--;
//                }
//            }
//        }
//    };

/