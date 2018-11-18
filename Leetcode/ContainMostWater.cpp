#include "stdafx.h"
#include "ContainMostWater.h"

//测试两个有序数组的合并  数组中有重复的元素
vector<int> mergeArray(vector<int> array1, vector<int> array2)
{
	vector<int> result;
	result.clear();
	if (array1.size() == 0 && array2.size() == 0)
	{
		return result;
	}
	if (array1.size() == 0)
	{
		return array2;
	}

	if (array2.size() == 0)
	{
		return array1;
	}

	int index1 = 0;
	int index2 = 0;
	int length1 = array1.size();
	int length2 = array2.size();


	while (index1 < length1 && index2< length2)
	{
		if (index1>0 && array1.at(index1 - 1) == array1.at(index1))
		{
			index1++;
		}
		if (index2 >0 && array2.at(index2 - 1) == array2.at(index2))
		{
			index2++;
		}

		if (index1 < length1 && index2 < length2 && array1.at(index1) < array2.at(index2))
		{
			result.push_back(array1.at(index1));
			index1++;
		}
		else if (index1 < length1 && index2 < length2 && array1.at(index1) == array2.at(index2))
		{
			result.push_back(array2.at(index2));
			index2++;
			index1++;
		}
		else
		{
			if (index2 < length2)
			{
				result.push_back(array2.at(index2));
				index2++;
			}
			
		}

	}
	//如果一个数组遍历结束，则将剩余的元素添加到result中

	while (index1 < length1)
	{
		if (result.back() != array1.at(index1))
		{
			result.push_back(array1.at(index1));
		}
		index1++;
		
	} 

	while (index2 < length2)
	{
		if (result.back() != array2.at(index2))
		{
			result.push_back(array2.at(index2));
		}
		index2++;
	}

	return result;

}
int maxArea(vector<int>& height)
{
	if (height.size() ==0 )
	{
		return -1;
	}

	int maxResult = 0;
	int tempArea = 0;
	int length = height.size();
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i; j< length; j++)
		{
			tempArea = (j - i)*(MIN(height.at(i),height.at(j)));
			if (tempArea > maxResult)
			{
				maxResult = tempArea;
			}
		}

	}
	return maxResult;

}

//leetcode 12题  inter to roman
string intToRoman(int num)
{
	string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

	if (num <= 0)
	{
		return nullptr;
	}

	string result;
	for (size_t i = 0; num != 0; i++)
	{
		while (num >= value[i])
		{
			num = num - value[i];
			result += symbol[i];
		}
	}

	return result;
}

//将char字符转化为int数字
int RomanCharToInt(char ch)
{
	int result = -1;
	switch (ch)
	{
		case 'I':
		    result = 1;
			break;
		case 'V':
			result = 5;
			break;
		case 'X':
			result = 10;
			break;
		case 'L':
			result = 50;
			break;
		case 'C':
			result = 100;
			break;
		case 'D':
			result = 500;
			break;
		case 'M':
			result = 1000;
			break;
	    default:
		    break;
	}
	return result;
}


// leetcode 13题  roman to inter
int RomanToInt(string str)
{
	if (str.size() == 0)
	{
		return -1;
	}

	int result = RomanCharToInt(str[0]);

	int pre;
	int current;
	int length = str.size();
	for (size_t i = 1; i < length; i++)
	{
		pre = RomanCharToInt(str[i - 1]);
		current = RomanCharToInt(str[i]);

		if (pre < current)
		{
			result = result + (current - pre) - pre;
		}
		else
		{
			result += current;
		}
	}
	return result;
}

//letcode 14题 14.Longest Common Prefix
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0)
	{
		return "";
	}
	if (strs.size() == 1)
	{
		return strs.at(0);
	}

	string result = "";
	int size = strs.at(0).size();
	
	for (size_t i = 1; i < size+1; i++)
	{
		string FirstStr = strs.at(0).substr(0, i);     //得到vector第一个元素的子字符串
		bool match = true;

		for (size_t j = 1; j < strs.size(); j++)
		{
			if (match && FirstStr == strs.at(j).substr(0,i))
			{
				match = true;
			}
			else
			{
				match = false;
				break;
			}
		}

		//遍历完成一次substr(0, i)的匹配

		if (match)
		{
			result = FirstStr;
		}
	}
	return result;
}


