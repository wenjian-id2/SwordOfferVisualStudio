#include "stdafx.h"
#include "DoubleList.h"

BinaryTreeNodeList* Convert(BinaryTreeNodeList* pRoot)
{
	if (pRoot == nullptr)
	{
		return nullptr;
	}




	return nullptr;
}

//题目：输入一个字符串，打印出该字符串中字符的所有排列

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

		}
	}




}
void Permutation(char* pStr)
{
	if (pStr == nullptr)
	{
		return;
	}

	Permutation(pStr, pStr);
}



int MoreThanHalfNum(int* number, int length)
{
	if (number == nullptr || length <= 0)
	{
		return 0;
	}

	int data = number[0], count = 1;

	for (size_t i = 1; i < length; i++)
	{
		if (count ==  0)
		{
			data = number[i];
			count = 1;
		}
		else if (data == number[i])
		{
			count++;
		}
		else
		{
			count--;
		}
	}
	return data;
}

//最小的k个数
void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
	leastNumbers.clear();

	if (k<1 || data.size() < k)
	{
		return;
	}

	vector<int>::const_iterator ite = data.begin();


	for (; ite != data.end(); ite++)
	{
		if (leastNumbers.size() < k)
		{
			leastNumbers.insert(*ite);

		}
		else
		{
			setIterator setIte = leastNumbers.begin();

			if (*ite < *setIte)
			{
				leastNumbers.erase(*setIte);
				leastNumbers.insert(*ite);
			}
		}

	}
}