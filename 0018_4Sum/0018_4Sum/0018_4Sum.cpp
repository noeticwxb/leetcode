// 0018_4Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef size_t INDEX;
// beats 79.54%
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result; 
		result.reserve(nums.size());

		vector<int> quadruplets;
		quadruplets.resize(4);

		if (nums.size() < 4 )
		{
			return result;
		}

		std::sort(nums.begin(), nums.end());

		INDEX first = 0;

		const INDEX first_end = nums.size() - 3;
		const INDEX second_end = nums.size() - 2;	
		const INDEX third_end = nums.size() - 1;

		while (first < first_end)
		{
			int three_target = target - nums[first];

			INDEX second = first+1;		
			while (second < second_end)
			{						
				int two_target = three_target - nums[second];

				INDEX third = second + 1;
				INDEX fouth = nums.size() - 1;

				while (third < fouth)
				{
					int sum = nums[third] + nums[fouth];
					if (sum < two_target)
					{
						++third;
					}
					else if ( sum > two_target)
					{
						--fouth;
					}
					else
					{
						// find a quadruplet that nums[first] + nums[second]+ nums[third] + nums[fouth] = target
						quadruplets[0] = nums[first];
						quadruplets[1] = nums[second];
						quadruplets[2] = nums[third];
						quadruplets[3] = nums[fouth];
						result.push_back(quadruplets);

						// remove repeat 
						while (third + 1 < fouth && nums[third + 1] == quadruplets[2])
						{
							++third;
						}

						while (second + 1 < third && nums[second + 1] == quadruplets[1])
						{
							++second;
						}

						while (first + 1 < second && nums[first + 1] == quadruplets[0])
						{
							++first;
						}

						// 在first，second相同的情况下，third和fouth可能有不同的组合
						//break;
						++third;
					}
				}

				++second;
			}
			++first;
		}

		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	//vector<int> input = { 1, 0, -1, 0, -2, 2 };
	vector<int> input = { -3, -2, -1, 0, 0, 1, 2, 3 };
	int target = 0;
	Solution solution;
	auto ret = solution.fourSum(input, target);
	for (auto retItem : ret)
	{
		for (auto i:retItem)
		{
			cout << i << " ";
		}
		cout << std::endl;
	}

	char ch;
	cin >> ch;

	return 0;
}