//leetcode 的 15题 3个数的和为0
vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> result;
	result.clear();

	if (nums.size() == 0)
	{
		return result;
	}

	//对nums进行排序
	std::sort(nums.begin(), nums.end(), std::less<int>());   //升序排列

	
	int size = nums.size();
	for (size_t i = 0; i < size-2; i++)
	{
		if (nums.at(i) > 0)     //如果第一个数字都大于0 则后面的数字之和不可能为0
		{
			break;
		}
		if (i>0 && nums.at(i)== nums.at(i-1))
		{
			continue;
		}
		int target = 0 - nums.at(i);
		int front = i + 1;
		int end = size - 1;  

		while (front < end)
		{
			if (nums.at(front) + nums.at(end) == target)
			{
				vector<int> result_core;
				result_core.clear();
				result_core.push_back(nums.at(i));
				result_core.push_back(nums.at(front));
				result_core.push_back(nums.at(end));
				result.push_back(result_core);

				while (front < end && nums.at(front) == nums.at(front+1))
				{
					front++;
				}

				while (front < end && nums.at(end) == nums.at(end-1))
				{
					end--;
				}
				front++;
				end--;
			}
			else if (nums.at(front) + nums.at(end) < target)
			{
				front++;
			}
			else
			{
				end--;
			}
		}
	}
	return result;
}


//leetcode 第16题 3 sum closet
int threeSumClosest(vector<int>& nums, int target)
{

	if (nums.size() == 0)
	{
		return NULL;
	}

	//对nums进行排序
	std::sort(nums.begin(), nums.end(), std::less<int>());   //升序排列


	int size = nums.size();
	int sum ;
	int minus = INT_MAX;
	int tempMinus;
	int retValue;
	int sumTemp;
	for (size_t i = 0; i < size - 2; i++)
	{

		if (i>0 && nums.at(i) == nums.at(i - 1))
		{
			continue;
		}

		int front = i + 1;
		int end = size - 1;

		while (front < end)
		{
			sum = nums.at(i) + nums.at(front) + nums.at(end);
			tempMinus = abs(sum - target);
			if (tempMinus < minus)
			{
				retValue = sum;
				minus =  tempMinus;
			}
			else if (sum < target)
			{
				front++;
			}
			else
			{
				end--;
			}
		}
	}
	return retValue;
}

//字符数转化为整数
int charToInt(char ch)
{
	if (ch < '0' || ch > '9')
	{
		return -1;
	}
	return (ch - '0');

}
//leetcode 17. Letter Combinations of a Phone Number
vector<string> letterCombinations(string digits)
{
	char phone[10][4] = { {'\0','\0','\0','\0'},    //0
	                      { '\0', '\0', '\0', '\0' },  //1
	                      {'a', 'b', 'c', '\0'},    //2
						  { 'd', 'e', 'f', '\0' },    //3
						  { 'g', 'h', 'i', '\0' },    //4
						  { 'j', 'k', 'l', '\0' },    //5
						  { 'm', 'n', 'o', '\0' },    //6
						  { 'p', 'q', 'r', 's' },    //7
						  { 't', 'u', 'v', '\0' },    //8
						  { 'w', 'x', 'y', 'z' }    //9
	};

	int length = digits.length();
	vector<int> nums;
	nums.clear();
	vector<string> result;
	result.clear();
	if (length == 0)
	{
		return result;
	}

	for (size_t i = 0; i < length; i++)
	{
		int num = charToInt(digits[i]);
		nums.push_back(num);
	}

	

	string str;		
	dfs(nums, 0, str, result, phone);
	
	return result;
}

void dfs(vector<int>& nums, int depth, string str, vector<string>& result, char phone[][4])
{
	if (depth == nums.size())    //递归返回的临界条件
	{
		result.push_back(str);
		return;
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (phone[nums.at(depth)][i] != '\0')
		{
			str = str + phone[nums.at(depth)][i];
			dfs(nums, depth+1, str, result, phone);
			str = str.substr(0, str.length() - 1);
		}
	}

}

//leetcode 20. Valid Parentheses
bool isValid(string s)
{
	if (s.length() == 0)
	{
		return true;
	}

	stack<char> stack_char;
	
	int length = s.length();

	for (size_t i = 0; i < length; i++)
	{
		if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
		{
			stack_char.push(s.at(i));
		}
		else if (stack_char.empty() == true)
		{
			return false;
		}	
		else
		{
			if (s.at(i) == ')' && stack_char.top() == '(')
			{
				stack_char.pop();
			}
			else if (s.at(i) == '}'  && stack_char.top() == '{')
			{
				stack_char.pop();
			}
			else if (s.at(i) == ']' && stack_char.top() == '[')
			{
				stack_char.pop();
			}
			else
			{
				return false;
			}
		}
	}

	return stack_char.empty();
}
//KMP算法实现
int KMP(string ts, string ps)
{
	return -1;
}
