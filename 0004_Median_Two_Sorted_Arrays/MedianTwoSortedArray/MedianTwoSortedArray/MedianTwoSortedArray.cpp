// MedianTwoSortedArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	// 相当于找到第K大的数组。一开始想不起来，后来看答案分成2/k，焕然大悟. 
	// 下面的答案在C++是beats 88.78%
	// @todo 可以考虑的优化，解开函数调用。
	// @todo 把偶数的两个find改成一个
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		size_t total = nums1.size() + nums2.size();
		if ( (total%2) == 0 )
		{
			// 偶数，找两个中间值。比如8个数，找第4大和第5大
			double m1 = FindOrderK(&(nums1[0]), nums1.size(), &(nums2[0]), nums2.size(), total / 2);
			double m2 = FindOrderK(&(nums1[0]), nums1.size(), &(nums2[0]), nums2.size(),  (total / 2) + 1 );
			return (m1 + m2) / 2;
		}
		else
		{
			// 奇数，找一个中间值。比如7个数，找到第4大就可以了。
			return FindOrderK(&(nums1[0]), nums1.size(), &(nums2[0]), nums2.size(), (total + 1) / 2);
		}
	}

	// 找到第k大的. k的有效索引从1开始取
	int FindOrderK(int* nums1, int nums1_max_K, int* nums2, int nums2_max_K, int k)
	{
		// 这个交换是为了保证后来的算法一定可以找到一个的值，避免越界判断
		if (nums2_max_K > nums1_max_K)
		{
			return FindOrderK(nums2, nums2_max_K, nums1, nums1_max_K, k);
		}

		// nums2 空了
		if (nums2_max_K <= 0)
		{
			return nums1[k - 1];
		}

		if (k == 1)
		{
			return std::min(*nums1, *nums2);
		}

		// nums1一定比nums2大
		int findOrderInNums2 = std::min<int>(nums2_max_K, k / 2);
		int findOrderInNums1 = k - findOrderInNums2;

		int val_in_nums1 = nums1[findOrderInNums1 - 1];
		int val_in_nums2 = nums2[findOrderInNums2 - 1];

		if ( val_in_nums1==val_in_nums2)
		{
			return val_in_nums1;
		}
		else if ( val_in_nums1 > val_in_nums2)
		{
			// val_in_nums2 之前的都可以丢掉
			return FindOrderK(nums1, nums1_max_K, 
				nums2 + findOrderInNums2, nums2_max_K - findOrderInNums2, 
				findOrderInNums1);
		}
		else 
		{
			// val_in_nums1 <   val_in_nums2
			// val_in_nums1 之前的丢掉
			return FindOrderK(nums1 + findOrderInNums1, nums1_max_K - findOrderInNums1,
				nums2, nums2_max_K,
				findOrderInNums2);
		}


	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution soluton;
	{
		vector<int> nums1 = { 1, 3 };
		vector<int> nums2 = { 2 };

		double d = soluton.findMedianSortedArrays(nums1, nums2);
		cout << d << endl;
	}

	{
		vector<int> nums1 = { 1, 2 };
		vector<int> nums2 = { 3, 4 };

		double d = soluton.findMedianSortedArrays(nums1, nums2);
		cout << d << endl;
	}

	char ch;
	cin >> ch;

	return 0;
}

