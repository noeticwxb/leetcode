// 0017_LetterCombinationsOfPhoneNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// beats 68.48 或许解开递归可以更快
class Solution {
public:
	

	vector<string> letterCombinations(string digits) {

		vector<string> mDigitToChar = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		vector<string> retList;
		retList.reserve(pow(3, digits.length()));

		string oneRet;
		oneRet.reserve(digits.length());
		modifyOneLetter(oneRet, digits, 0, mDigitToChar, retList);

		return retList;
	}

	void modifyOneLetter(string& oneRet, const string& digit, size_t pos, const vector<string>& mDigitToChar, vector<string>& retList)
	{
		if (pos >= digit.length())
		{
			if (!oneRet.empty())
			{
				retList.push_back(oneRet);
			}			
			return;
		}

		int index = digit[pos] - '0';
		auto charList = mDigitToChar[index];
		if (charList.length()==0)
		{
			modifyOneLetter(oneRet, digit, pos + 1, mDigitToChar, retList);
		}
		else
		{
			for (char ch : charList)
			{
				oneRet.push_back(ch);
				modifyOneLetter(oneRet, digit, pos + 1, mDigitToChar, retList);
				oneRet.pop_back(); 
			}
		}

	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	string in = "123";
	vector<string> ret = solution.letterCombinations(in);
	for (auto s : ret )
	{
		std::cout << s << std::endl;
	}
	
	char ch;
	std::cin >> ch;

	return 0;
}

