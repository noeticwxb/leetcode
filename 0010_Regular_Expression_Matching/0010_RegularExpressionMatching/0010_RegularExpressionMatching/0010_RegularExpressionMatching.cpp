// 0010_RegularExpressionMatching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cassert>
#include <exception>
#include <vector>
#include <stack>
#include <memory>
#include "compile_time_regex.h"

using namespace std;

/*

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true

*/

class Solution {
public:

	// right, but just only 39%
	const char EOFChar = '\0';
	bool isMatch(const char* text, const char* p)
	{
		if (*text == EOFChar && *p == EOFChar)
		{
			return true;
		}

		if (*p == EOFChar)
		{
			return false;
		}

		if ( *(p+1) == '*')
		{
			return isMatchStar(text, *p, p + 2);
		}

		if (*text == EOFChar)
		{
			return false;
		}

		if ( *p == '.' )
		{
			return isMatch(text + 1, p + 1);
		}
		else if ( *text == *p )
		{
			return isMatch(text + 1, p + 1);
		}

		return false;
				
	}

	bool isMatchStar(const char* text, char ch, const char* p)
	{
		do 
		{
			if (isMatch(text, p))
			{
				return true;
			}

		} while (*text != EOFChar && ( *(text++) == ch || ch == '.' ) );
		return false;
	}


	bool isMatch(string s, string p) {

		return isMatch(s.data(), p.data());
	}
};


#include <cassert>

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	assert(solution.isMatch("aa", "a") == false);
	assert(solution.isMatch("aa", "aa") == true);
	assert(solution.isMatch("aaa", "aa") == false);
	assert(solution.isMatch("aa", "a*") == true);
	assert(solution.isMatch("aa", ".*") == true);
	assert(solution.isMatch("ab", ".*") == true);
	assert(solution.isMatch("aab", "c*a*b") == true);
	assert(solution.isMatch("aaa", "a*a") == true);
	assert(solution.isMatch("aaa", "a*a") == true);

	assert(solution.isMatch("", "..") == false);

	assert(solution.isMatch("a", "ab*") == true);

	std::cout << "OK" << std::endl;

	char ch;
	std::cin >> ch;

	return 0;

}

