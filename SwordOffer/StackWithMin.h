#pragma once
#include <stack>

// ������30������min������ջ
// ��Ŀ������ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min
// �������ڸ�ջ�У�����min��push��pop��ʱ�临�Ӷȶ���O(1)��

template<typename T>
class StackWithMin
{
public:
	StackWithMin(){}
	~StackWithMin(){}

	T& top();   //����ջ��Ԫ��

	void Push(const T& value);    //ѹջ����
	void pop();                   //��ջ����

    T& min();           //����ջ����СԪ��
	bool Empty() const;          //ջ�Ƿ�Ϊ��
	size_t size() const;         //����ջ�Ĵ�С

private:
	std::stack<T> m_data;        //����ջ������Ԫ��
	std::stack<T> m_min;         //����ջ�����ڱ�����СԪ��

};

