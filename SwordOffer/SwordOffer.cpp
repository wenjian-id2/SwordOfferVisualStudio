// SwordOffer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "MyString.h"
#include "List.h"
#include "Tree.h"
#include "StackWithMin.h"
#include "StackSample.h"
#include "DoubleList.h"

bool(*func)(int);

void ListTest() {
	cout << "��������" << endl;
	ListNode* pNode1 = CreateListNode(1);
	AddToTail(&pNode1, 2);
	AddToTail(&pNode1, 6);
	AddToTail(&pNode1, 3);
	AddToTail(&pNode1, 5);
	AddToTail(&pNode1, 4);
	cout << "��ӡ����:";
	PrintList(pNode1);

//	cout << "����ת����ӡ����:";
//	ListNode* end = pNode1->pNext->pNext->pNext;
//	PrintList(reverseList(pNode1));
	
	cout << "����ÿ2���ڵ㷴ת����ӡ����:";
	PrintList(Test_reverseKnode(pNode1, 2));

	/*���Ժϲ�����*/
	ListNode* pNodeMerge1 = CreateListNode(1);
	AddToTail(&pNodeMerge1, 3);
	AddToTail(&pNodeMerge1, 5);
	AddToTail(&pNodeMerge1, 7);


	ListNode* pNodeMerge2 = CreateListNode(2);
	AddToTail(&pNodeMerge2, 4);
	AddToTail(&pNodeMerge2, 6);
	AddToTail(&pNodeMerge2, 8);
	cout << "�ϲ��������Ϊ:";
	PrintList(mergeList(pNodeMerge1, pNodeMerge2));
    
	//	PrintList(reverseList(pNode1));
	/*
	//ɾ���ڵ�
	cout << "ɾ���ڵ�4��" << endl;
	RemoveNode(&pNode1,4);
	PrintList(pNode1);
	//�����ӡ����
	cout << "�����ӡ����" << endl;
	printReverse(pNode1);
	cout << endl;
	// ɾ���ڵ�
	cout << "ʹ��O(1)�ķ���ɾ����3���ڵ�" << endl;
	DeleteNode(&pNode1, pNode1->pNext->pNext->pNext->pNext);
	PrintList(pNode1);*/
	/*
	unsigned int k = 4;
	cout << "��������ĵ�����" << k << "���ڵ�:" ;
	cout << findKthToTail(pNode1,k)->value;
	cout << endl;
	ListSort(&pNode1);
	cout << "����������Ϊ:" << endl;
	PrintList(pNode1);
	cout << endl;
	cout << "ɾ���ظ���Ԫ�أ�" << endl;
	deleteDuplication(&pNode1);
	PrintList(pNode1); */

}

//����ReorderOddEven����
void ReorderOddEvenTest() {
	int data[] = { -1,2,-3,-4,-5,-6 };
	//ReorderOddEven(data, sizeof(data)/sizeof(int));
	func = isEven;
	ReorderOddEven(data, sizeof(data) / sizeof(int), func);
	unsigned int length = sizeof(data) / sizeof(int);
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;

}

//���Զ������ĺ���
void TestBinaryTree()
{
	BinaryTreeNode* pRoot = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pRoot, pNode1, pNode2);
	ConnectTreeNodes(pNode1, pNode3, pNode4);

	//���Բ�����

	BinaryTreeNode* pFindRoot = CreateBinaryTreeNode(6);
	BinaryTreeNode* pFindNode1 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pFindNode2 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pFindRoot, pFindNode1, pFindNode2);
	cout << "**********************************************" << endl;
	cout << "��1�Ƿ������2:";
	cout << HasSubTree(pRoot, pFindRoot) << endl;

	cout << "**********************************************" << endl;
	cout << "ǰ���ӡ������" << endl;
	PrintBinaryPreorder(pRoot);
	cout << endl;

	cout << "**********************************************" << endl;
	cout << "�������ľ��񣬾����Ķ�����ǰ�������" << endl;

	MirrorTree(pRoot);
	PrintBinaryPreorder(pRoot);
	cout << endl;

	cout << "**********************************************" << endl;
	cout << "�ж�һ���������Ƿ��ǶԳƶ�����" << endl;

	//            8
	//        6      6
	//       5 7    7 5

	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode8, pNode61, pNode62);
	ConnectTreeNodes(pNode61, pNode51, pNode71);
	ConnectTreeNodes(pNode62, pNode72, pNode52);

	cout << "�˶������ǶԳƶ�������" << isSymmetrical(pNode8) << endl;


	DestroyBinary(pRoot);
	DestroyBinary(pFindRoot);


}


void Test(const char* testName, StackWithMin<int>& stack, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	/*
	if (stack.min() == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");  */
}


