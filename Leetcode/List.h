#pragma once
#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};

//连接节点
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);

// 打印链表
void printList(ListNode* pHead);

//销毁链表
void DestroyList(ListNode* head);

//  leetcode 19. Remove Nth Node From End of List

ListNode* removeNthFromEnd(ListNode* head, int n);

//21. Merge Two Sorted Lists  采用递归方法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
//采用循环的方式
ListNode* mergeTwoListsCycle(ListNode* l1, ListNode* l2);