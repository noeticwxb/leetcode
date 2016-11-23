// ReverseInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits>
#include <cmath>
#include <stack>

class Solution {
public:
	// beats 28% 太差了
	int reverse_V1(int x) {
		int MaxInt = std::numeric_limits<int>::max();	// 2147483647
		
		// 去掉正负号。最后在加上正负号
		int isNegtive = 1;
		if (x < 0)
		{
			x *= -1;
			isNegtive = -1;
		}

		// 提取出十进制表示
		std::stack<long long> numStack;
		while (x > 0)
		{
			long long digit = x % 10;
			numStack.push(digit);
			x = x / 10; 
		}

		// 倒置
		long long ret = 0;
		int op = 1;
		while (!numStack.empty())
		{
			long long digit = numStack.top() * op;
			numStack.pop();
			op *= 10;

			ret += digit;
		}

		if (ret > MaxInt)
		{
			return 0;
		}

		
		// 恢复正负号
		ret *= isNegtive;

		return ret;
	}

	// 和V1版本的性能差不多，beats也是28%。以后尝试的优化方案：
	// 1、快速的除法、求模
	// 2、更好的数学变化公式？
	// 结果又提交一次，变成74.99%。无语了
	int reverse(int x)
	{
		if (x < 1000000000 && x > -1000000000)
		{
			// 完全不会溢出

			int ret = 0;
			do
			{
				ret = (ret * 10) + (x % 10);
				x = x / 10;
			} while (x != 0);
			return ret;
		}
		else
		{
			int ret = 0;
			do
			{
				// 处理倒数最后一位之前，不会溢出
				if (ret < 99999999 && ret > -99999999)
				{
					ret = (ret * 10) + (x % 10);
					x = x / 10;
				}
				else
				{
					int retEnd = ret * 10;
					// overflow
					if (ret != retEnd / 10)
					{
						return 0;
					}

					int digit = x % 10;

					// over flow
					if (x > 0 && (std::numeric_limits<int>::max() - digit) < retEnd)
					{
						return 0;
					}

					// over flow
					if (x < 0 && std::numeric_limits<int>::min() - digit > retEnd)
					{
						return 0;
					}

					ret = retEnd + digit;
					x = x / 10;
				}

			} while (x != 0);
			return ret;

		}		 
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution; 
	std::cout << "123 reverse is " << solution.reverse(123) << std::endl; 
	std::cout << "-321 reverse is " << solution.reverse(-321) << std::endl;
	std::cout << "1534236469 reverse is " << solution.reverse(1534236469) << std::endl;
	std::cout << "-2147483412 reverse is " << solution.reverse(-2147483412) << std::endl;

	char ch;
	std::cin >> ch;
	return 0;
}

