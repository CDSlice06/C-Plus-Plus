#include<iostream>
#include<vector>
using namespace std;
int compare(int a, int b)
{
    return a > b ? b : a;
}
//方法一
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
//优化,调用库里的比较大小
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, tmp = 0;
        while (left < right)
        {
            int maxi = min(height[left], height[right]) * (right - left);
            tmp = max(tmp, maxi);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return tmp;
    }
};