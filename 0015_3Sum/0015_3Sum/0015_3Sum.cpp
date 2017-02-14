// 0015_3Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	// beats 9.8%. 想不通，我觉得这样写的算法效率还可以啊。难道要用hash去做?
	// 加了reserve之后，到23%
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		result.reserve(nums.size()/3);
		size_t count = nums.size();
		if (count <= 2 )
		{
			return result;
		}
		std::sort(nums.begin(), nums.end());

		for (size_t iLoop = 0; iLoop < count - 2;++iLoop)
		{
			int triplet_1 = nums[iLoop];
			int target = 0-triplet_1;

			size_t iBegin = iLoop + 1;
			size_t iEnd = count - 1;
			while (iBegin < iEnd)
			{
				int triplet_2 = nums[iBegin];
				int triplet_3 = nums[iEnd];
				int total = triplet_2 + triplet_3;
				if (target > total)
				{
					++iBegin;
				}
				else if (target < total)
				{
					--iEnd;
				}
				else
				{
					result.push_back({ triplet_1, triplet_2, triplet_3 });

					while ((iBegin + 1 < iEnd)
						&& triplet_2 == nums[iBegin + 1])
					{
						++iBegin;
					}

					while( (iEnd - 1 > iBegin)
						&& triplet_3 == nums[iEnd - 1] )
					{
						--iEnd;
					}

					while ((iLoop + 1 < iBegin)
						&& triplet_1 == nums[iLoop + 1])
					{
						++iLoop;
					}

					++iBegin;
					--iEnd;
				}
			}

		}

		return result;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	//vector<int> nums = { -1, 0, 1, 2, -1, -1, -4 };
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	//vector<int> nums = { 0,0,0,0 };
	//vector<int> nums = { -2, 0, 1, 1, 2 };

	Solution solution;
	auto result = solution.threeSum(nums);

	for (auto triplet: result)
	{
		for (auto item: triplet)
		{
			cout << item << " ";
		}
		cout << endl;
	}

	char ch;
	cin >> ch;

	return 0;
}

