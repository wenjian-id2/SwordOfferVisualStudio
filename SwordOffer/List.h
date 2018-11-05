#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;



//����List�ڵ�
struct ListNode
{
	int value;
	ListNode* pNext;
};

//����ListNode�ڵ�
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

//�ҵ�����ĵ���K���ڵ�   ֻ�ܱ���һ������
ListNode* findKthToTail(ListNode* pHead, unsigned int k);
//����ķ�ת
ListNode* reverseList(ListNode* head);

/*
����һ���������ͷ�ڵ�head��ʵ��һ������������ĺ�����ʹ��ÿk���ڵ�֮������
�����󲻹�k���ڵ�һ�飬�򲻵�����󼸸��ڵ㡣

���磺

����1->2->3->4->5->6->7->8->null��k��3

������3->2->1->6->5->4->7->8->null
*/
ListNode* reverseKnode(ListNode* head, int K);

//����ת
ListNode* reverseList(ListNode* begin, ListNode* end);

//��ת�����е�һ������
ListNode* reverseOneGroup(ListNode* pre, ListNode* end);

/*�ϲ�������������*/
ListNode* mergeList(ListNode* pHead1, ListNode* pHead2);


/***********************************************
����Ϊ���Դ��룬����֤�������ȷ��
*************************************************/
ListNode* Test_reverseKnode(ListNode* head, int K);

//��תpre��end֮��Ľڵ�
ListNode* Test_reverseOneGroup(ListNode* pre, ListNode* end);
