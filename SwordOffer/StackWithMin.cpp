#include "stdafx.h"
#include "StackWithMin.h"

/*
template<typename T>
StackWithMin<T>::StackWithMin()
{
}

template<typename T>
StackWithMin<T>::~StackWithMin()
{
}
 */
template<typename T>
T& StackWithMin<T>::top()   //返回栈顶元素
{
	return m_data.top();
}


template<typename T>
void StackWithMin<T>::Push(const T& value)    //压栈操作
{
	m_data.push(value);

	if (m_min.size() == 0 || value < m_min.top())
	{
		m_min.push(value);
	}
	else
	{
		m_min.push(m_min.top());
	}
}

template<typename T>
void StackWithMin<T>::pop()                   //出栈操作
{
	m_data.pop();
	m_min.pop();
}


template<typename T>
T& StackWithMin<T>::min()              //返回栈中最小元素
{
	return m_min.top();
}



template<typename T>
bool StackWithMin<T>::Empty() const      //栈是否为空
{
	return m_data.empty();
}

template<typename T>
size_t StackWithMin<T>::size() const      //返回栈的大小
{
	return m_data.size();
}