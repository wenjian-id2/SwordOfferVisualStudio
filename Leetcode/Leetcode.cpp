// Leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ContainMostWater.h"
#include "List.h"
#include <iostream>
using std::cin;
using std::endl;
using std::cout;

//�������������ˮ
void TestContainMostWater()
{
	cout << "******************************************************************" << endl;
	cout << "���ˮ��������:��������Ϊ";
	vector<int> height;
	height.clear();

	//[1,8,6,2,5,4,8,3,7]
	height.push_back(1);
	height.push_back(8);
	height.push_back(6);
	height.push_back(2);
	height.push_back(5);
	height.push_back(4);
	height.push_back(8);
	height.push_back(3);
	height.push_back(7);

	for (size_t i = 0; i < height.size(); i++)
	{
		cout << height.at(i) << " ";
	}
	cout << endl;
	cout << "������Ϊ:" << maxArea(height) << endl;
}

//��������ת��Ϊ������
void  TestIntgerToRoman()
{

	cout << "******************************************************************" << endl;
	int num = 1994;
	cout << "��������ת��Ϊ��������,��������Ϊ" << num << ",����ַ���Ϊ:";
	cout << intToRoman(num) << endl;
	

}

//������������ת��Ϊ����
void TestRomanToIntger()
{
	cout << "******************************************************************" << endl;
	string str = "MCMXCIV";
	cout << "������������ת��Ϊ����,�����ַ���Ϊ" << str << ",�������Ϊ:";
	cout << RomanToInt(str) << endl;
}


////letcode 14�� 14.Longest Common Prefix

void TestLongestCommonPrefix()
{
	cout << "******************************************************************" << endl;
	
	const char* str[] = { "flower", "flow", "flight" };  
//	const char* str[] = { "c", "c"};
	vector<string> strs(str,str+3);


	cout << "����������ַ�ǰ׺,�����ַ�������Ϊ��";
	for (size_t i = 0; i < strs.size(); i++)
	{
		cout << strs.at(i) << " ";
	}
	cout << endl;
	cout << "�����ǰ׺Ϊ: ";
	cout << longestCommonPrefix(strs) << endl;


}

