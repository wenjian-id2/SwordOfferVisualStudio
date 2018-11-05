#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;



//定义List节点
struct ListNode
{
	int value;
	ListNode* pNext;
};

//创建ListNode节点
ListNode* CreateListNode(int value);

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);

void PrintList(ListNode* pHead);

void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);
void printReverse(ListNode* pHead);
void DeleteNode(ListNode** pHead, ListNode* tobeDeleted);
void deleteDuplication(ListNode** pHead);
void ListSort(ListNode** pHead);

int FindPos(vector<int> & array, int low, int high);

//找到链表的倒数K个节点   只能遍历一次链表
ListNode* findKthToTail(ListNode* pHead, unsigned int k);
//链表的反转
ListNode* reverseList(ListNode* head);

/*
给定一个单链表的头节点head，实现一个调整单链表的函数，使得每k个节点之间逆序，
如果最后不够k个节点一组，则不调整最后几个节点。

例如：

链表：1->2->3->4->5->6->7->8->null，k＝3

调整后：3->2->1->6->5->4->7->8->null
*/
ListNode* reverseKnode(ListNode* head, int K);

//链表反转
ListNode* reverseList(ListNode* begin, ListNode* end);

//反转链表中的一组数据
ListNode* reverseOneGroup(ListNode* pre, ListNode* end);

/*合并两个有序链表*/
ListNode* mergeList(ListNode* pHead1, ListNode* pHead2);


/***********************************************
以下为测试代码，不保证代码的正确性
*************************************************/
ListNode* Test_reverseKnode(ListNode* head, int K);

//旋转pre和end之间的节点
ListNode* Test_reverseOneGroup(ListNode* pre, ListNode* end);
