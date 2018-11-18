#include "stdafx.h"
#include "List.h"

//连接节点
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
	{
		return;
	}

	pCurrent->next = pNext;

}

// 打印链表
void printList(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}

	ListNode* current = pHead;
	cout << "链表从头到尾节点依次为:";
	while (current != nullptr)
	{
		if (current->next == nullptr)
		{
			cout << current->val;
		}
		else
		{
			cout << current->val << "-->>";
		}
		
		current = current->next;
	}
	cout << endl;
}

//销毁链表
void DestroyList(ListNode* head)
{
	if (head == nullptr)
	{
		return;
	}
	
	ListNode* current = head;
	ListNode* pre;
	while (current != nullptr)
	{
		pre = current;
		current = current->next;
		delete pre;
	}
}

//  leetcode 19. Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	//要考虑到删除的是头节点还是尾节点

	if (n < 0 || head == nullptr)
	{
		return nullptr;
	}

	// 定义两个指针，指针的地址相减为 n
	ListNode* pFirst = head;
	ListNode* pLast = head;
	ListNode* pre = head;

	int count = 1;
	while (pFirst != nullptr && count < n)    //first首先走 n 步
	{
		pFirst = pFirst->next;
		count++;
	}

	if (pFirst == nullptr)    //如果pFirst走到了末尾， 
	{
		return nullptr;
	}

	while (pFirst->next != nullptr)
	{
		pre = pLast;
		pLast = pLast->next;
		pFirst = pFirst->next;
	}

	//此时pLast 和 pFirst之间相差 n   pLast指向的就是要删除的元素

	if (pLast == head)        //如果删除的是头节点
	{
		return head->next;    //返回头节点的下一个节点
	}

	pre->next = pLast->next;
	return head;
}

//21. Merge Two Sorted Lists  采用递归方法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	
	if (l1 == nullptr && l2 == nullptr)
	{
		return nullptr;
	}
	if (l1 == nullptr && l2 != nullptr)
	{
		return l2;
	}

	if (l2 == nullptr && l1 != nullptr)
	{
		return l1;
	}

	ListNode* result; 
	if (l1->val < l2->val)
	{
		result = l1;
		result->next = mergeTwoLists(l1->next, l2);
	}
	else
	{
		result = l2;
		result->next = mergeTwoLists(l1, l2->next);
	}
	return result;
}

//采用循环的方式
ListNode* mergeTwoListsCycle(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr)
	{
		return l2;
	}

	if (l2 == nullptr)
	{
		return l1;
	}
	ListNode* dumpy = new ListNode(-1);

	ListNode* node1 = l1;
	ListNode* node2 = l2;

	ListNode* cursor = dumpy;

	while (node1 != nullptr && node2 != nullptr)
	{
		if (node1->val < node2->val)
		{
			cursor->next = node1;
			node1 = node1->next;
			cursor = cursor->next;
		}
		else
		{
			cursor->next = node2;
			node2 = node2->next;
			cursor = cursor->next;

		}
	}

	//如果链表一个遍历完成  另一个没有完成
	while (node1 != nullptr)
	{
		cursor->next = node1;
		node1 = node1->next;
		cursor = cursor->next;
	}

	while (node2 != nullptr)
	{
		cursor->next = node2;
		node2 = node2->next;
		cursor = cursor->next;
	}
		
	return dumpy->next;

}