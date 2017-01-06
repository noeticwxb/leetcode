#include "stdafx.h"
#include "Allheader.h"

// 三门问题
//http://baike.baidu.com/link?url=-z7ggzdb67eLfiuV9fTxxZJiRUlqwTtuf1-2G6GgGZdjIX8rXkHYf5e9jRjZa4iRHHiC1fSTHgTr9ydyyjqmz7xfb7eiOflHH4y8zNnpnYNjmO1SgPt6EQ1WcZ0Iu4lS
//https://www.zhihu.com/question/26709273?rf=25099900
void ThreeRoom()
{
	std::srand(std::time(0)); // use current time as seed for random generator

	const int LoopCount = 100000;
	bool room[3];

	int firstSelectIsGift = 0;
	int secondSelectIsGift = 0;

	for (int iLoop = 0; iLoop < LoopCount; ++iLoop)
	{
		// 三个房间中，随机填充一个房间，代表礼物存放的为准
		room[0] = false;
		room[1] = false;
		room[2] = false;

		float f = (float)std::rand();
		f = f / RAND_MAX;
		if (f < 0.3333333333)
		{
			room[0] = true;
		}
		else if (f < 0.66666666)
		{
			room[1] = true;
		}
		else
		{
			room[2] = true;
		}

		// 先随机选择一个房间
		int firstSelectIndex = std::rand() % 3;

		// 挑选一个没有礼物的房间，打开
		int openRoomIndex = (firstSelectIndex + 1) % 3;
		if (room[openRoomIndex] == true)
		{
			openRoomIndex = (openRoomIndex + 1) % 3;
		}

		assert(openRoomIndex != firstSelectIndex);

		// 选择挑选出来后，剩余的那个房间
		int secondSelectIndex = openRoomIndex;
		secondSelectIndex = (secondSelectIndex + 1) % 3;
		if (secondSelectIndex == firstSelectIndex)
		{
			secondSelectIndex = (secondSelectIndex + 1) % 3;
		}

		assert(secondSelectIndex != openRoomIndex);
		assert(secondSelectIndex != firstSelectIndex);

		if (room[firstSelectIndex])
		{
			++firstSelectIsGift;
		}

		if (room[secondSelectIndex])
		{
			++secondSelectIsGift;
		}

	}


	std::cout << "Probability of First Select in Gift " << (float)firstSelectIsGift / (float)LoopCount << std::endl;
	std::cout << "Probability of Second Select in Gift " << (float)secondSelectIsGift / (float)LoopCount << std::endl;

}