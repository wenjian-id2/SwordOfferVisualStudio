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

//定义树节点
struct  BinaryTreeNode
{
	double m_value;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//构造二叉树节点
BinaryTreeNode* CreateBinaryTreeNode(double m_value);

//连接二叉树节点
void ConnectTreeNodes(BinaryTreeNode* parent, BinaryTreeNode* left, BinaryTreeNode* right);

//二叉树的前序遍历
void PrintBinaryPreorder(BinaryTreeNode* pRoot);

//销毁二叉树
void DestroyBinary(BinaryTreeNode* root);

//判断一个二叉树中是否包含另一个二叉树
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

//判断两个double类型的数据是否相等
bool Equal(double value1, double value2);

//判断tree1是否包含Tree2
bool DoesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

//二叉树的镜像
void MirrorTree(BinaryTreeNode* pRoot);

//判断一颗二叉树是否是对称的
bool isSymmetrical(BinaryTreeNode* pRoot);
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

//从上向下依次打印二叉树
//// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
void  PrintFromTopToBottom(BinaryTreeNode* pRoot);

//分行 从上向下打印一颗二叉树
void PrintFromTopToBottomLines(BinaryTreeNode* pRoot);

//从上到下之字形打印一颗二叉树
void PrintFromTopToBottomZigZag(BinaryTreeNode* pRoot);

/*// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。*/

bool VerifySquenceOfBST(int sequence[], int length);

// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

void FindPath(BinaryTreeNode* pRoot, int expectedSum);

