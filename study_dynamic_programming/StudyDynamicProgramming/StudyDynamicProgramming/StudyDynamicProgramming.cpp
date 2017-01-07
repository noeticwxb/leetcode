// StudyDynamicProgramming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AllHeader.h"
#include <vector>
#include <limits>
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	for (int sum = 1; sum < 13; ++sum)
	{
		std::cout << sum << ":  " << CoinCount(sum) << std::endl;
	}

	char c;
	std::cin >> c;

	return 0;
}

