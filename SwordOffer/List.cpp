#include "stdafx.h"
#include "List.h"


//创建ListNode节点
ListNode* CreateListNode(int value) 
{
	ListNode* node = new ListNode();
	node->value = value;
	node->pNext = nullptr;
	return node;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
	if (pCurrent != nullptr) {
		pCurrent->pNext = pNext;
	}

}
void PrintListNode(ListNode* pNode) {
	if (pNode == nullptr)
	{
		cout << "the node is null" << endl;
	}
	else
	{
		cout << "the key in node is " << pNode->value << endl;
	}

}

void PrintList(ListNode* pHead) {
	while (pHead != nullptr) {
		cout << pHead->value << " ";
		pHead = pHead->pNext;
	}
	cout << endl;
}

void DestroyList(ListNode* pHead) {
	ListNode *tobeDeleted;
	tobeDeleted = pHead;
	while (tobeDeleted != nullptr)
	{
		pHead = pHead->pNext;
		delete tobeDeleted;
		tobeDeleted = pHead;
	}

}
//在尾节点添加节点
void AddToTail(ListNode** pHead, int value) {
	ListNode* pNew = new ListNode();
	pNew->pNext = nullptr;
	pNew->value = value;

	//如果该链表为空链表
	if ((*pHead) == nullptr)
	{
		*pHead = pNew;
		return;
	}

	//该链表不为空
	ListNode* pNode = *pHead;
	while (pNode->pNext != nullptr)
	{
		pNode = pNode->pNext;
	}
	pNode->pNext = pNew;
}
//删除节点 时间复杂度为O(n)
void RemoveNode(ListNode** pHead, int value) {
	if (pHead == nullptr || (*pHead)==nullptr)
	{
		return;
	}

	//如果删除的节点为头节点
	if ((*pHead)->value == value)
	{
		delete *pHead;
		*pHead = nullptr;
	}

	//查找到要删除的节点的前一个节点
	ListNode* pNode = *pHead;
	while (pNode->pNext != nullptr && pNode->pNext->value != value)
	{
		pNode = pNode->pNext;
	}
	//此时pNode节点为删除节点的前一个节点
	if (pNode->pNext != nullptr && pNode->pNext->value == value)
	{
		ListNode* tobeDeleted = pNode->pNext;
		pNode->pNext = pNode->pNext->pNext;
		delete tobeDeleted;
	}

}

//逆序打印链表中的节点
void printReverse(ListNode* pHead) {
	if (pHead == nullptr) {
		return;
	}
	printReverse(pHead->pNext);
	cout << pHead->value << " ";
}

//删除链表中的节点  时间复杂度为O（1）
void DeleteNode(ListNode** pHead, ListNode* tobeDeleted) {
	if ((*pHead) == nullptr || tobeDeleted == nullptr || pHead == nullptr)
	{
		return;
	}
	//如果要删除的节点不是尾节点
	if (tobeDeleted->pNext != nullptr)
	{
		ListNode* pNode = tobeDeleted->pNext;
		tobeDeleted->pNext = pNode->pNext;
		tobeDeleted->value = pNode->value;
		delete pNode;
		pNode = nullptr;
		return;
	}
	//如果只有一个节点 要删除头节点

	if ((*pHead) == tobeDeleted)
	{
		delete *pHead;
		*pHead = nullptr;
		return;
	}

	//要删除的节点为尾节点 只能遍历到要删除的节点的前一个节点
	ListNode* pNode = *pHead;
	while (pNode->pNext != nullptr && pNode->pNext != tobeDeleted) {
		pNode = pNode->pNext;
	}
	//此时的pNode节点为删除节点的前一个节点
	delete tobeDeleted;
	pNode->pNext = nullptr;
	tobeDeleted = nullptr;

}


//快速排序
void QuickSort(vector<int> & array, int low, int high) {
	int pos;
	if (low < high) {
		pos = FindPos(array, low, high);
		QuickSort(array, low, pos - 1);
		QuickSort(array, pos + 1, high);
	}
}

