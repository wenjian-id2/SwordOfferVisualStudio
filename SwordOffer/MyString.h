#pragma once

/*请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配*/
bool match(const char* strOrigin, const char* patten);

/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串”+100”,”5e2”,”-123”,”3.1416”和”-1E-16”都表示数值。 
但是”12e”,”1a3.14”,”1.2.3”,”+-5”和”12e+4.3”都不是。*/

bool isNumber(const char* str);

/*
输入一个整数数组，实现一个函数来解决该数组中数字的位置，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。*/

void ReorderOddEven(int* pData, unsigned int length);

//这种方法采用函数指针的方式，具有更好的扩展性
bool isEven(int num);
void ReorderOddEven(int* pData, unsigned int length, bool (*func)(int));