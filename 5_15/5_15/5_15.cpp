#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();
        for (int a = 0; a < n;)
        {

            for (int b = a + 1; b < n;)
            {

                int c = b + 1, d = n - 1;

                while (c < d)
                {
                    long Sum = nums[c] + nums[d];
                    if (Sum > target - (long)nums[a] - (long)nums[b])d--;
                    else if (Sum < target - (long)nums[a] - (long)nums[b]) c++;
                    else
                    {
                        ret.push_back({ nums[a],nums[b],nums[c],nums[d] });
                        c++, d--;
                        while (c < d && nums[c] == nums[c - 1])c++;
                        while (c < d && nums[d] == nums[d + 1])d--;
                    }
                }
                b++;
                while (b < n && nums[b] == nums[b - 1])b++;
            }
            a++;
            while (a < n && nums[a] == nums[a - 1])a++;

        }
        return ret;

    }
};