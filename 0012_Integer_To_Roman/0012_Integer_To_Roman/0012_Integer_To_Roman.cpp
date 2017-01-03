// 0012_Integer_To_Roman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

/************************************************************************/
/* 
�������ֵı��뷽ʽ��
I	V	X	L	��	��	��
1	5	10	50	100	500	1000

(1) ��ͬ��������д������ʾ����������Щ������ӵõ��������磺��=3��
(2) С�������ڴ�����ֵ��ұߡ�����ʾ����������Щ������ӵõ������� �磺��=8����=12��
(3) С�����֡������� ��X �� C���ڴ�����ֵ���ߡ�����ʾ�������ڴ�����С���õ��������磺��=4����=9��
(4) ����ʹ��ʱ����д�������ظ����ó������Σ�
(5) ��һ���������滭һ�����ߡ���ʾ��������� 1000 ��
*/
/************************************************************************/
class Solution {
public:
	// �������������ֵı����������baidu�ˡ��ٶȰٿ���ֱ�Ӿ��д��ˡ���ʵ���׹���֮�󣬺ܼ򵥵��㷨��
	string intToRoman(int num) {
		char* c[4][10] = {
			{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
			{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
			{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
			{ "", "M", "MM", "MMM" }	
		};

		string roman;
		roman.append(c[3][num / 1000]);
		roman.append(c[2][ (num / 100) % 10]);
		roman.append(c[1][(num / 10) % 10]);
		roman.append(c[0][num % 10]);

		return roman;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	assert(solution.intToRoman(100) == "C");
	assert(solution.intToRoman(4) == "IV");
	assert(solution.intToRoman(3999) == "MMMCMXCIX");

	std::cout << "Success" << std::endl; 

	char c;
	std::cin >> c;


	return 0;
}

