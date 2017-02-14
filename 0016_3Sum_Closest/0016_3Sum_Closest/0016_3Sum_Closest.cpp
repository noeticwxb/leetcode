// 0016_3Sum_Closest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
	// beats 89.04
	int threeSumClosest(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		int result = nums[0] + nums[1] + nums[2];

		for (size_t firstIndex = 0; firstIndex < nums.size() - 2; ++firstIndex)
		{
			int first_num = nums[firstIndex]; 

			size_t secondIndex = firstIndex + 1;
			size_t thirdIndex = nums.size() - 1;

			while (secondIndex < thirdIndex)
			{
				int total = first_num + nums[secondIndex] + nums[thirdIndex];
				if (std::abs(target-total) <= std::abs(target - result ) )
				{
					result = total;
					if (result == target)
					{
						return result;
					}
				}

				if (total > target)
				{
					--thirdIndex;
				}
				else
				{
					++secondIndex;
				}
			}

		}

		return result;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution soulution;
	vector<int> vec1 = { -1, 2, 1, - 4 };

	std::cout << soulution.threeSumClosest(vec1, 1);

	char ch;
	std::cin >> ch;

	return 0;
}

