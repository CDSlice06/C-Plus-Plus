#pragma once
#include<vector>
#include<iostream>
using namespace std;
//
//enum State
//{
//	EXIST,
//	EMPTY,
//	DELETE
//};
//
//template<class k,class v>
//struct HashData
//{
//	pair<k, v> _kv;
//	State _state = EMPTY;
//};
//
//template<class k, class v>
//class HashTable
//{
//public:
//	HashTable()
//	{
//		:_table(_stl_next_prime(0))
//	}
//private:
//	vector<HashData<k, v>> _table;
//	size_t _n;
//};
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left<right)
		{
			int Sum = nums[left] + nums[right];
			if (Sum < target)
				left++;
			else if (Sum > target)
				right--;
			else
				return { nums[left],nums[right] };
		}
		return { -1,-1 };
	}
};
int main()
{
	cout << "helloworld" << endl;
}