//��Сջ����
void TestStackWithMin()
{
	
	StackWithMin<int> stack;

//	stack.Push(3);
//	Test("Test1", stack, 3);
	
	/*
	stack.Push(4);
	Test("Test2", stack, 3);

	stack.Push(2);
	Test("Test3", stack, 2);

	stack.Push(3);
	Test("Test4", stack, 2);

	stack.pop();
	Test("Test5", stack, 2);

	stack.pop();
	Test("Test6", stack, 3);

	stack.pop();
	Test("Test7", stack, 3);

	stack.Push(0);  
	Test("Test8", stack, 0); */

}


/*// ������31��ջ��ѹ�롢�������� */
// ====================���Դ���====================
void TestIsPopOrder(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (isPopOrder(pPush, pPop, nLength) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1IsPopOrder()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };

	TestIsPopOrder("Test1", push, pop, nLength, true);
}

void Test2IsPopOrder()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 2, 1 };

	TestIsPopOrder("Test2", push, pop, nLength, true);
}

void Test3IsPopOrder()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 3, 5, 1, 2 };

	TestIsPopOrder("Test3", push, pop, nLength, false);
}

void Test4IsPopOrder()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 1, 2 };

	TestIsPopOrder("Test4", push, pop, nLength, false);
}

// push��pop����ֻ��һ������
void Test5IsPopOrder()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 2 };

	TestIsPopOrder("Test5", push, pop, nLength, false);
}

void Test6IsPopOrder()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 1 };

	TestIsPopOrder("Test6", push, pop, nLength, true);
}

void Test7IsPopOrder()
{
	TestIsPopOrder("Test7", nullptr, nullptr, 0, false);
}

void TestPopOrder()
{
	Test1IsPopOrder();
	Test2IsPopOrder();
	Test3IsPopOrder();
	Test4IsPopOrder();
	Test5IsPopOrder();
	Test6IsPopOrder();
	Test7IsPopOrder();
}

/**********************************************************/
/************* ���Դ��ϵ������δ�ӡ������**********************/

// ====================���Դ���====================
void TestPrintFromTopToBottom(char* testName, BinaryTreeNode* pRoot)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	cout << "������ǰ�������";
	PrintBinaryPreorder(pRoot);
	cout << endl;

	printf("The nodes from top to bottom, from left to right are: \n");
	PrintFromTopToBottom(pRoot);

	printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1PrintFromTopToBottom()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	TestPrintFromTopToBottom("Test1", pNode10);

	DestroyBinary(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2PrintFromTopToBottom()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);
	ConnectTreeNodes(pNode2, pNode1, nullptr);

	TestPrintFromTopToBottom("Test2", pNode5);

	DestroyBinary(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3PrintFromTopToBottom()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, nullptr, pNode2);
	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	TestPrintFromTopToBottom("Test3", pNode1);

	DestroyBinary(pNode1);
}

// ����ֻ��1�����
void Test4PrintFromTopToBottom()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	TestPrintFromTopToBottom("Test4", pNode1);

	DestroyBinary(pNode1);
}

// ����û�н��
void Test5PrintFromTopToBottom()
{
	TestPrintFromTopToBottom("Test5", nullptr);
}

void TestFromTopToBottom()
{
	Test1PrintFromTopToBottom();
	Test2PrintFromTopToBottom();
	Test3PrintFromTopToBottom();
	Test4PrintFromTopToBottom();
	Test5PrintFromTopToBottom();
}

/***********************************************/
/**************���Է��� ���ϵ��´�ӡ������****************/

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void TestPrintFromTopToBottomLines()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	PrintFromTopToBottomLines(pNode10);

	DestroyBinary(pNode10);
}

/***********************************************/
/**************����֮���� ���ϵ��´�ӡ������****************/

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void TestPrintFromTopToBottomZigZag()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	PrintFromTopToBottomZigZag(pNode10);

	DestroyBinary(pNode10);
}

