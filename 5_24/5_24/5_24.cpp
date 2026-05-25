#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//第一次尝试
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        int ret = 0, sum = 0;
        for (int left = 0, right = 0; right < fruits.size(); right++)
        {
            hash[fruits[right]]++;
            while (hash.size() > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0)
                    hash.erase(fruits[left]);
                left++;
            }
            if (hash.size() == 2 || hash.size() == 1)
                ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

//第一次优化
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        int ret = 0, sum = 0;
        for (int left = 0, right = 0; right < fruits.size(); right++)
        {
            hash[fruits[right]]++;
            while (hash.size() > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0)
                    hash.erase(fruits[left]);
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};
//第二次优化
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int hash[100001] = { 0 };
        int ret = 0;
        for (int left = 0, right = 0, kinds = 0; right < fruits.size(); right++)
        {
            if (hash[fruits[right]] == 0)kinds++;
            hash[fruits[right]]++;
            while (kinds > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0)kinds--;
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};
