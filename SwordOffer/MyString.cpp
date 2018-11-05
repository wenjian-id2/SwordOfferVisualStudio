#include "MyString.h"
#include "stdafx.h"

/*��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��*/

/*�ⷨ��

1.���ȿ��ǵ�һ���ַ���ģʽ�ַ�ƥ����������������������ch = ch����.�����͵ÿ��Եõ���һ������*str==*pattern || (*str ��= ��\0�� && *pattern == ��.��)

2.Ȼ���ǵڶ���ģʽ�ַ�Ϊ*���������������Ƚϸ���

A.����һ���ַ�ƥ�䣬��ô��Ϊ���������

  1��ƥ���ַ���0���ַ�����aa��a*aa���ַ������ƶ���ģʽ����*ǰ����ַ��������ڿ�ʼʱ��һֱû�뵽��������

  2��ƥ���ַ���1���ַ�����ab��a*b���ַ�����1λ��ģʽ����*ǰ����ַ�

  3��ƥ���ַ���2���������ַ�����aab��a*b���ַ�����1λ��ģʽ����

B.����һ���ַ���ƥ�䣬��ba��a*ba����ôͬ�����1��ƥ��0���ַ�

3.�������������ͬ1�������ƶ�����һ��λ�ý��бȽϡ�

4.���嶼ʹ�õݹ�������ģ��ݹ��������������ַ�����ģʽͬʱ�������λ�ã��򷵻��棻����ַ���δ��������ַ�������ģʽ�����˷��ؼ٣�*/
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
		if (*strOrigin == *patten || (*strOrigin != '\0' && *patten == '.'))   //ƥ���һ���ַ�
		{
			return match(strOrigin, patten + 2) || //��aa��a*aa
				match(strOrigin + 1, patten + 2) ||    //ab��a*b
				match(strOrigin + 1, patten);         //aab��a*b���ַ�����1λ��ģʽ����
		} 
		//����һ���ַ���ƥ��
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
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ�����+100��,��5e2��,��-123��,��3.1416���͡�-1E-16������ʾ��ֵ��
���ǡ�12e��,��1a3.14��,��1.2.3��,��+-5���͡�12e+4.3�������ǡ�*/

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

	//��������������
	bool result = scanInterger(&str);
	if (*str == '.')   //�������. ���������С������
	{
		str++;
		//����һ�д������ ||��ԭ��
		//1 С������û����������  .123����0.123
		//2 С���������û������  123. ���� 123.0
		//3 С�����ֺ��������ֶ�����   123.666 
		result = scanUnsignedInterger(&str) || result;
	}
	if (*str == 'E' || *str == 'e')    //������ָ������
	{
		str++;
		result = scanInterger(&str) && result;
	}

	return result && (*str) == '\0';

}

/*
����һ���������飬ʵ��һ����������������������ֵ�λ�ã�ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�*/

void ReorderOddEven(int* pData, const unsigned int length) {
	if (pData == nullptr || length == 0)
	{
		return;
	}

	int* pHead = pData;
	int* pTail = pData + length - 1;
	while (pHead < pTail)
	{
		while (pHead < pTail && (((*pHead) & 0x1) == 1))    //���Ϊ����
		{
			pHead++;
		}
		while (pHead < pTail && (((*pTail) & 0x1) == 0))    //���Ϊż��
		{
			pTail--;
		}
		//�������ߵ�λ��
		if (pHead < pTail)
		{
			int temp = *pHead;
			*pHead = *pTail;
			*pTail = temp;
		}		 
	}

}

//���ú���ָ��ķ�ʽ
void ReorderOddEven(int* pData, unsigned int length, bool(*func)(int)) {
	if (pData == nullptr || length == 0)
	{
		return;
	}

	int* pHead = pData;
	int* pTail = pData + length - 1;
	while (pHead < pTail)
	{
		while (pHead < pTail && !func(*pHead))    //���Ϊ����
		{
			pHead++;
		}
		while (pHead < pTail && func(*pTail))    //���Ϊż��
		{
			pTail--;
		}
		//�������ߵ�λ��
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