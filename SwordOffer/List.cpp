#include "stdafx.h"
#include "List.h"


//����ListNode�ڵ�
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
//��β�ڵ���ӽڵ�
void AddToTail(ListNode** pHead, int value) {
	ListNode* pNew = new ListNode();
	pNew->pNext = nullptr;
	pNew->value = value;

	//���������Ϊ������
	if ((*pHead) == nullptr)
	{
		*pHead = pNew;
		return;
	}

	//������Ϊ��
	ListNode* pNode = *pHead;
	while (pNode->pNext != nullptr)
	{
		pNode = pNode->pNext;
	}
	pNode->pNext = pNew;
}
//ɾ���ڵ� ʱ�临�Ӷ�ΪO(n)
void RemoveNode(ListNode** pHead, int value) {
	if (pHead == nullptr || (*pHead)==nullptr)
	{
		return;
	}

	//���ɾ���Ľڵ�Ϊͷ�ڵ�
	if ((*pHead)->value == value)
	{
		delete *pHead;
		*pHead = nullptr;
	}

	//���ҵ�Ҫɾ���Ľڵ��ǰһ���ڵ�
	ListNode* pNode = *pHead;
	while (pNode->pNext != nullptr && pNode->pNext->value != value)
	{
		pNode = pNode->pNext;
	}
	//��ʱpNode�ڵ�Ϊɾ���ڵ��ǰһ���ڵ�
	if (pNode->pNext != nullptr && pNode->pNext->value == value)
	{
		ListNode* tobeDeleted = pNode->pNext;
		pNode->pNext = pNode->pNext->pNext;
		delete tobeDeleted;
	}

}

//�����ӡ�����еĽڵ�
void printReverse(ListNode* pHead) {
	if (pHead == nullptr) {
		return;
	}
	printReverse(pHead->pNext);
	cout << pHead->value << " ";
}

//ɾ�������еĽڵ�  ʱ�临�Ӷ�ΪO��1��
void DeleteNode(ListNode** pHead, ListNode* tobeDeleted) {
	if ((*pHead) == nullptr || tobeDeleted == nullptr || pHead == nullptr)
	{
		return;
	}
	//���Ҫɾ���Ľڵ㲻��β�ڵ�
	if (tobeDeleted->pNext != nullptr)
	{
		ListNode* pNode = tobeDeleted->pNext;
		tobeDeleted->pNext = pNode->pNext;
		tobeDeleted->value = pNode->value;
		delete pNode;
		pNode = nullptr;
		return;
	}
	//���ֻ��һ���ڵ� Ҫɾ��ͷ�ڵ�

	if ((*pHead) == tobeDeleted)
	{
		delete *pHead;
		*pHead = nullptr;
		return;
	}

	//Ҫɾ���Ľڵ�Ϊβ�ڵ� ֻ�ܱ�����Ҫɾ���Ľڵ��ǰһ���ڵ�
	ListNode* pNode = *pHead;
	while (pNode->pNext != nullptr && pNode->pNext != tobeDeleted) {
		pNode = pNode->pNext;
	}
	//��ʱ��pNode�ڵ�Ϊɾ���ڵ��ǰһ���ڵ�
	delete tobeDeleted;
	pNode->pNext = nullptr;
	tobeDeleted = nullptr;

}


//��������
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
	int pivot = array[left];   //�������Ľڵ���Ϊ��Ŧ
	while (left < right) {
		while (left < right && array[right] >= pivot) {
			right--;
		}
		//������Ŧ����ʼλ��
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

//��������
/*
    ���������˼·��  �Ȱ����ݷŵ������У�Ȼ����ø�Ч�������㷨��Ȼ��ŵ�������
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

	//��������п�������
	QuickSort(data,0,data.size()-1);
	pNode = *pHead;

	//���������������θ��Ƶ�List��
	int i = 0;
	while (pNode != nullptr)
	{
		int temp = data.at(i);
		pNode->value = temp;		
		pNode = pNode->pNext;
		i++;
	}

}

//ɾ��һ���������ظ��Ľڵ�  ������Ϊ���������
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
		//ɾ���ڵ�
		if (tobeDeleted != nullptr)
		{
			pPreNode->pNext = pNode;    //����������
			delete tobeDeleted;
			tobeDeleted = nullptr;
		}
	}
}

//�ҵ�����ĵ���K���ڵ�   ֻ�ܱ���һ������
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

//����ķ�ת
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
//��ת����
// �����������ʼ�ڵ����ֹ�ڵ���з�ת
// ����ֵ�� ��ת���������ʼ�ڵ�
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
   ��תһ������ڵ�
   ��pre��next֮�������ת
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
   ����һ�������һ����k����������1��2��3��4��5��6��k=2����ת��2��1��4��3��6��5����k=3,��ת��3��2��1��6��5��4����k=4����ת��4��3��2��1��5��6��
   ����ֵΪ�������ʼ�ڵ�

   -1->1->2->3->4->5
   |           |
   pre         next

   -1->3->2->1->4->5
   |  |
   pre next

   �Դ����ƣ�ֻҪnext�߹�k���ڵ㣬�Ϳ��Ե��÷�ת���������оֲ���ת�ˣ�����������ʾ��


   �������������ÿk��Ϊһ������ת����ʵ�����ǰ�ԭ����ֳ�����С�Σ�Ȼ��ֱ������з�ת��
   ��ô�϶��ܹ���Ҫ����������һ���������ֶεģ�һ����������ת�ģ����Ǿ�����Ŀ�и�������������
   ���ڸ�������1->2->3->4->5��һ���ڴ�����������ʱ�����Ǵ��ʱ�򶼻��ڿ�ͷ�ټ�һ��dummy node��
   ��Ϊ��ת����ʱͷ�����ܻ�仯��Ϊ�˼�¼��ǰ���µ�ͷ����λ�ö������dummy node��
   ��ô���Ǽ���dummy node��������Ϊ-1->1->2->3->4->5�����kΪ3�Ļ���
   ���ǵ�Ŀ���ǽ�1,2,3��תһ�£���ô������ҪһЩָ�룬
   pre��next�ֱ�ָ��Ҫ��ת�������ǰ���λ�ã�Ȼ��ת��pre��λ�ø��µ������µ�λ�ã�
*/
ListNode* reverseKnode(ListNode* head, int K)
{
	if (!head || K == 1)
	{
		return head;
	}
	int count = 0;
	//���׽ڵ����dumpy�ڵ�
	ListNode* dumpy = CreateListNode(-1);
	dumpy->pNext = head;

	ListNode* pre = dumpy;
	ListNode* cur = head;

	while (cur)
	{
		count++;
		if (count%K == 0)
		{
			//��ת
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
   �������������������ϲ�
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

	ListNode* mergeListResult = nullptr;    //����ϲ���������׽ڵ�ָ��

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
   ����Ϊ���Դ��룬����֤�������ȷ��
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
	ListNode* cur = head;    //��head�ڵ��������²���K���ڵ�
	int count = 0;           //ͳ�Ƶ�ǰ���±����Ľڵ�

	while (cur)
	{
		count++;
		if (count%K == 0)
		{
			//����K���ڵ�  �������ת
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