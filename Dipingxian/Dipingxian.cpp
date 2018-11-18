// Dipingxian.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <limits>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;


//树结点结构
class BSTNode{
public:
	int _key; //关键在字（键值）
	BSTNode *_lchild; //左孩
	BSTNode *_rchild; //右孩
	BSTNode *_parent; // 双亲
	int _index;

	//构造函数
	BSTNode(int key, BSTNode *lchild, BSTNode *rchild, BSTNode *parent,int index) :
		_key(key), _lchild(lchild), _rchild(rchild), _parent(parent),_index(index){};
};

BSTNode *_Root = NULL;
	/*
	*插入操作
	*非递归实现
	*内部使用函数
	*/
	void insert(BSTNode* &tree, BSTNode* z)
	{
		BSTNode* parent = NULL;
		BSTNode* temp = tree;

		//寻找插入点
		while (temp != NULL)
		{
			parent = temp;
			if (z->_key>temp->_key)
				temp = temp->_rchild;
			else
				temp = temp->_lchild;
		}
		z->_parent = parent;
		if (parent == NULL) //如果树本来就是空树，则直接把z节点插入根节点
			tree = z;
		else if (z->_key>parent->_key) //如果z的值大于其双亲，则z为其双亲的右孩
			parent->_rchild = z;
		else
			parent->_lchild = z;
	}
	/*
	*
	*接口
	*/
	
	void insert(int key,int index)
	{
		//创建一个新的节点，使用构造函数初始化
		BSTNode* z = new BSTNode(key, NULL, NULL, NULL,index);
		if (!z) //如果创建失败则返回
			return;
		//调用内部函数进行插入
		insert(_Root, z);
	}
	BSTNode*  search(BSTNode* &tree, int key)
	{
		BSTNode* temp = tree;
		while (temp != NULL)
		{
			if (temp->_key == key)
				return temp;
			else if (temp->_key>key)
				temp = temp->_lchild;
			else
				temp = temp->_rchild;
		}
		return NULL;
	}

	BSTNode* search(int key)
	{
		return search(_Root, key);
	}


int _tmain(int argc, _TCHAR* argv[])
{
	int find = 0;
	cin >> find;
	int a;
	int index = 0;
	while (cin >> a)
	{
		insert(a,index);
		index++;
	}

	BSTNode* result = search(find);

	if (result != NULL)
	{
		cout << result->_index << endl;
	}
	else
	{
		cout << -1 << endl;
	}


	return 0;
}

