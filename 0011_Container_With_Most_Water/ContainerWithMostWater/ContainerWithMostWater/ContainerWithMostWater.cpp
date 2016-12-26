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
	// ����һ��ѭ���������ҵ���͸߶ȡ���Ϊ����Ǽ��ٵġ�����ڶ���ѭ����heightС����һ���ҵ���height��˵���ڶ���ѭ������ִ���ˡ�
	// ������һ����������ʱ��ʱ�����
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

	// next loop ��fisrt�����С��֮ǰ��first������������ֵ
	// next loop ��first���������֮ǰ��first������С��֮ǰ��second��ֻ��Ҫ��second��λ�ÿ�ʼѭ������Ϊ
	// next loop ��fisrt���������֮ǰ��second����ôҪ��ͷ��ʼѭ��
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

	/** ����ϸ������
	 ���������ҵ��Ľ����(A,B),�´ο��ܵĸߵ��ǣ�C��D�������ǿ���֤��A<C, D<=B��
	 C����A����֤����ѭ����������д�ġ�
	 1����ҪH(C)>H(A)
		֤������H(C)<=H(A)���������иߵ㡣
			�����иߵ㣬��ζ��Area(C��D) > Area(A,B)��
			����ΪH(C)<=H(A)����|AD|>|CD|�� ��ôArea(A,D)=min(H(A),H(D))*|AD| >= min(H(C),H(D))*|AD| >��min(H(C),H(D))*|CD|=Area(C,D)
			���ϣ���Area(A,D)>Area(A,B)�������ì��
	 2������D>B���� |AD|>|AB|������H(D) <= min(H(A),H(B))	
			����H(D) > min(H(A),H(B)), ��ô Area(A,D) = min(H(A),H(D))*|AD|> min(H(A),min(H(A),H(B)))*|AD|= min( H(A),H(B) )*|AD| >��min( H(A),H(B) )*|AB|=Area(A,B),�����ì��
			��֤��H(D) <= min(H(A),H(B)),��H(D) < H(A) �� H(D) < H(A)
			�ִ�1��֪��H(C)>H(A��,��ôH(D) < H(C)
			��ôArea(C,D) = min(H(D),H(C))*|CD|=H(D)*|CD| < H(D)*|AD|= min(H(D),H(A))*|AD|=Area(A,D) < Area(A,B)
			Ҳ����˵����D>Bʱ������������ߵ㡣������ۺ���Ҫ����ζ�����������ǲ������Ӽ���
     3����1��2��֪������ߵ㣬����H(C) > H(A) && D<=B
		�� H(A)<H(C)<=H(B)ʱ��
			Area(C,D)=min(H(C),H(D))*|CD| <= H(C)*|CD| <= H(C)*|CB| = min(H(C),H(B))*|CB|=Area(C,B)
			Ҳ����˵���� H(A)<H(C)<H(B)ʱ��ֻ��Ҫ���Area(C,B)����
		��H(C) > H(B) && H(C) > H(A) ʱ��
			��ȻҪ��H(D) > H(A), ����Area(A,D) > Area(C,D), �����иߵ�
			ҲҪ��H(D) >= H(B), ����Area(B,C) >= Area(C,D)��
    beats 14.43%���ǲ��ԣ�˵��û�а��յ��㷨�ı��ʡ�			
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

	// �����Ѿ���֪���������ǲ������Ӽ���
	// ���赱ǰ�����(A��B)����ô���
	// H(A) > H(B),  ��ô��B�Ƕ̰壬���ǳ��԰�B�������ƶ�
	// H(A) < H(A)����ôA�Ƕ̰壬���ǳ��԰�A���ڲ��ƶ�
	// Ϊɶ�ƶ��̰壬��Ϊmin(H(A),H(B))*|AB|������ƶ����Ĳ��֣���ô|AB|��С����min(H(A)��H��B��)����
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

