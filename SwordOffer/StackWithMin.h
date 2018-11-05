#pragma once
#include <stack>

// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

template<typename T>
class StackWithMin
{
public:
	StackWithMin(){}
	~StackWithMin(){}

	T& top();   //返回栈顶元素

	void Push(const T& value);    //压栈操作
	void pop();                   //出栈操作

    T& min();           //返回栈中最小元素
	bool Empty() const;          //栈是否为空
	size_t size() const;         //返回栈的大小

private:
	std::stack<T> m_data;        //保存栈的所有元素
	std::stack<T> m_min;         //辅助栈，用于保存最小元素

};

