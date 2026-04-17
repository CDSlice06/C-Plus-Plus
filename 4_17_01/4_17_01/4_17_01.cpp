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

//”≈ªØ
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left, right;
        int sum = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            left = 0, right = nums.size() - i;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[right + 1])
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

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, n = nums.size();
        for (int i = n - 1; i >= 2; i--)
        {
            int left = 0, right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
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