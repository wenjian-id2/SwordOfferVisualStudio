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


//�����ṹ
class BSTNode{
public:
	int _key; //�ؼ����֣���ֵ��
	BSTNode *_lchild; //��
	BSTNode *_rchild; //�Һ�
	BSTNode *_parent; // ˫��
	int _index;

	//���캯��
	BSTNode(int key, BSTNode *lchild, BSTNode *rchild, BSTNode *parent,int index) :
		_key(key), _lchild(lchild), _rchild(rchild), _parent(parent),_index(index){};
};

BSTNode *_Root = NULL;
	/*
	*�������
	*�ǵݹ�ʵ��
	*�ڲ�ʹ�ú���
	*/
	void insert(BSTNode* &tree, BSTNode* z)
	{
		BSTNode* parent = NULL;
		BSTNode* temp = tree;

		//Ѱ�Ҳ����
		while (temp != NULL)
		{
			parent = temp;
			if (z->_key>temp->_key)
				temp = temp->_rchild;
			else
				temp = temp->_lchild;
		}
		z->_parent = parent;
		if (parent == NULL) //������������ǿ�������ֱ�Ӱ�z�ڵ������ڵ�
			tree = z;
		else if (z->_key>parent->_key) //���z��ֵ������˫�ף���zΪ��˫�׵��Һ�
			parent->_rchild = z;
		else
			parent->_lchild = z;
	}
	/*
	*
	*�ӿ�
	*/
	
	void insert(int key,int index)
	{
		//����һ���µĽڵ㣬ʹ�ù��캯����ʼ��
		BSTNode* z = new BSTNode(key, NULL, NULL, NULL,index);
		if (!z) //�������ʧ���򷵻�
			return;
		//�����ڲ��������в���
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

