#include<iostream>
#include<string>
using namespace std;
#include<vector>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = { 0 };
        int left = 0, right = 0, n = s.size();
        int len = 0;
        while (right < n)
        {
            hash[s[right]]++;
            while (hash[s[right]] > 1)
                hash[s[left++]]--;
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
//第一次尝试
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zero = 0, len = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            if (nums[right] == 0)
                zero++;
            while (zero > k)
                if (nums[left++] == 0)
                    zero--;
            len = max(len, right - left + 1);
        }
        return len;
    }
};
//第二次尝试
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0;
        for (int left = 0, right = 0,zero=0; right < nums.size(); right++)
        {
            if (nums[right] == 0)zero++;
            while (zero > k)
                if (nums[left++] == 0)zero--;
            len = max(len, right - left + 1);
        }
        return len;
    }
};