//leetcode �� 15�� 3�����ĺ�Ϊ0
void  TestThreeSum()
{
	cout << "******************************************************************" << endl;
	cout << "�����������ĺ�Ϊ0 ,������������Ϊ��";
	
	int array[] = { -1, 0, 1, 2, -1, -4 };
//	int array[] = { 0,0,0 };
	vector<int> data(array, array+6);

	for (size_t i = 0; i < data.size(); i++)
	{
		cout << data.at(i) << " ";
	}
	cout << endl;
	cout << "������Ϊ:";
	vector<vector<int>> result = threeSum(data);
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << "��" << i << "����Ϊ:";
		for (size_t j = 0; j < result.at(i).size(); j++)
		{
			cout << result.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

//leetcode ��16�� 3 sum closet
void TestThreeSumClosest()
{
	cout << "******************************************************************" << endl;
	cout << "�����������ĺ���Ŀ��ֵ��� ,������������Ϊ��";

//	int array[] = { -1, 2, 1, -4 }; 
	//	int array[] = { 0,0,0 };  []
//	int array[] = { 0, 2, 1, -3 };
	int array[] = { 1, 1, -1, -1, 3 };
	vector<int> data(array, array + 5);

	for (size_t i = 0; i < data.size(); i++)
	{
		cout << data.at(i) << " ";
	}
	cout << endl;
	int target = -1;
	cout << "Ŀ��ֵΪ:" << target<< endl;
	cout << "�����������Ϊ:";
	int result = threeSumClosest(data, target);
	cout << result << endl;
}

//����������������ĺϲ�  ���������ظ���Ԫ��
void TestMergeArray()
{
	int array1[] = { -1, 1, 1, 2, 3, 4, 10, 10 };
	vector<int> vec1(array1, array1 + 8);

	int array2[] = { -1, 3, 5, 6, 7, 8, 8 };
	vector<int> vec2(array2, array2 + 7);

	vector<int> result = mergeArray(vec1, vec2);

	cout << "******************************************************************" << endl;
	cout << "����������������ĺϲ�."<< endl;
	cout << "��������1��";
	for (size_t i = 0; i < vec1.size(); i++)
	{
		cout << vec1.at(i) << " ";
	}
	cout << endl;

	cout << "��������2��";
	for (size_t i = 0; i < vec2.size(); i++)
	{
		cout << vec2.at(i) << " ";
	}
	cout << endl;

	cout << "�ϲ������飺";
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result.at(i) << " ";
	}
	cout << endl;

}


//leetcode 17. Letter Combinations of a Phone Number
void TestletterCombinations()
{
	cout << "******************************************************************" << endl;
	cout << "�����ֻ����ֵ�ȫ����." << endl;
	string strInput = "23";
	cout << "���������ַ���Ϊ��"+strInput;

	vector<string> result = letterCombinations(strInput);

	cout << "���Ϊ:"<< endl;

	int length = result.size();
	for (size_t i = 0; i < length; i++)
	{
		cout << result.at(i) << endl;
	}
}


// �������
void TestList()
{
	ListNode* pHead = new ListNode(1);
	ListNode* pNode2 = new ListNode(2);
	ListNode* pNode3 = new ListNode(3);
	ListNode* pNode4 = new ListNode(4);
	ListNode* pNode5 = new ListNode(5);

	ConnectListNodes(pHead, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	cout << "******************************************************************" << endl;
	cout << "��������" << endl;


	cout << "��ӡ����:"<< endl;
	printList(pHead);

	////  leetcode 19. Remove Nth Node From End of List

	int k = 1;

	cout << "ɾ����β�ڵ���˵�ĵ�����" << k << "���ڵ�" << endl;

	cout << "��ӡɾ���ڵ�������"<< endl;
	ListNode* node = removeNthFromEnd(pHead, k);
	printList(node);

	DestroyList(pHead);
}

//leetcode 20. Valid Parentheses
void TestValidString()
{
	cout << "******************************************************************" << endl;
	cout << "�ַ����Ƿ���Ч,�ַ�����������Ϊ '(', ')', '{', '}', '[' and ']'" << endl;
	string str = "]";
	cout << "�����ַ���Ϊ:" << str << endl;
	cout << "�ַ����Ƿ��ǳɶԳ���:" << isValid(str) << endl;
}

//21. Merge Two Sorted Lists
void TestMergeList()
{
	cout << "******************************************************************" << endl;
	cout << "����������������ĺϲ������õݹ鷽��" << endl;

	ListNode* pMerge1Node1 = new ListNode(1);
	ListNode* pMerge1Node2 = new ListNode(2);
	ListNode* pMerge1Node3 = new ListNode(4);

	ConnectListNodes(pMerge1Node1, pMerge1Node2);
	ConnectListNodes(pMerge1Node2, pMerge1Node3);

	ListNode* pMerge2Node1 = new ListNode(1);
	ListNode* pMerge2Node2 = new ListNode(3);
	ListNode* pMerge2Node3 = new ListNode(5);
	ListNode* pMerge2Node4 = new ListNode(6);

	ConnectListNodes(pMerge2Node1, pMerge2Node2);
	ConnectListNodes(pMerge2Node2, pMerge2Node3);
	ConnectListNodes(pMerge2Node3, pMerge2Node4);

	cout << "����1��";
	printList(pMerge1Node1);
	cout << "����2��";
	printList(pMerge2Node1);

	cout << "�ϲ�������Ϊ:";
	ListNode* result = mergeTwoLists(pMerge1Node1, pMerge2Node1);
	printList(result);

	DestroyList(result);

	//���Ժϲ��������õݹ�ķ�ʽ
	cout << "******************************************************************" << endl;
	cout << "����������������ĺϲ��������õݹ鷽��" << endl;

	ListNode* pMerge3Node1 = new ListNode(1);
	ListNode* pMerge3Node2 = new ListNode(2);
	ListNode* pMerge3Node3 = new ListNode(4);

	ConnectListNodes(pMerge3Node1, pMerge3Node2);
	ConnectListNodes(pMerge3Node2, pMerge3Node3);

	ListNode* pMerge4Node1 = new ListNode(1);
	ListNode* pMerge4Node2 = new ListNode(3);
	ListNode* pMerge4Node3 = new ListNode(5);
	ListNode* pMerge4Node4 = new ListNode(6);

	ConnectListNodes(pMerge4Node1, pMerge4Node2);
	ConnectListNodes(pMerge4Node2, pMerge4Node3);
	ConnectListNodes(pMerge4Node3, pMerge4Node4);

	cout << "����1��";
	printList(pMerge3Node1);
	cout << "����2��";
	printList(pMerge4Node1);

	cout << "�ϲ�������Ϊ:";
	ListNode* result2 = mergeTwoListsCycle(pMerge3Node1, pMerge4Node1);
	printList(result2);

	DestroyList(result2);
	

}
int _tmain(int argc, _TCHAR* argv[])
{
	//�������������ˮ
	TestContainMostWater();
	//��������ת��Ϊ������
	TestIntgerToRoman();
	//������������ת��Ϊ����
	TestRomanToIntger();
	////letcode 14�� 14.Longest Common Prefix
	TestLongestCommonPrefix();

	//leetcode �� 15�� 3�����ĺ�Ϊ0
	TestThreeSum();

	//leetcode ��16�� 3 sum closet
	TestThreeSumClosest();

	//����������������ĺϲ�  ���������ظ���Ԫ��
	TestMergeArray();

	//leetcode 17. Letter Combinations of a Phone Number
	TestletterCombinations();

	// �������
	TestList();

	//leetcode 20. Valid Parentheses
	TestValidString();

	//21. Merge Two Sorted Lists
	TestMergeList();

	return 0;
}

