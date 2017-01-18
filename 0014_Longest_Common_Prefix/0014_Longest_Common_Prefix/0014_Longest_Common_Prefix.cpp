// 0014_Longest_Common_Prefix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;

// 成功，但是不知道效率，网站出问题了，没有detail了
class Solution {
public:

	inline int longestCommonPrefix(const string& str1, const string& str2, size_t count)
	{
		for (size_t i = 0; i < count;++i)
		{
			if ( str1[i]!=str2[i])
			{
				return i;
			}
		}
		return count;
	}

	string longestCommonPrefix(vector<string>& strs) {

		if (strs.empty())
		{
			return nullptr;
		}

		if (strs.size() == 1)
		{
			return strs[0];
		}

		size_t minCount = std::numeric_limits<size_t>::max();
		for (const string& str : strs)
		{
			minCount = std::min(minCount, str.size());
		}

		const string& str1 = strs[0];

		for (size_t loop = 1; loop < strs.size();++loop)
		{
			minCount = longestCommonPrefix(str1, strs[loop], minCount);
		}
		 
		return str1.substr(0, minCount);
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<string> strVec;
	//strVec.push_back("123");
	//strVec.push_back("1234");


	Solution solution;
	string str = solution.longestCommonPrefix(strVec);

	std::cout << str << std::endl;
	char ch;
	std::cin >> ch;

	return 0;
}

