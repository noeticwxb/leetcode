// ZigZagConversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	// 有思路看。数学上是有规律的。从波峰，相位得到启发。固定间隔为d，A1是第一个元素, An是第numRows个
	// A1，A1+d、A1+2*d,A1+3*d
	// (A1-1), A1+1, (A1-1+d),(A1+1+d),(A1-1+2*d),(A1+1+2*d).... 
	//  (A1-2), A1+2, (A1-2+d),(A1+2+d),(A1-2+2*d),(A1+2+2*d).... 
	//...
	// An,An+d,An+2*d,An+3*d,An+4*d

	// o(N), beats 76.52%
	string convert(string s, int numRows) {
		if (s.empty() || numRows <= 1)
		{
			return s;
		}

		int phaseLength = (2 * numRows) - 2;

		string ret(s);

		char *pRet = (char*)ret.data();
		char* pS = (char*)s.data();

		int retIndex = 0;

		// first line
		{
			size_t phaseIndex = 0;
			while (phaseIndex < s.length())
			{
				pRet[retIndex] = pS[phaseIndex];
				retIndex++;
				phaseIndex += phaseLength;
			}
		}

		{
			// mid lines
			size_t maxRowIndex = numRows - 1;
			for (size_t i = 1; i < maxRowIndex; ++i)
			{
				size_t phaseIndexLeft = i;// A1 + 1
				size_t phaseIndexRight = phaseLength - i; // A1 - 1 + d
				while (phaseIndexLeft < s.length() && phaseIndexRight < s.length())
				{
					pRet[retIndex] = pS[phaseIndexLeft];
					retIndex++;
					phaseIndexLeft += phaseLength;

					pRet[retIndex] = pS[phaseIndexRight];
					retIndex++;
					phaseIndexRight += phaseLength;
				}

				if (phaseIndexLeft < s.length() )
				{
					pRet[retIndex] = pS[phaseIndexLeft];
					retIndex++;
				}

			}		
		}


		// end line
		{
			size_t phaseIndex = numRows - 1;
			while (phaseIndex < s.length())
			{
				pRet[retIndex] = pS[phaseIndex];
				retIndex++;
				phaseIndex += phaseLength;
			}
		}
		return std::move(ret);
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	string strIn = "PAYPALISHIRING";
	string strResult = "PAHNAPLSIIGYIR";

	string strOut = solution.convert(strIn, 3);
	cout << strOut << std::endl;
	if (strOut == strResult )
	{
		cout << "OK" << std::endl;
	}
	else
	{
		cout << "Failed" << std::endl;
	}

	char ch;
	cin >> ch;

	return 0;
}

