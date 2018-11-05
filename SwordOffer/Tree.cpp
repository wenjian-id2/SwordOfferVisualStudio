#include "stdafx.h"
#include "Tree.h"



BinaryTreeNode* CreateBinaryTreeNode(double m_value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_value = m_value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* parent, BinaryTreeNode* left, BinaryTreeNode* right)
{
	if (parent != nullptr)
	{
		parent->m_pLeft = left;
		parent->m_pRight = right;
	}
	
}

//��������ǰ�����
void PrintBinaryPreorder(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}
	cout << pRoot->m_value << " ";
	PrintBinaryPreorder(pRoot->m_pLeft);
	PrintBinaryPreorder(pRoot->m_pRight);
}

/*���ٶ�����*/
void DestroyBinary(BinaryTreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	BinaryTreeNode* left = root->m_pLeft;
	BinaryTreeNode* right = root->m_pRight;

	delete root;
	root = nullptr;

	DestroyBinary(left);
	DestroyBinary(right);

}

/*�ж�����double���͵�ֵ�Ƿ����*/
bool Equal(double value1, double value2)
{
	if ((value1-value2 < 0.00000001) && (value1-value2 > -0.00000001))
	{
		return true;
	}
	return false;
}

//�ж�tree1�Ƿ����Tree2
bool DoesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == nullptr)
	{
		return true;
	}

	if (pRoot1 == nullptr)
	{
		return false;
	}
	if (!Equal(pRoot1->m_value, pRoot2->m_value))
	{
		return false;
	}

	return DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

/*�ж�һ�Ŷ��������Ƿ������һ��������*/
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;

	if (pRoot1 != nullptr &&pRoot2 != nullptr)
	{
		if (Equal(pRoot1->m_value, pRoot2->m_value))  
		{
			result = DoesTree1HasTree2(pRoot1, pRoot2);
		}
		if (!result)
		{
			result = HasSubTree(pRoot1->m_pLeft, pRoot2);
		}

		if (!result)
		{
			result = HasSubTree(pRoot1->m_pRight, pRoot2);
		}


	}
	return result;
}

//�������ľ���
void MirrorTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}

	//�����ӽڵ��滻
	BinaryTreeNode* temp = pRoot->m_pRight;
	pRoot->m_pRight = pRoot->m_pLeft;
	pRoot->m_pLeft = temp;

	//�ݹ龵�����ҽڵ�

	MirrorTree(pRoot->m_pLeft);
	MirrorTree(pRoot->m_pRight);
}

//�ж�һ�Ŷ������Ƿ��ǶԳƵ�
bool isSymmetrical(BinaryTreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr &&pRoot2 == nullptr)
	{
		return true;
	}

	if (pRoot1 == nullptr || pRoot2 ==  nullptr)
	{
		return false;
	}

	if (!Equal(pRoot1->m_value, pRoot2->m_value))
	{
		return false;
	}

	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) 
		   && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

//������ �����������δ�ӡ������
void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}
	queue<BinaryTreeNode*> queueVec;

	queueVec.push(pRoot);

	while (!queueVec.empty())     //������в�Ϊ��
	{
		cout << queueVec.front()->m_value << " ";
		
		if (queueVec.front()->m_pLeft != nullptr)
		{
			queueVec.push(queueVec.front()->m_pLeft);
		}
		
		if (queueVec.front()->m_pRight != nullptr)
		{
			queueVec.push(queueVec.front()->m_pRight);
		}
		if (!queueVec.empty())
		{
			queueVec.pop();
		}
		
	}

}

//���� �����������δ�ӡ������
void PrintFromTopToBottomLines(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}
	queue<BinaryTreeNode*> queueVec;

	queueVec.push(pRoot);

	int nextLevel = 0;    //��һ��Ҫ��ӡ�Ľڵ�����
	int toPrint = 1;      //��ǰ�㻹��Ҫ��ӡ������


	while (!queueVec.empty())     //������в�Ϊ��
	{
		cout << queueVec.front()->m_value << " ";
		
		if (queueVec.front()->m_pLeft != nullptr)
		{
			queueVec.push(queueVec.front()->m_pLeft);
			nextLevel++;
		}

		if (queueVec.front()->m_pRight != nullptr)
		{
			queueVec.push(queueVec.front()->m_pRight);
			nextLevel++;
		}
		if (!queueVec.empty())
		{
			queueVec.pop();
			toPrint--;

			if (toPrint == 0)
			{
				toPrint = nextLevel;
				nextLevel = 0;
			    cout << endl;
			}
		}

	}
}

