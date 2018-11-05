#pragma once
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using std::vector;
using std::stack;
using std::queue;
using std::cout;
using std::cin;
using std::endl;

//�������ڵ�
struct  BinaryTreeNode
{
	double m_value;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//����������ڵ�
BinaryTreeNode* CreateBinaryTreeNode(double m_value);

//���Ӷ������ڵ�
void ConnectTreeNodes(BinaryTreeNode* parent, BinaryTreeNode* left, BinaryTreeNode* right);

//��������ǰ�����
void PrintBinaryPreorder(BinaryTreeNode* pRoot);

//���ٶ�����
void DestroyBinary(BinaryTreeNode* root);

//�ж�һ�����������Ƿ������һ��������
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

//�ж�����double���͵������Ƿ����
bool Equal(double value1, double value2);

//�ж�tree1�Ƿ����Tree2
bool DoesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

//�������ľ���
void MirrorTree(BinaryTreeNode* pRoot);

//�ж�һ�Ŷ������Ƿ��ǶԳƵ�
bool isSymmetrical(BinaryTreeNode* pRoot);
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

//�����������δ�ӡ������
//// ������32��һ���������д������´�ӡ������
// ��Ŀ���������´�ӡ����������ÿ����㣬ͬһ��Ľ�㰴�մ����ҵ�˳���ӡ��
void  PrintFromTopToBottom(BinaryTreeNode* pRoot);

//���� �������´�ӡһ�Ŷ�����
void PrintFromTopToBottomLines(BinaryTreeNode* pRoot);

//���ϵ���֮���δ�ӡһ�Ŷ�����
void PrintFromTopToBottomZigZag(BinaryTreeNode* pRoot);

/*// ������33�������������ĺ����������
// ��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
// ������򷵻�true�����򷵻�false���������������������������ֶ�������ͬ��*/

bool VerifySquenceOfBST(int sequence[], int length);

// ������34���������к�Ϊĳһֵ��·��
// ��Ŀ������һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ������������
// ��·���������ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

void FindPath(BinaryTreeNode* pRoot, int expectedSum);

