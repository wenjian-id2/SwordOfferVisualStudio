#include "stdafx.h"
#include "ContainMostWater.h"


int maxArea(vector<int>& height)
{
	if (height.size() ==0 )
	{
		return -1;
	}

	int maxResult = 0;
	int length = height.size();
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i; j< length; j++)
		{
			
		}

	}
	return maxResult;

}
