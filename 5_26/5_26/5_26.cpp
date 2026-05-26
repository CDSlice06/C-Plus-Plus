#include<iostream>
#include<vector>
#include<string>
using namespace std;
//µÚÒ»´Î³¢ÊÔ
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26] = { 0 }, hash2[26] = { 0 }, len = 0, count = 0;
        vector<int> array;
        for (auto i : p)
            hash1[i]++;
        for (int left = 0,right = 0; right < s.size(); right++)
        {
            hash2[s[right]]++;
            if (hash2[s[right]] == 1)
                count++;
            len = right - left + 1;
            if (len == p.size())
            {
                if (count == p.size())
                    array.push_back(left);
            }

            if (len > p.size())
            {
                hash2[left++]--;
            }
        }
        return array;
    }
};