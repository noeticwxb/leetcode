// 0008_String_To_Integer.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
	// betas 96.93%
	// 个人感觉还是题目没说清楚。比如overflow之后是应该返回0还是返回max或者min。害的提交了好几次。
	int myAtoi(const string& str) {
		int result = 0;
		bool beginConvert = false;
		int isNegtive = 1;
		for (string::const_iterator itor = str.begin(); itor != str.end(); ++itor)
		{
			if (*itor == '+')
			{
				if (beginConvert)
				{
					return result;
				}
				else
				{
					beginConvert = true; 
				}
			}
			else if (*itor == '-')
			{
				if (beginConvert)
				{
					return result;
				}
				else
				{
					beginConvert = true;
					isNegtive = -1;
				}
			}
			else if ( *itor >= '0' && *itor <= '9')
			{
				if (!beginConvert)
				{
					beginConvert = true;
				}

				int tempShift = result * 10;
				if (result != tempShift / 10)
				{
					if (result > 0)
					{
						return std::numeric_limits<int>::max();
					}
					else
					{
						return std::numeric_limits<int>::min();
					}
				}

				int toAdd = *itor - '0';
				toAdd *= isNegtive;

				if (toAdd > 0 && (std::numeric_limits<int>::max() - tempShift) < toAdd)
				{
					return std::numeric_limits<int>::max();
				}

				if (toAdd < 0 && (std::numeric_limits<int>::min() - tempShift) > toAdd)
				{
					return std::numeric_limits<int>::min();
				}

				result = tempShift + toAdd;
			}
			else if (*itor == ' ' )
			{
				if (beginConvert)
				{
					return result;
				}
			}
			else
			{
				return result;
			}
		}

		return result ;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	string test_1 = "+11112";
	std::cout << test_1 << " " << solution.myAtoi(test_1) << std::endl;

	string test_2 = "-11112";
	std::cout << test_2 << " " << solution.myAtoi(test_2) << std::endl;

	string test_3 = "00000122";
	std::cout << test_3 << " " << solution.myAtoi(test_3) << std::endl;

	string test_4 = "      -11919730356x";
	std::cout << test_4 << " " << solution.myAtoi(test_4) << std::endl;

	char ch;
	std::cin >> ch;
	return 0;
}

