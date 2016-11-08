// LongestPalindromicSubstring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	// 一次提交成功。beats 74.4%

	string longestPalindrome(string s) {
		const char* start = s.data();

		const char* rend = start - 1;
		const char* end = start + s.length();

		const char* cur = start;
		const char* longestBegin = cur-1;
		int longestCount = 2;
		while (cur != end)
		{
			// 考虑回文是计数的情况
			{
				const char* back = cur;
				const char* forward = cur;
				while ((back != rend) && (forward != end) && (*back == *forward))
				{
					back--;
					forward++;
				}

				if ((forward - back) > longestCount)
				{
					longestBegin = back;
					longestCount = forward - back;
				}
			}

			// 考虑回文是偶数的情况
			{
				const char* back = cur; 
				const char* forward = cur+1;
				while ((back != rend) && (forward != end) && (*back == *forward))
				{
					back--;
					forward++;
				}
				if ((forward - back) > longestCount)
				{
					longestBegin = back;
					longestCount = forward - back;
				}
			}


			cur++; 
		}

		return string(longestBegin+1, longestCount - 1);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	string in = "a";
	string out = solution.longestPalindrome(in);
	cout << in << " " << out << std::endl;

	in = "aa";
	out = solution.longestPalindrome(in);
	cout << in << " " <<out << std::endl;

	in = string("abbbba");
	out = solution.longestPalindrome(in);
	cout << in << " " << out << std::endl;

	in = string("abbbb");
	out = solution.longestPalindrome(in);
	cout << in << " " << out << std::endl;

	char c;
	cin >> c;

	return 0;
}