int FindPos(vector<int> & array, int low, int high) {
	int left = low;
	int right = high;
	int pivot = array[left];   //用最左侧的节点作为枢纽
	while (left < right) {
		while (left < right && array[right] >= pivot) {
			right--;
		}
		//交换枢纽和起始位置
		if (left < right) {
			array[left] = array[right];
		}

		while (left < right && array[left] < pivot) {
			left++;
		}

		if (left < right) {
			array[right] = array[left];
		}
	}
	array[left] = pivot;
	return right;

}

//链表排序
/*
    链表排序的思路是  先把数据放到数组中，然后采用高效的排序算法，然后放到链表中
*/
void ListSort(ListNode** pHead) {
	if (pHead == nullptr || (*pHead) == nullptr) {
		return;
	}
	vector<int> data;
	ListNode* pNode = *pHead;
	while (pNode != nullptr)
	{
		data.push_back(pNode->value);
		pNode = pNode->pNext;
	}

	//对数组进行快速排序
	QuickSort(data,0,data.size()-1);
	pNode = *pHead;

	//将排序后的数据依次复制到List中
	int i = 0;
	while (pNode != nullptr)
	{
		int temp = data.at(i);
		pNode->value = temp;		
		pNode = pNode->pNext;
		i++;
	}

}

//删除一个链表中重复的节点  此链表为排序的链表
void deleteDuplication(ListNode** pHead) {
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode* pNode = (*pHead)->pNext;
	ListNode* pPreNode = *pHead;
	ListNode* tobeDeleted = nullptr;
	while (pNode != nullptr)
	{
		if (pPreNode->value == pNode->value) 
		{
			tobeDeleted = pNode;
		}
		else
		{
			pPreNode = pNode;
		}
		pNode = pNode->pNext;
		//删除节点
		if (tobeDeleted != nullptr)
		{
			pPreNode->pNext = pNode;    //链表建立连接
			delete tobeDeleted;
			tobeDeleted = nullptr;
		}
	}
}

//找到链表的倒数K个节点   只能遍历一次链表
ListNode* findKthToTail(ListNode* pHead, unsigned int k) {
	if (pHead == nullptr || k < 1)
	{
		return nullptr;	 
	}
	ListNode* pBehind;
	ListNode* pBefore = pHead;
	for (unsigned int i = k-1; i > 0; i--)
	{
		pBefore = pBefore->pNext;
	}

	pBehind = pHead;
	while (pBefore->pNext != nullptr)
	{
		pBefore = pBefore->pNext;
		pBehind = pBehind->pNext;
	}
	return pBehind;

}

//链表的反转
ListNode* reverseList(ListNode* head)
{
	ListNode* node, *pre, *next;
	node = head;
	pre = nullptr;
	
	while (node->pNext != nullptr)
	{
		next = node->pNext;
		node->pNext = pre;
		pre = node;
		node = next;
	}

	node->pNext = pre;
	return node;

}

/*
//反转链表
// 根绝链表的起始节点和终止节点进行反转
// 返回值： 反转后链表的起始节点
*/

ListNode* reverseList(ListNode* begin, ListNode* end)
{
	if (begin == end)
	{
		return begin;		 
	}
	ListNode* node = begin;
	ListNode* pre = nullptr;
	ListNode* next;
	while (node != end)
	{
		next = node->pNext;
		node->pNext = pre;
		pre = node;
		node = next;
	}
	node->pNext = pre;
	return node;
}

/*
   反转一组链表节点
   把pre和next之间的链表反转
*/

