#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
//第一次尝试
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> S;
        int len = 0, n = s.size();
        for (int left = 0, right = 0; right < n; right++)
        {
            if (S.find(s[right]) != S.end())
            {
                left = S.find(s[right])->second;
                for (int i = 0; i < left; i++)
                {
                    S.erase(s[i]);
                }
                left++;

            }
            S.insert({ s[right],right });
            len = max(right - left + 1, len);
        }
        return len;
    }
};
//第二次尝试