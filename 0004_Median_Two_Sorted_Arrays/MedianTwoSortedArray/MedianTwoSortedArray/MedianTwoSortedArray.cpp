// MedianTwoSortedArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	// �൱���ҵ���K������顣һ��ʼ�벻�������������𰸷ֳ�2/k����Ȼ����. 
	// ����Ĵ���C++��beats 88.78%
	// @todo ���Կ��ǵ��Ż����⿪�������á�
	// @todo ��ż��������find�ĳ�һ��
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		size_t total = nums1.size() + nums2.size();
		if ( (total%2) == 0 )
		{
			// ż�����������м�ֵ������8�������ҵ�4��͵�5��
			double m1 = FindOrderK(&(nums1[0]), nums1.size(), &(nums2[0]), nums2.size(), total / 2);
			double m2 = FindOrderK(&(nums1[0]), nums1.size(), &(nums2[0]), nums2.size(),  (total / 2) + 1 );
			return (m1 + m2) / 2;
		}
		else
		{
			// ��������һ���м�ֵ������7�������ҵ���4��Ϳ����ˡ�
			return FindOrderK(&(nums1[0]), nums1.size(), &(nums2[0]), nums2.size(), (total + 1) / 2);
		}
	}

	// �ҵ���k���. k����Ч������1��ʼȡ
	int FindOrderK(int* nums1, int nums1_max_K, int* nums2, int nums2_max_K, int k)
	{
		// ���������Ϊ�˱�֤�������㷨һ�������ҵ�һ����ֵ������Խ���ж�
		if (nums2_max_K > nums1_max_K)
		{
			return FindOrderK(nums2, nums2_max_K, nums1, nums1_max_K, k);
		}

		// nums2 ����
		if (nums2_max_K <= 0)
		{
			return nums1[k - 1];
		}

		if (k == 1)
		{
			return std::min(*nums1, *nums2);
		}

		// nums1һ����nums2��
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
			// val_in_nums2 ֮ǰ�Ķ����Զ���
			return FindOrderK(nums1, nums1_max_K, 
				nums2 + findOrderInNums2, nums2_max_K - findOrderInNums2, 
				findOrderInNums1);
		}
		else 
		{
			// val_in_nums1 <   val_in_nums2
			// val_in_nums1 ֮ǰ�Ķ���
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

