// 0020_Valid_Parentheses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// beats 15.8% how?
class Solution {

public:
	char BracketsPairs[255];

	Solution()
	{
		::memset(BracketsPairs, 0, 255);
		BracketsPairs['}'] = '{';
		BracketsPairs[')'] = '(';
		BracketsPairs[']'] = '[';
	}

	bool isValid(string s) {
		std::vector<char> bracketsNotPair;
		bracketsNotPair.reserve(s.size());

		for (char ch:s)
		{
			const char firstBracket = BracketsPairs[ch];
			if (firstBracket==0)
			{
				// not '}' ')'']'
				bracketsNotPair.push_back(ch);
			}
			else
			{
				if (!bracketsNotPair.empty() &&
					bracketsNotPair.back() == firstBracket
					)
				{
					bracketsNotPair.pop_back();
				}
				else
				{
					return false;
				}

			}
		}

		return bracketsNotPair.empty();

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	{
		string s1 = "()[]{}";
		std::cout << s1.c_str() << " " << solution.isValid(s1) << std::endl;
	}

	{
		string s2 = "([]";
		std::cout << s2.c_str() << " " << solution.isValid(s2) << std::endl;
	}




	char ch;
	std::cin >> ch;

	return 0;
}

