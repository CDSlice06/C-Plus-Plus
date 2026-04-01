#include<iostream>
#include<string>
#include <algorithm> 
using namespace std;
//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        int left = 0, right = s.size() - 1;
//        while (left < right)
//        {
//            swap(s[left++], s[right--]);
//        }
//    }
//};

    bool isPalindrome(string s)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] < 65 || s[i]>90 && s[i] < 97 || s[i]>122)
            {
                s[i] = ' ';
            }
            else
            {
                s[i] = tolower(s[i]);
            }
        }
        s = remove(s.begin(), s.end(), ' ');
        size_t left = 0, right = s.size() - 1;
        while (left <= right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;


    }
void test()
{
    bool ret=isPalindrome("A man, a plan, a canal: Panama");
    cout << ret << endl;
}
int main()
{
    test();
  
    return 0;
}
//string s;
  //getline(cin, s);
  //int cur = 0, dest = 0;
  //for (; cur < s.size(); cur++)
  //{
  //    if (!s[cur])
  //    {
  //        dest = cur + 1;
  //    }
  //}
  //cout << s.size() - dest << endl;