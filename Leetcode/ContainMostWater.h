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

//测试两个有序数组的合并  数组中有重复的元素
vector<int> mergeArray(vector<int> array1, vector<int> array2);



#define MIN(x,y)  x>y?y:x

int maxArea(vector<int>& height);

//leetcode 12题  inter to roman
string intToRoman(int num);

// leetcode 13题  roman to inter
int RomanToInt(string str);

//将char字符转化为int数字
int RomanCharToInt(char ch);

//letcode 14题 14.Longest Common Prefix
string longestCommonPrefix(vector<string>& strs);
//leetcode 的 15题 3个数的和为0
vector<vector<int>> threeSum(vector<int>& nums);

//leetcode 第16题 3 sum closet
int threeSumClosest(vector<int>& nums, int target);

//leetcode 17. Letter Combinations of a Phone Number
vector<string> letterCombinations(string digits);
//字符数转化为整数
int charToInt(char ch);
//深度遍历
void dfs(vector<int>& nums, int depth, string str, vector<string>& result, char phone[][4]);

//leetcode 20. Valid Parentheses   string input 类型为   Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
//determine if the input string is valid.
bool isValid(string s);

//KMP算法实现
int KMP(string ts, string ps);



