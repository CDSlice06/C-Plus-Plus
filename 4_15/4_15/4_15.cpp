#include<iostream>
using namespace std;
class Solution {
public:
    int Sum(int n)
    {
        int sum = 0;
        while (n)
        {
            int k = n % 10;
            sum += k * k;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = Sum(n);
        while (slow != fast)
        {
            slow = Sum(slow);
            fast = Sum(Sum(fast));
        }
        return slow == 1;
    }
};