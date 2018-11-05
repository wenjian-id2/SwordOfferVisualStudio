#pragma once
#include "stdafx.h"

#include <set>
#include <functional>
#include <vector>
using std::vector;
using std::set;
using std::multiset;


// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。

//二叉搜索树节点定义
struct  BinaryTreeNodeList
{
	int m_nValue;
	BinaryTreeNodeList* m_left;
	BinaryTreeNodeList* m_right;
};

BinaryTreeNodeList* Convert(BinaryTreeNodeList* pRoot);

// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。

void Permutation(char* pStr, char* pBegin);
void Permutation(char* pStr);


int MoreThanHalfNum(int* number, int length);


// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

typedef multiset<int, std::greater<int>> intSet;

typedef multiset<int, std::greater<int>>::iterator setIterator;
void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k);