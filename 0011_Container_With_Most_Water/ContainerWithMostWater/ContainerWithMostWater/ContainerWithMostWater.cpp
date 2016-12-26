// ContainerWithMostWater.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// 
	int maxArea_V1_TimeLimitExceeded(vector<int>& height) {
		size_t max_area = 0;
		for (size_t firstPoint = 0; firstPoint < height.size() - 1; ++firstPoint)
		{
			for (size_t secondPoint = firstPoint + 1; secondPoint < height.size(); ++secondPoint)
			{
				size_t minHeight = std::min(height[firstPoint], height[secondPoint]);
				size_t width = secondPoint - firstPoint;
				max_area = std::max(max_area, minHeight*width);
			}
		}
		return max_area;
	}
	// 当第一个循环结束后，找到最低高度。因为宽度是减少的。如果第二遍循环的height小于上一次找到的height，说明第二遍循环不用执行了。
	// 还是在一个递增队列时候时间溢出
	int maxArea_V2_TimeLimitExceeded(vector<int>& heights)
	{
		size_t max_area = 0;
		int last_min_height = 0;
		for (size_t firstPoint = 0; firstPoint < heights.size() - 1; ++firstPoint)
		{
			int first_height = heights[firstPoint];
			if (first_height < last_min_height)
			{
				continue;
			}

			for (size_t secondPoint = firstPoint + 1; secondPoint < heights.size(); ++secondPoint)
			{
				int height = std::min(first_height, heights[secondPoint]);
				size_t width = secondPoint - firstPoint;
				size_t area = height * width;
				if (area > max_area)
				{
					max_area = area;
					last_min_height = first_height;
				}
				
			}
		}
		return max_area;
	}

	// next loop 的fisrt，如果小于之前的first，不会出现最大值
	// next loop 的first，如果大于之前的first，但是小于之前的second。只需要从second的位置开始循环。因为
	// next loop 的fisrt，如果大于之前的second，那么要从头开始循环
	// beats 14.43%
	int maxArea_V3_14(vector<int>& heights)
	{
		size_t max_area = 0;
		int last_first_height = 0;
		int last_second_height = 0;

		int last_second_Point = 1;

		for (size_t firstPoint = 0; firstPoint < heights.size() - 1; ++firstPoint)
		{
			int first_height = heights[firstPoint];

			size_t beginSecond = firstPoint + 1;

			if (first_height <= last_first_height)
			{
				continue;
			}
			else if (first_height <= last_second_height)
			{
				beginSecond = last_second_Point;
			}
			else
			{
				beginSecond = firstPoint + 1;
			}
						
			for (size_t secondPoint = beginSecond; secondPoint < heights.size(); ++secondPoint)
			{
				int height = std::min(first_height, heights[secondPoint]);
				size_t width = secondPoint - firstPoint;
				size_t area = height * width;
				if (area > max_area)
				{
					max_area = area;
					last_first_height = first_height;
					last_second_height = heights[secondPoint];
					last_second_Point = secondPoint;
				}
			}
		}
		return max_area;
	}

	/** 继续细化讨论
	 假设现在找到的结果是(A,B),下次可能的高点是（C、D）。我们可以证明A<C, D<=B。
	 C大于A不用证明，循环就是这样写的。
	 1、需要H(C)>H(A)
		证明：当H(C)<=H(A)，不可能有高点。
			否则，有高点，意味着Area(C、D) > Area(A,B)。
			又因为H(C)<=H(A)，且|AD|>|CD|， 那么Area(A,D)=min(H(A),H(D))*|AD| >= min(H(C),H(D))*|AD| >　min(H(C),H(D))*|CD|=Area(C,D)
			综上，有Area(A,D)>Area(A,B)，与假设矛盾
	 2、假设D>B，即 |AD|>|AB|，定有H(D) <= min(H(A),H(B))	
			否则H(D) > min(H(A),H(B)), 那么 Area(A,D) = min(H(A),H(D))*|AD|> min(H(A),min(H(A),H(B)))*|AD|= min( H(A),H(B) )*|AD| >　min( H(A),H(B) )*|AB|=Area(A,B),与假设矛盾
			得证：H(D) <= min(H(A),H(B)),即H(D) < H(A) 且 H(D) < H(A)
			又从1得知，H(C)>H(A）,那么H(D) < H(C)
			那么Area(C,D) = min(H(D),H(C))*|CD|=H(D)*|CD| < H(D)*|AD|= min(H(D),H(A))*|AD|=Area(A,D) < Area(A,B)
			也就是说，当D>B时，不可能有最高点。这个结论很重要，意味着搜索区间是不断求子集。
     3、由1、2得知，有最高点，必有H(C) > H(A) && D<=B
		当 H(A)<H(C)<=H(B)时，
			Area(C,D)=min(H(C),H(D))*|CD| <= H(C)*|CD| <= H(C)*|CB| = min(H(C),H(B))*|CB|=Area(C,B)
			也就是说，当 H(A)<H(C)<H(B)时，只需要检查Area(C,B)即可
		当H(C) > H(B) && H(C) > H(A) 时，
			必然要求H(D) > H(A), 否则Area(A,D) > Area(C,D), 不会有高点
			也要求H(D) >= H(B), 否则Area(B,C) >= Area(C,D)。
    beats 14.43%还是不对，说明没有把握到算法的本质。			
	**/
	int maxArea_V4_14(vector<int>& heights)
	{
		size_t max_area = 0;
		int last_first_height = 0;
		int last_second_height = 0;
		int last_max_height = 0;

		int last_second_Point = 1;

		for (size_t firstPoint = 0; firstPoint < heights.size() - 1; ++firstPoint)
		{
			int first_height = heights[firstPoint];

			if (first_height <= last_first_height)
			{
				continue;
			}

			if (first_height <= last_second_height)
			{
				size_t area = first_height * (last_second_Point - firstPoint);
				if (area > max_area)
				{
					max_area = area;
					last_first_height = first_height;
					last_max_height = std::max(last_first_height, last_second_height);
				}
			}
			else
			{
				size_t beginSecond = firstPoint + 1;

				for (size_t secondPoint = beginSecond; secondPoint < heights.size(); ++secondPoint)
				{
					int second_height = heights[secondPoint];
					if (second_height < last_max_height)
					{
						continue;
					}

					int height = std::min(first_height, second_height);
					size_t width = secondPoint - firstPoint;
					size_t area = height * width;
					if (area > max_area)
					{
						max_area = area;
						last_first_height = first_height;
						last_second_height = heights[secondPoint];
						last_second_Point = secondPoint;
					}
				}

				last_max_height = std::max(last_first_height, last_second_height);
			}

		}
		return max_area;
	}

	// 上面已经得知搜索区间是不断求子集。
	// 假设当前结果是(A，B)，那么如果
	// H(A) > H(B),  那么是B是短板，我们尝试把B向里面移动
	// H(A) < H(A)，那么A是短板，我们尝试把A向内部移动
	// 为啥移动短板，因为min(H(A),H(B))*|AB|，如果移动长的部分，那么|AB|变小。而min(H(A)，H（B）)不变
	// beats 38%
	int maxArea_v5(vector<int>& heights)
	{
		int firstPoint = 0;
		int secondPoint = heights.size() - 1;
		int max_area = 0;
		while (firstPoint < secondPoint)
		{
			int area = std::min(heights[firstPoint], heights[secondPoint]) * (secondPoint - firstPoint);
			max_area = std::max(max_area, area);

			if (heights[firstPoint] > heights[secondPoint])
			{
				secondPoint--;
			}
			else
			{
				firstPoint++;
			}
		}
		return max_area;
	}

	// beats 91.17%
	int maxArea(vector<int>& heights)
	{
		int* firstPoint = heights.data();
		int* secondPoint = firstPoint + heights.size() - 1;
		int max_area = 0;
		int min_number = 0;
		while (firstPoint < secondPoint)
		{
			if (*firstPoint > min_number || *secondPoint > min_number)
			{
				int m = std::min(*firstPoint, *secondPoint);
				int area = m * (secondPoint - firstPoint);
				if (area > max_area)
				{
					max_area = area;
					min_number = m;
				}
			}
			
			if (*firstPoint > *secondPoint)
			{
				secondPoint--;
			}
			else
			{
				firstPoint++;
			}
		}
		return max_area;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{


	return 0;
}

