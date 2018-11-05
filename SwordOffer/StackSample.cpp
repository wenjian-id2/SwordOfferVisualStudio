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
	stack<int> stackHelp;  //建立辅助栈
	while (nPushCount < nLength || nPopCount < nLength )
	{
		while (stackHelp.empty() || stackHelp.top() != pPop[nPopCount])
		{
			if (nPushCount >= nLength)     //如果遍历到结束 都没有匹配  则返回false
			{
				return false;
			}
			stackHelp.push(pPush[nPushCount]);     //把push元素依次压入栈中
			nPushCount++;
		}
	    //此时 
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
