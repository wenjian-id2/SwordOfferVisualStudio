#include "MyString.h"
#include "stdafx.h"

/*请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配*/

/*解法：

1.首先考虑第一个字符和模式字符匹配的条件，会有两种情况，ch = ch或者.这样就得可以得到第一个条件*str==*pattern || (*str ！= ‘\0’ && *pattern == ‘.’)

2.然后考虑第二个模式字符为*的情况，这种情况比较复杂

A.若第一个字符匹配，那么分为三种情况：

  1）匹配字符串0个字符，如aa和a*aa，字符串不移动，模式跳过*前面的字符（这种在开始时候一直没想到！！！）

  2）匹配字符串1个字符，如ab和a*b，字符串移1位，模式跳过*前面的字符

  3）匹配字符串2个及以上字符，如aab和a*b，字符串移1位，模式不动

B.若第一个字符不匹配，如ba和a*ba，那么同上面的1）匹配0个字符

3.所以其他情况就同1，进行移动到下一个位置进行比较。

4.整体都使用递归来处理的，递归结束条件：如果字符串和模式同时到达结束位置，则返回真；如果字符串未到达结束字符串，而模式到达了返回假；*/
bool match(const char* strOrigin,const char* patten) {
	if (strOrigin == nullptr || patten == nullptr)
	{
		return false;
	}

	if (*strOrigin == '\0' && *patten == '\0')
	{
		return true;
	}

	if (*strOrigin != '\0' && *patten == '\0')
	{
		return false;
	}

	if (*(strOrigin+1) == '*')
	{
		if (*strOrigin == *patten || (*strOrigin != '\0' && *patten == '.'))   //匹配第一个字符
		{
			return match(strOrigin, patten + 2) || //如aa和a*aa
				match(strOrigin + 1, patten + 2) ||    //ab和a*b
				match(strOrigin + 1, patten);         //aab和a*b，字符串移1位，模式不动
		} 
		//若第一个字符不匹配
		else
		{
			return match(strOrigin, patten + 2);
		}
	}

	//
	if (*strOrigin == *patten || (*strOrigin != '\0' && *patten == '.')) {
		return match(strOrigin + 1, patten + 1);
	}
	return false;
}

/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串”+100”,”5e2”,”-123”,”3.1416”和”-1E-16”都表示数值。
但是”12e”,”1a3.14”,”1.2.3”,”+-5”和”12e+4.3”都不是。*/

bool scanUnsignedInterger(const char** str) {
	const char* first = *str;
	while (**str != '\0' && **str>='0' &&**str <= '9')
	{
		(*str)++;
	}
	return first < *str;
}

bool scanInterger(const char** str) {
	if (**str == '+' || **str == '-')
	{
		(*str)++;
	}
	return scanUnsignedInterger(str);
}

bool isNumber(const char* str) {
	if (str == nullptr)
	{
		return false;
	}

	//依次向后遍历整数
	bool result = scanInterger(&str);
	if (*str == '.')   //如果出现. 则接下来是小数部分
	{
		str++;
		//下面一行代码采用 ||的原因：
		//1 小数可以没有整数部分  .123等于0.123
		//2 小数后面可以没有数字  123. 等于 123.0
		//3 小数部分和整数部分都有数   123.666 
		result = scanUnsignedInterger(&str) || result;
	}
	if (*str == 'E' || *str == 'e')    //后面是指数部分
	{
		str++;
		result = scanInterger(&str) && result;
	}

	return result && (*str) == '\0';

}

/*
输入一个整数数组，实现一个函数来解决该数组中数字的位置，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。*/

void ReorderOddEven(int* pData, const unsigned int length) {
	if (pData == nullptr || length == 0)
	{
		return;
	}

	int* pHead = pData;
	int* pTail = pData + length - 1;
	while (pHead < pTail)
	{
		while (pHead < pTail && (((*pHead) & 0x1) == 1))    //如果为奇数
		{
			pHead++;
		}
		while (pHead < pTail && (((*pTail) & 0x1) == 0))    //如果为偶数
		{
			pTail--;
		}
		//调换两者的位置
		if (pHead < pTail)
		{
			int temp = *pHead;
			*pHead = *pTail;
			*pTail = temp;
		}		 
	}

}

//采用函数指针的方式
void ReorderOddEven(int* pData, unsigned int length, bool(*func)(int)) {
	if (pData == nullptr || length == 0)
	{
		return;
	}

	int* pHead = pData;
	int* pTail = pData + length - 1;
	while (pHead < pTail)
	{
		while (pHead < pTail && !func(*pHead))    //如果为奇数
		{
			pHead++;
		}
		while (pHead < pTail && func(*pTail))    //如果为偶数
		{
			pTail--;
		}
		//调换两者的位置
		if (pHead < pTail)
		{
			int temp = *pHead;
			*pHead = *pTail;
			*pTail = temp;
		}
	}

}

bool isEven(int num) {
	return ((num & 0x1) == 0);
}