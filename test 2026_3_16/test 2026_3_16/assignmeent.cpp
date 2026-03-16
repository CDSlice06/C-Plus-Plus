#include<iostream>
using namespace std;
class Solution {
public:
    class Sum
    {
    public:
        Sum()
        {
            _ret += _i;
            ++_i;
        }
    };
    static int _ret;
    static int _i;
public:
    int Sum_Solution(int n)
    {
        Sum* arr= new Sum[n];
        delete[]arr;
        return _ret;
    }
};
int Solution::_ret = 0;
int Solution::_i = 1;

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.Sum_Solution(n) << endl;
}