// 0012_Integer_To_Roman.cpp : Defines the entry point for the console application.
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

(1) 相同的数字连写、所表示的数等于这些数字相加得到的数、如：Ⅲ=3；
(2) 小的数字在大的数字的右边、所表示的数等于这些数字相加得到的数、 如：Ⅷ=8、Ⅻ=12；
(3) 小的数字、（限于 Ⅰ、X 和 C）在大的数字的左边、所表示的数等于大数减小数得到的数、如：Ⅳ=4、Ⅸ=9；
(4) 正常使用时、连写的数字重复不得超过三次；
(5) 在一个数的上面画一条横线、表示这个数扩大 1000 倍
*/
/************************************************************************/
class Solution {
public:
	// 不明白罗马数字的编码规则。所以baidu了。百度百科上直接就有答案了。其实明白规则之后，很简单的算法。
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

