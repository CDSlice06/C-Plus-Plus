#include<iostream>
#include<vecotr>
using namespace std;
int compare(int a, int b)
{
    return a > b ? b : a;
}
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, tmp = 0;
        int min = compare(height[left], height[right]);
        int max = min * (right - left);
        while (left < right)
        {
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
            min = compare(height[left], height[right]);
            tmp = min * (right - left);
            if (tmp > max)
                max = tmp;
        }
        return max;
    }
};