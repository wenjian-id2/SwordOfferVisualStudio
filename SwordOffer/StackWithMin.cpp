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
T& StackWithMin<T>::top()   //����ջ��Ԫ��
{
	return m_data.top();
}


template<typename T>
void StackWithMin<T>::Push(const T& value)    //ѹջ����
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
void StackWithMin<T>::pop()                   //��ջ����
{
	m_data.pop();
	m_min.pop();
}


template<typename T>
T& StackWithMin<T>::min()              //����ջ����СԪ��
{
	return m_min.top();
}



template<typename T>
bool StackWithMin<T>::Empty() const      //ջ�Ƿ�Ϊ��
{
	return m_data.empty();
}

template<typename T>
size_t StackWithMin<T>::size() const      //����ջ�Ĵ�С
{
	return m_data.size();
}