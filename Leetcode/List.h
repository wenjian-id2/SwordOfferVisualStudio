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

//���ӽڵ�
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);

// ��ӡ����
void printList(ListNode* pHead);

//��������
void DestroyList(ListNode* head);

//  leetcode 19. Remove Nth Node From End of List

ListNode* removeNthFromEnd(ListNode* head, int n);

//21. Merge Two Sorted Lists  ���õݹ鷽��
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
//����ѭ���ķ�ʽ
ListNode* mergeTwoListsCycle(ListNode* l1, ListNode* l2);