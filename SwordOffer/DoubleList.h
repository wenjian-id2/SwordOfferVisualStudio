#pragma once
#include "stdafx.h"

#include <set>
#include <functional>
#include <vector>
using std::vector;
using std::set;
using std::multiset;


// ������36��������������˫������
// ��Ŀ������һ�ö��������������ö���������ת����һ�������˫������Ҫ��
// ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

//�����������ڵ㶨��
struct  BinaryTreeNodeList
{
	int m_nValue;
	BinaryTreeNodeList* m_left;
	BinaryTreeNodeList* m_right;
};

BinaryTreeNodeList* Convert(BinaryTreeNodeList* pRoot);

// ������38���ַ���������
// ��Ŀ������һ���ַ�������ӡ�����ַ������ַ����������С����������ַ���abc��
// ���ӡ�����ַ�a��b��c�������г����������ַ���abc��acb��bac��bca��cab��cba��

void Permutation(char* pStr, char* pBegin);
void Permutation(char* pStr);


int MoreThanHalfNum(int* number, int length);


// ������40����С��k����
// ��Ŀ������n���������ҳ�������С��k��������������4��5��1��6��2��7��3��8
// ��8�����֣�����С��4��������1��2��3��4��

typedef multiset<int, std::greater<int>> intSet;

typedef multiset<int, std::greater<int>>::iterator setIterator;
void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k);