//*********************���Զ������ĺ�����������********************
// ====================���Դ���====================
void TestSquence(const char* testName, int sequence[], int length, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (VerifySquenceOfBST(sequence, length) == expected)
		printf("passed.\n");
	else
		printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1SquenceOfBST()
{
	int data[] = { 4, 8, 6, 12, 16, 14, 10 };
	TestSquence("Test1", data, sizeof(data) / sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2SquenceOfBST()
{
	int data[] = { 4, 6, 7, 5 };
	TestSquence("Test2", data, sizeof(data) / sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3SquenceOfBST()
{
	int data[] = { 1, 2, 3, 4, 5 };
	TestSquence("Test3", data, sizeof(data) / sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4SquenceOfBST()
{
	int data[] = { 5, 4, 3, 2, 1 };
	TestSquence("Test4", data, sizeof(data) / sizeof(int), true);
}

// ����ֻ��1�����
void Test5SquenceOfBST()
{
	int data[] = { 5 };
	TestSquence("Test5", data, sizeof(data) / sizeof(int), true);
}

void Test6SquenceOfBST()
{
	int data[] = { 7, 4, 6, 5 };
	TestSquence("Test6", data, sizeof(data) / sizeof(int), false);
}

void Test7SquenceOfBST()
{
	int data[] = { 4, 6, 12, 8, 16, 14, 10 };
	TestSquence("Test7", data, sizeof(data) / sizeof(int), false);
}

void Test8SquenceOfBST()
{
	TestSquence("Test8", nullptr, 0, false);
}


void TestSquenceOfBST()
{
	Test1SquenceOfBST();
	Test2SquenceOfBST();
	Test3SquenceOfBST();
	Test4SquenceOfBST();
	Test5SquenceOfBST();
	Test6SquenceOfBST();
	Test7SquenceOfBST();
	Test8SquenceOfBST();
}


/*****************************************************************/
/***********************���Զ�������·��****************************/
void TestFindPathCore(char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	FindPath(pRoot, expectedSum);

	printf("\n");
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// ������·���ϵĽ���Ϊ22
void Test1FindPath()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);

	printf("Two paths should be found in Test1.\n");
	TestFindPathCore("Test1", pNode10, 22);

	DestroyBinary(pNode10);
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// û��·���ϵĽ���Ϊ15
void Test2FindPath()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);

	printf("No paths should be found in Test2.\n");
	TestFindPathCore("Test2", pNode10, 15);

	DestroyBinary(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
// ��һ��·������Ľ���Ϊ15
void Test3FindPath()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);
	ConnectTreeNodes(pNode2, pNode1, nullptr);

	printf("One path should be found in Test3.\n");
	TestFindPathCore("Test3", pNode5, 15);

	DestroyBinary(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
// û��·������Ľ���Ϊ16
void Test4FindPath()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, nullptr, pNode2);
	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	printf("No paths should be found in Test4.\n");
	TestFindPathCore("Test4", pNode1, 16);

	DestroyBinary(pNode1);
}

// ����ֻ��1�����
void Test5FindPath()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	printf("One path should be found in Test5.\n");
	TestFindPathCore("Test5", pNode1, 1);

	DestroyBinary(pNode1);
}

// ����û�н��
void Test6FindPath()
{
	printf("No paths should be found in Test6.\n");
	TestFindPathCore("Test6", nullptr, 0);
}

void  TestPath()
{
	Test1FindPath();
	Test2FindPath();
	Test3FindPath();
	Test4FindPath();
	Test5FindPath();
	Test6FindPath();
}


void TestPermutation()
{
	char str[] = "abc";
	Permutation(str);
}

void TestMoreThanHalf()
{
	int data[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << MoreThanHalfNum(data, sizeof(data) / sizeof(int));
	cout << endl;
}


//���� ������40����С��k����

void TestLeastNumbers()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	vector<int> vectorData;
	int n = sizeof(data) / sizeof(int);
	for (int i = 0; i < n; ++i)
		vectorData.push_back(data[i]);

	intSet leastNumbers;
	int k = sizeof(expected) / sizeof(int);
	GetLeastNumbers(vectorData, leastNumbers, k);

	for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
		printf("%d ", *iter);
	printf("\n\n");

}

int main()
{
	//��������
	//ListTest();

	// ���Զ������Ƿ������һ����

	TestBinaryTree();

	cout << "******************************************" << endl;
	cout << "������Сջ" << endl;
	TestStackWithMin();


	cout << "******************************************" << endl;
	cout << "����ջ�ĵ���˳��" << endl;
	TestPopOrder();

	cout << "******************************************" << endl;
	cout << "���Դ��ϵ������δ�ӡ������" << endl;
	TestFromTopToBottom();

	cout << "******************************************" << endl;
	cout << "���Է��д��ϵ������δ�ӡ������" << endl;
	TestPrintFromTopToBottomLines();

	cout << "******************************************" << endl;
	cout << "����֮���δ��ϵ������δ�ӡ������" << endl;
	TestPrintFromTopToBottomZigZag();

	cout << "******************************************" << endl;
	cout << "���������������ĺ�����������" << endl;
	TestSquenceOfBST();

	
	cout << "******************************************" << endl;
	cout << "���Զ�������·���ĺ�Ϊĳһ·��" << endl;
	TestPath(); 

	cout << "******************************************" << endl;
	cout << "�����ַ���������:" << endl;
	TestPermutation();

	cout << "******************************************" << endl;
	cout << "�������������ִ�������һ�������:" << endl;
	TestMoreThanHalf();

	cout << "******************************************" << endl;
	cout << "��С��k����:" << endl;
	TestLeastNumbers();


	/*
	//�ַ���ƥ��
	char str[] = "aab";
	char patten[] = "a.b";

	cout << match(str, patten) << endl;

	//�ַ����Ƿ�������
	const char* strNum = "5e2";
	cout << "�ַ���" << strNum << "�Ƿ�������:";
	cout << isNumber(strNum) << endl;

	//����ReorderOddEven����
	cout << "����ReorderOddEven����" << endl;
	ReorderOddEvenTest(); */

}