ListNode* reverseOneGroup(ListNode* pre, ListNode* end)
{
	
	ListNode* node = pre->pNext;
	ListNode* previous = nullptr;
	ListNode* next;
	while (node != end)
	{
		next = node->pNext;
		node->pNext = previous;
		previous = node;
		node = next;
	}
	pre->pNext->pNext = end;
	ListNode* result = pre->pNext;
	pre->pNext = previous;

	return result;
}
/*
   给出一个链表和一个数k，比如链表1→2→3→4→5→6，k=2，翻转后2→1→4→3→6→5，若k=3,翻转后3→2→1→6→5→4，若k=4，翻转后4→3→2→1→5→6，
   返回值为链表的起始节点

   -1->1->2->3->4->5
   |           |
   pre         next

   -1->3->2->1->4->5
   |  |
   pre next

   以此类推，只要next走过k个节点，就可以调用翻转函数来进行局部翻转了，代码如下所示：


   这道题让我们以每k个为一组来翻转链表，实际上是把原链表分成若干小段，然后分别对其进行翻转，
   那么肯定总共需要两个函数，一个是用来分段的，一个是用来翻转的，我们就以题目中给的例子来看，
   对于给定链表1->2->3->4->5，一般在处理链表问题时，我们大多时候都会在开头再加一个dummy node，
   因为翻转链表时头结点可能会变化，为了记录当前最新的头结点的位置而引入的dummy node，
   那么我们加入dummy node后的链表变为-1->1->2->3->4->5，如果k为3的话，
   我们的目标是将1,2,3翻转一下，那么我们需要一些指针，
   pre和next分别指向要翻转的链表的前后的位置，然后翻转后pre的位置更新到如下新的位置：
*/
ListNode* reverseKnode(ListNode* head, int K)
{
	if (!head || K == 1)
	{
		return head;
	}
	int count = 0;
	//在首节点添加dumpy节点
	ListNode* dumpy = CreateListNode(-1);
	dumpy->pNext = head;

	ListNode* pre = dumpy;
	ListNode* cur = head;

	while (cur)
	{
		count++;
		if (count%K == 0)
		{
			//反转
			pre = reverseOneGroup(pre,cur->pNext);
			cur = pre->pNext;
		}
		else
		{
			cur = cur->pNext;
		}
	}
	return dumpy->pNext;

}

/*
   两个链表都是有序链表，合并
*/
ListNode* mergeList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
	{
		return pHead2;
	}
	else if (pHead2 == nullptr)
	{
		return pHead2;
	}

	ListNode* mergeListResult = nullptr;    //定义合并后链表的首节点指针

	if (pHead1->value < pHead2->value)
	{
		mergeListResult = pHead1;
		mergeListResult->pNext = mergeList(pHead1->pNext, pHead2);
	}
	else
	{
		mergeListResult = pHead2;
		mergeListResult->pNext = mergeList(pHead1, pHead2->pNext);
	}

	return mergeListResult;
}


/*
   以下为测试代码，不保证代码的正确性
*/

ListNode* Test_reverseKnode(ListNode* head, int K)
{
	if (!head || K == 1)
	{
		return head;
	}

	ListNode* dumpy = CreateListNode(-1);
	dumpy->pNext = head;
	ListNode* pre = dumpy;
	ListNode* cur = head;    //从head节点依次向下查找K个节点
	int count = 0;           //统计当前向下遍历的节点

	while (cur)
	{
		count++;
		if (count%K == 0)
		{
			//满足K个节点  则进行旋转
			pre = Test_reverseOneGroup(pre,cur->pNext);
			cur = pre->pNext;


		}
		else
		{
			cur = cur->pNext;
		}
		

	}
	return dumpy->pNext;

}

ListNode* Test_reverseOneGroup(ListNode* pre, ListNode* end)
{
	ListNode* node = pre->pNext;
	ListNode* next;
	ListNode* previous = nullptr;

	while (node != end)
	{
		next = node->pNext;
		node->pNext = previous;
		previous = node;
		node = next;
	}
	ListNode* result = pre->pNext;
	pre->pNext->pNext = end;
	pre->pNext = previous;
	
	return result;

}