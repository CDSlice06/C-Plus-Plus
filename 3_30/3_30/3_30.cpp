#include<iostream>
#include<string>
using namespace std;
//字符串翻转问题
//方法一:开辟额外空间
class Solution {
public:
    string reverseWords(string s) {
        string tmp;
        int i = 0;
        while (s[i] != '\0')
        {
            int begin = i;
            while (i < s.size() && s[i] != ' ')
                i++;
            for (int j = i - 1; j >= begin; j--)
            {
                tmp.push_back(s[j]);
            }
            while (i < s.size() && s[i] == ' ')
            {
                i++;
                tmp.push_back(' ');
            }
        }
        return tmp;
    }
};
//方法二:左右区间法
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (i < s.size())
        {
            int left = i;
            while (i < s.size() && s[i] != ' ')
            {
                i++;
            }
            int right = i - 1;
            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            while (i < s.size() && s[i] == ' ')
            {
                i++;
            }

        }
        return s;
    }
};