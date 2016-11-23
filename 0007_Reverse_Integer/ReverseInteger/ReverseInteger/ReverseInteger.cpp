// ReverseInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits>
#include <cmath>
#include <stack>

class Solution {
public:
	// beats 28% ̫����
	int reverse_V1(int x) {
		int MaxInt = std::numeric_limits<int>::max();	// 2147483647
		
		// ȥ�������š�����ڼ���������
		int isNegtive = 1;
		if (x < 0)
		{
			x *= -1;
			isNegtive = -1;
		}

		// ��ȡ��ʮ���Ʊ�ʾ
		std::stack<long long> numStack;
		while (x > 0)
		{
			long long digit = x % 10;
			numStack.push(digit);
			x = x / 10; 
		}

		// ����
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

		
		// �ָ�������
		ret *= isNegtive;

		return ret;
	}

	// ��V1�汾�����ܲ�࣬beatsҲ��28%���Ժ��Ե��Ż�������
	// 1�����ٵĳ�������ģ
	// 2�����õ���ѧ�仯��ʽ��
	// ������ύһ�Σ����74.99%��������
	int reverse(int x)
	{
		if (x < 1000000000 && x > -1000000000)
		{
			// ��ȫ�������

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
				// ���������һλ֮ǰ���������
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

