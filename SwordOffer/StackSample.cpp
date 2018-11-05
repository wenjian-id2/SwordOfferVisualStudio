#include "stdafx.h"
#include "StackSample.h"

bool isPopOrder(const int* pPush, const int* pPop, int nLength)
{
	if (pPush == nullptr || pPop == nullptr || nLength <= 0)
	{
		return false;
	}


	int nPushCount = 0;
	int nPopCount = 0;
	stack<int> stackHelp;  //��������ջ
	while (nPushCount < nLength || nPopCount < nLength )
	{
		while (stackHelp.empty() || stackHelp.top() != pPop[nPopCount])
		{
			if (nPushCount >= nLength)     //������������� ��û��ƥ��  �򷵻�false
			{
				return false;
			}
			stackHelp.push(pPush[nPushCount]);     //��pushԪ������ѹ��ջ��
			nPushCount++;
		}
	    //��ʱ 
		if (stackHelp.top() != pPop[nPopCount])
		{
			return false;
		}

		stackHelp.pop();
		nPopCount++;
	}

	if (stackHelp.empty() && nPopCount == nLength)
	{
		return true;
	}


	return false;
}
