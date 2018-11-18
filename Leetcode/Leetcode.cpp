// Leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ContainMostWater.h"
#include "List.h"
#include <iostream>
using std::cin;
using std::endl;
using std::cout;

//测试最多容器的水
void TestContainMostWater()
{
	cout << "******************************************************************" << endl;
	cout << "最多水容器测试:输入数据为";
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
	cout << "计算结果为:" << maxArea(height) << endl;
}

//测试整数转化为罗马数
void  TestIntgerToRoman()
{

	cout << "******************************************************************" << endl;
	int num = 1994;
	cout << "测试整数转化为罗马数字,输入数字为" << num << ",输出字符串为:";
	cout << intToRoman(num) << endl;
	

}

//测试罗马数字转化为整数
void TestRomanToIntger()
{
	cout << "******************************************************************" << endl;
	string str = "MCMXCIV";
	cout << "测试罗马数字转化为整数,输入字符串为" << str << ",输出数字为:";
	cout << RomanToInt(str) << endl;
}


////letcode 14题 14.Longest Common Prefix

void TestLongestCommonPrefix()
{
	cout << "******************************************************************" << endl;
	
	const char* str[] = { "flower", "flow", "flight" };  
//	const char* str[] = { "c", "c"};
	vector<string> strs(str,str+3);


	cout << "测试最长公共字符前缀,输入字符串数组为：";
	for (size_t i = 0; i < strs.size(); i++)
	{
		cout << strs.at(i) << " ";
	}
	cout << endl;
	cout << "最长公共前缀为: ";
	cout << longestCommonPrefix(strs) << endl;


}

//leetcode 的 15题 3个数的和为0
void  TestThreeSum()
{
	cout << "******************************************************************" << endl;
	cout << "测试三个数的和为0 ,输入整数数组为：";
	
	int array[] = { -1, 0, 1, 2, -1, -4 };
//	int array[] = { 0,0,0 };
	vector<int> data(array, array+6);

	for (size_t i = 0; i < data.size(); i++)
	{
		cout << data.at(i) << " ";
	}
	cout << endl;
	cout << "输出结果为:";
	vector<vector<int>> result = threeSum(data);
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << "第" << i << "组结果为:";
		for (size_t j = 0; j < result.at(i).size(); j++)
		{
			cout << result.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

//leetcode 第16题 3 sum closet
void TestThreeSumClosest()
{
	cout << "******************************************************************" << endl;
	cout << "测试三个数的和与目标值最近 ,输入整数数组为：";

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
	cout << "目标值为:" << target<< endl;
	cout << "最靠近的输出结果为:";
	int result = threeSumClosest(data, target);
	cout << result << endl;
}

//测试两个有序数组的合并  数组中有重复的元素
void TestMergeArray()
{
	int array1[] = { -1, 1, 1, 2, 3, 4, 10, 10 };
	vector<int> vec1(array1, array1 + 8);

	int array2[] = { -1, 3, 5, 6, 7, 8, 8 };
	vector<int> vec2(array2, array2 + 7);

	vector<int> result = mergeArray(vec1, vec2);

	cout << "******************************************************************" << endl;
	cout << "测试两个有序数组的合并."<< endl;
	cout << "输入数组1：";
	for (size_t i = 0; i < vec1.size(); i++)
	{
		cout << vec1.at(i) << " ";
	}
	cout << endl;

	cout << "输入数组2：";
	for (size_t i = 0; i < vec2.size(); i++)
	{
		cout << vec2.at(i) << " ";
	}
	cout << endl;

	cout << "合并后数组：";
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
	cout << "测试手机数字的全排序." << endl;
	string strInput = "23";
	cout << "输入数字字符串为："+strInput;

	vector<string> result = letterCombinations(strInput);

	cout << "结果为:"<< endl;

	int length = result.size();
	for (size_t i = 0; i < length; i++)
	{
		cout << result.at(i) << endl;
	}
}


// 链表操作
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
	cout << "测试链表：" << endl;


	cout << "打印链表:"<< endl;
	printList(pHead);

	////  leetcode 19. Remove Nth Node From End of List

	int k = 1;

	cout << "删除从尾节点来说的倒数第" << k << "个节点" << endl;

	cout << "打印删除节点后的链表："<< endl;
	ListNode* node = removeNthFromEnd(pHead, k);
	printList(node);

	DestroyList(pHead);
}

//leetcode 20. Valid Parentheses
void TestValidString()
{
	cout << "******************************************************************" << endl;
	cout << "字符串是否有效,字符串输入类型为 '(', ')', '{', '}', '[' and ']'" << endl;
	string str = "]";
	cout << "输入字符串为:" << str << endl;
	cout << "字符串是否是成对出现:" << isValid(str) << endl;
}

//21. Merge Two Sorted Lists
void TestMergeList()
{
	cout << "******************************************************************" << endl;
	cout << "测试两个有序链表的合并，采用递归方法" << endl;

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

	cout << "链表1：";
	printList(pMerge1Node1);
	cout << "链表2：";
	printList(pMerge2Node1);

	cout << "合并后链表为:";
	ListNode* result = mergeTwoLists(pMerge1Node1, pMerge2Node1);
	printList(result);

	DestroyList(result);

	//测试合并，不采用递归的方式
	cout << "******************************************************************" << endl;
	cout << "测试两个有序链表的合并，不采用递归方法" << endl;

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

	cout << "链表1：";
	printList(pMerge3Node1);
	cout << "链表2：";
	printList(pMerge4Node1);

	cout << "合并后链表为:";
	ListNode* result2 = mergeTwoListsCycle(pMerge3Node1, pMerge4Node1);
	printList(result2);

	DestroyList(result2);
	

}
int _tmain(int argc, _TCHAR* argv[])
{
	//测试最多容器的水
	TestContainMostWater();
	//测试整数转化为罗马数
	TestIntgerToRoman();
	//测试罗马数字转化为整数
	TestRomanToIntger();
	////letcode 14题 14.Longest Common Prefix
	TestLongestCommonPrefix();

	//leetcode 的 15题 3个数的和为0
	TestThreeSum();

	//leetcode 第16题 3 sum closet
	TestThreeSumClosest();

	//测试两个有序数组的合并  数组中有重复的元素
	TestMergeArray();

	//leetcode 17. Letter Combinations of a Phone Number
	TestletterCombinations();

	// 链表操作
	TestList();

	//leetcode 20. Valid Parentheses
	TestValidString();

	//21. Merge Two Sorted Lists
	TestMergeList();

	return 0;
}

