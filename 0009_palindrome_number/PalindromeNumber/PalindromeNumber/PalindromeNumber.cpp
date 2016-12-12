// PalindromeNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Solution {
public:
	// 利用求模和除法去实现
	// beats 40.52% . run second 75.55%.run third 96.15%
	// 按照下面的代码，直接做if，比做循环除法要快一点点。
	// http://stackoverflow.com/questions/701322/how-can-you-get-the-first-digit-in-an-int-c/701621#701621
	// 
	bool isPalindrome(int x) {
		if (x < 0 )
		{
			return false;
		}
		if (x == 0 )
		{
			return true;
		}

		int temp = x;
		int numBit = 1;
		temp = temp / 10;
		while (temp!=0)
		{		
			temp = temp / 10;
			numBit *= 10;
		}

		temp = x;
		while (numBit!=0)
		{
			int first = temp / numBit;
			int last = temp % 10;
			if (first!=last)
			{
				return false;
			}

			// remove first
			temp = temp - first * numBit;

			// remove last
			temp = temp / 10; 

			numBit = numBit / 100;
			if (numBit==1)
			{
				return true;
			}
		}
		return true;

	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	std::cout << "1 " << solution.isPalindrome(1) << std::endl;
	std::cout << "11 " << solution.isPalindrome(11) << std::endl;
	std::cout << "111 " << solution.isPalindrome(111) << std::endl;
	std::cout << "1111 " << solution.isPalindrome(1111) << std::endl;
	std::cout << "12 " << solution.isPalindrome(12) << std::endl;
	std::cout << "121 " << solution.isPalindrome(121) << std::endl;
	std::cout << "123 " << solution.isPalindrome(123) << std::endl;
	std::cout << "-1 " << solution.isPalindrome(-1) << std::endl;

	char ch;
	std::cin >> ch;
	return 0;
}

