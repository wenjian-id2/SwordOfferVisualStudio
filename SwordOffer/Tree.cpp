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

//二叉树的前序遍历
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

/*销毁二叉树*/
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

/*判断两个double类型的值是否相等*/
bool Equal(double value1, double value2)
{
	if ((value1-value2 < 0.00000001) && (value1-value2 > -0.00000001))
	{
		return true;
	}
	return false;
}

//判断tree1是否包含Tree2
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

/*判断一颗二叉树中是否包含另一个二叉树*/
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

//二叉树的镜像
void MirrorTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}

	//左右子节点替换
	BinaryTreeNode* temp = pRoot->m_pRight;
	pRoot->m_pRight = pRoot->m_pLeft;
	pRoot->m_pLeft = temp;

	//递归镜像左右节点

	MirrorTree(pRoot->m_pLeft);
	MirrorTree(pRoot->m_pRight);
}

//判断一颗二叉树是否是对称的
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

//不分行 从上向下依次打印二叉树
void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}
	queue<BinaryTreeNode*> queueVec;

	queueVec.push(pRoot);

	while (!queueVec.empty())     //如果队列不为空
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

//分行 从上向下依次打印二叉树
void PrintFromTopToBottomLines(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}
	queue<BinaryTreeNode*> queueVec;

	queueVec.push(pRoot);

	int nextLevel = 0;    //下一层要打印的节点数量
	int toPrint = 1;      //当前层还需要打印的数量


	while (!queueVec.empty())     //如果队列不为空
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

//从上到下之字形打印一颗二叉树
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

	while ((!stackVec.empty()) || !stackVec2.empty())     //如果栈不为空
	{
		if (isOdd == true)
		{
			while (!stackVec.empty())   //当栈不为空 依次打印栈中的所有节点
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

/*判断数组是否是二叉搜索树的后续遍历*/
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

	int root = sequence[length - 1];    //根节点值

	int leftIndex = 0;
	while (sequence[leftIndex] < root)
	{
		leftIndex++;
	}
	//得到左二叉树的部分

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

//采用递归的方式来实现二叉树中和为某一值的路径
//路径为到叶子节点

bool FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum)
{
	bool result = false;
	//二叉树采用前序遍历的方式
	currentSum = currentSum + (int)(pRoot->m_value);
	path.push_back((int)(pRoot->m_value));

	bool isLeaf = (pRoot->m_pLeft == nullptr) && (pRoot->m_pRight == nullptr);    //判断是否为叶子节点
	if (currentSum == expectedSum && isLeaf)     //满足则打印当前节点
	{
		vector<int>::iterator ite = path.begin();
		cout << "路径为：";
		for (; ite != path.end(); ite++)
		{
			cout << *ite << " ";
		}
		cout << endl;
		result =  true;
	}

	//然后递归左右节点
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

//二叉树中和为某一值的路径
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
	{
		cout << "路径未找到" << endl;
		return;
	}
	vector<int> path;     //用于保存路径
	int currentSum = 0;

	bool result = FindPath(pRoot, expectedSum, path,currentSum);
	if (!result)
	{
		cout << "路径未找到" << endl;
	}
}