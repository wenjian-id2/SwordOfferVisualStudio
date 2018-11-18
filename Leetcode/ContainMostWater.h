#pragma once
#include "stdafx.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <math.h>
#include <limits>
#include <stack>
using std::stack;

#include <string>
using std::string;

#include <vector>
using std::vector;

//����������������ĺϲ�  ���������ظ���Ԫ��
vector<int> mergeArray(vector<int> array1, vector<int> array2);



#define MIN(x,y)  x>y?y:x

int maxArea(vector<int>& height);

//leetcode 12��  inter to roman
string intToRoman(int num);

// leetcode 13��  roman to inter
int RomanToInt(string str);

//��char�ַ�ת��Ϊint����
int RomanCharToInt(char ch);

//letcode 14�� 14.Longest Common Prefix
string longestCommonPrefix(vector<string>& strs);
//leetcode �� 15�� 3�����ĺ�Ϊ0
vector<vector<int>> threeSum(vector<int>& nums);

//leetcode ��16�� 3 sum closet
int threeSumClosest(vector<int>& nums, int target);

//leetcode 17. Letter Combinations of a Phone Number
vector<string> letterCombinations(string digits);
//�ַ���ת��Ϊ����
int charToInt(char ch);
//��ȱ���
void dfs(vector<int>& nums, int depth, string str, vector<string>& result, char phone[][4]);

//leetcode 20. Valid Parentheses   string input ����Ϊ   Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
//determine if the input string is valid.
bool isValid(string s);

//KMP�㷨ʵ��
int KMP(string ts, string ps);



