#include "stdafx.h"
#include "List.h"

//���ӽڵ�
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
	{
		return;
	}

	pCurrent->next = pNext;

}

// ��ӡ����
void printList(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}

	ListNode* current = pHead;
	cout << "�����ͷ��β�ڵ�����Ϊ:";
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

//��������
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
	//Ҫ���ǵ�ɾ������ͷ�ڵ㻹��β�ڵ�

	if (n < 0 || head == nullptr)
	{
		return nullptr;
	}

	// ��������ָ�룬ָ��ĵ�ַ���Ϊ n
	ListNode* pFirst = head;
	ListNode* pLast = head;
	ListNode* pre = head;

	int count = 1;
	while (pFirst != nullptr && count < n)    //first������ n ��
	{
		pFirst = pFirst->next;
		count++;
	}

	if (pFirst == nullptr)    //���pFirst�ߵ���ĩβ�� 
	{
		return nullptr;
	}

	while (pFirst->next != nullptr)
	{
		pre = pLast;
		pLast = pLast->next;
		pFirst = pFirst->next;
	}

	//��ʱpLast �� pFirst֮����� n   pLastָ��ľ���Ҫɾ����Ԫ��

	if (pLast == head)        //���ɾ������ͷ�ڵ�
	{
		return head->next;    //����ͷ�ڵ����һ���ڵ�
	}

	pre->next = pLast->next;
	return head;
}

//21. Merge Two Sorted Lists  ���õݹ鷽��
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

//����ѭ���ķ�ʽ
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

	//�������һ���������  ��һ��û�����
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