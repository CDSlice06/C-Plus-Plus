#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int x = num1.size() - 1, y = num2.size() - 1, add = 0;
        string tmp = "";
        while (x >= 0 || y >= 0 || add != 0)
        {
            int i = x >= 0 ? num1[x] - '0' : 0;
            int j = y >= 0 ? num2[y] - '0' : 0;
            int result = i + j + add;
            tmp.push_back(result % 10 + '0');
            add = result / 10;
            x -= 1;
            y -= 1;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};