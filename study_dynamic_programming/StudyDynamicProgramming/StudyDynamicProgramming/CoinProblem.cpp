#include "stdafx.h"
#include "AllHeader.h"
#include <vector>
#include <limits>

// http://www.hawstein.com/posts/dp-novice-to-advanced.html

int CoinCount(int score)
{
	const int COIN_COUNT = 3;
	int COIN[COIN_COUNT] = { 1, 3, 5 };

	// 只需要记录之前的三个状态就可以了
	std::vector<int> minCoinRecord;
	minCoinRecord.resize(score + 1, std::numeric_limits<int>::max());
	minCoinRecord[0] = 0; 
	for (int curScore = 1; curScore <= score; ++curScore)
	{
		for (int curCoin = 0; curCoin < COIN_COUNT;++curCoin)
		{
			if (COIN[curCoin] <= curScore 
				&& minCoinRecord[curScore - COIN[curCoin]] + 1 < minCoinRecord[curScore])
			{
				minCoinRecord[curScore] = minCoinRecord[curScore - COIN[curCoin]] + 1;
			}
		}
	}

	return minCoinRecord[score];
}