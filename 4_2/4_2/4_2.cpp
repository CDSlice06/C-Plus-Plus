#include<iostream>
#include<string>
using namespace std;
#include <algorithm> 
//class Solution {
//public:
//    bool isPalindrome(string s)
//    {
//        string tmp;
//        for (auto e : s)
//        {
//            if (isalnum(e))
//            {
//                tmp += tolower(e);
//            }
//
//        }
//        int left = 0, right = tmp.size() - 1;
//        while (left <= right)
//        {
//            if (tmp[left++] != tmp[right--])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
class Solution {
public:
    string reverseStr(string s, int k)
    {
        int n = s.size() / (2 * k);
        int r = s.size() % (2 * k);
        int i = 0;
        for(int j=n;j>0;j--)
        {
            int left = i, right = i + k - 1;
            while (left < right)
            {
                swap(s[left++], s[right--]);
            }
            i += (2 * k);
        }
        if (r == 0)
            return s;
        int left = i, right = s.size() - 1;
        if (r < k)
        {
            while (left < right)
                swap(s[left++], s[right--]);
            return s;
        }
        else
        {
            right = left + k - 1;
                while (left < right)
                    swap(s[left++], s[right--]);
                return s;
        }
    }
};
int main()
{
    Solution a;
    //cout << a.reverseStr("abcd", 2) << endl;
    cout << a.reverseStr("abcdefg", 2) << endl;
    return 0;
}