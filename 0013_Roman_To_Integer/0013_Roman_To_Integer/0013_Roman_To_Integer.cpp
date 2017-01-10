// 0013_Roman_To_Integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;
/************************************************************************/
/*
罗马数字的编码方式：
I	V	X	L	Ｃ	Ｄ	Ｍ
1	5	10	50	100	500	1000

小的数字、（限于 Ⅰ、X 和 C）在大的数字的左边、所表示的数等于大数减小数得到的数、如：Ⅳ=4、Ⅸ=9；
beats: 84.29%
*/
class Solution {
public:

	inline int Convert_I(const std::string& s, size_t curPos)
	{
		size_t nextPos = curPos + 1;
		if (nextPos < s.size())
		{
			char nextChar = s[nextPos];
			if (nextChar == 'V' || nextChar == 'X')
			{
				return -1;
			}
		}
		return 1;
	}

	inline int Convert_X(const std::string& s, size_t curPos)
	{
		size_t nextPos = curPos + 1;
		if (nextPos < s.size())
		{
			char nextChar = s[nextPos];
			if (nextChar == 'L' || nextChar == 'C')
			{
				return -10;
			}
		}
		return 10;
	}

	inline int Convert_C(const std::string& s, size_t curPos)
	{
		size_t nextPos = curPos + 1;
		if (nextPos < s.size())
		{
			char nextChar = s[nextPos];
			if (nextChar == 'D' || nextChar == 'M')
			{
				return -100;
			}
		}
		return 100;
	}

	int romanToInt(string s) {
		size_t cur = 0;
		int sum = 0; 
		while (cur < s.size())
		{
			char romanChar = s[cur];
			if (romanChar=='I')
			{
				sum += Convert_I(s, cur);
			}
			else if (romanChar == 'V')
			{
				sum += 5;
			}
			else if (romanChar == 'X')
			{
				sum += Convert_X(s,cur);
			}
			else if (romanChar == 'L')
			{
				sum += 50;
			}
			else if (romanChar == 'C')
			{
				sum += Convert_C(s, cur);
			}
			else if (romanChar == 'D')
			{
				sum += 500;
			}
			else if (romanChar == 'M')
			{
				sum += 1000;
			}

			++cur;
		}

		return sum;


	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	assert(solution.romanToInt("C") == 100);
	assert(solution.romanToInt("IV") == 4);
	assert(solution.romanToInt("MMMCMXCIX") == 3999);

	std::cout << "OK" << std::endl;

	char ch;
	std::cin >> ch;
	return 0;
}