//���ϵ���֮���δ�ӡһ�Ŷ�����
void PrintFromTopToBottomZigZag(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}
	stack<BinaryTreeNode*> stackVec;
	stack<BinaryTreeNode*> stackVec2;

	stackVec.push(pRoot);

	BinaryTreeNode* node;
	bool isOdd = true;

	while ((!stackVec.empty()) || !stackVec2.empty())     //���ջ��Ϊ��
	{
		if (isOdd == true)
		{
			while (!stackVec.empty())   //��ջ��Ϊ�� ���δ�ӡջ�е����нڵ�
			{
				node = stackVec.top();
				stackVec.pop();
				cout << node->m_value << " ";
				if (node->m_pLeft != nullptr)
				{
					stackVec2.push(node->m_pLeft);
				}
				if (node->m_pRight != nullptr)
				{
					stackVec2.push(node->m_pRight);
				}
				
				
			}
			isOdd = false;
		}
		else
		{
			while (!stackVec2.empty())
			{
				node = stackVec2.top();
				stackVec2.pop();
				cout << node->m_value << " ";
				if (node->m_pRight != nullptr)
				{
					stackVec.push(node->m_pRight);
				}
				if (node->m_pLeft!= nullptr)
				{
					stackVec.push(node->m_pLeft);
				}
				

			}
			isOdd = true;
		}
	}	
	cout << endl;
}

/*�ж������Ƿ��Ƕ����������ĺ�������*/
bool VerifySquenceOfBST(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
	{
		return false;
	}
	if (length == 1)
	{
		return true;
	}

	int root = sequence[length - 1];    //���ڵ�ֵ

	int leftIndex = 0;
	while (sequence[leftIndex] < root)
	{
		leftIndex++;
	}
	//�õ���������Ĳ���

	for (size_t i = leftIndex; i < length-1; i++)
	{
		if (sequence[i] < root)
		{
			return false;
		}
	}

	bool left = true;
	if (leftIndex > 0)
	{
		left = VerifySquenceOfBST(sequence, leftIndex);
	}
	
	bool right = true;
	if (length - leftIndex - 1 > 0)
	{
		right = VerifySquenceOfBST(&sequence[leftIndex], length - leftIndex - 1);
	}
	
	return left && right;

}

//���õݹ�ķ�ʽ��ʵ�ֶ������к�Ϊĳһֵ��·��
//·��Ϊ��Ҷ�ӽڵ�

bool FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum)
{
	bool result = false;
	//����������ǰ������ķ�ʽ
	currentSum = currentSum + (int)(pRoot->m_value);
	path.push_back((int)(pRoot->m_value));

	bool isLeaf = (pRoot->m_pLeft == nullptr) && (pRoot->m_pRight == nullptr);    //�ж��Ƿ�ΪҶ�ӽڵ�
	if (currentSum == expectedSum && isLeaf)     //�������ӡ��ǰ�ڵ�
	{
		vector<int>::iterator ite = path.begin();
		cout << "·��Ϊ��";
		for (; ite != path.end(); ite++)
		{
			cout << *ite << " ";
		}
		cout << endl;
		result =  true;
	}

	//Ȼ��ݹ����ҽڵ�
	bool left = false;
	if (pRoot->m_pLeft != nullptr)
	{
		left = FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	}
	bool right = false;
	if (pRoot->m_pRight != nullptr)
	{
		right = FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	}
	path.pop_back();

	return left || right || result;
}

//�������к�Ϊĳһֵ��·��
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
	{
		cout << "·��δ�ҵ�" << endl;
		return;
	}
	vector<int> path;     //���ڱ���·��
	int currentSum = 0;

	bool result = FindPath(pRoot, expectedSum, path,currentSum);
	if (!result)
	{
		cout << "·��δ�ҵ�" << endl;
	}
}