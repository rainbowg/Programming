/*
在二元树中找出和为某一值的所有路径（树）
题目：输入一个整数和一棵二元树。
从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。
打印出和与输入整数相等的所有路径。
例如 输入整数22和如下二元树
   10
  /  \
 5    12
/ \
4  7
则打印出两条路径：10, 12和10, 5, 7。
二元树节点的数据结构定义为：
struct BinaryTreeNode // a node in the binary tree
{
int m_nValue; // value of node
BinaryTreeNode *m_pLeft; // left child of node
BinaryTreeNode *m_pRight; // right child of node
};
题目要求了数据结构，如果需要增加效率的话应该在该结构中增加两个字
二元树节点的数据结构定义为：
struct BinaryTreeNode // a node in the binary tree
{
int m_nValue; // value of node
BinaryTreeNode *m_pLeft; // left child of node
BinaryTreeNode *m_pRight; // right child of node
int minValue; //the minimun value of this subtree with this node as root
int maxValue；//the maximum value
};

需要考虑回溯问题：
*/
#include<stdio.h>

typedef struct SearchTree
{
	SearchTree	*lchild; //树结构中为左孩子，双链表中指向前一个节点
	SearchTree	*rchild; //树结构中为右孩子，双链表中指向后一个节点
	int			value;
}STree;

int CoverPath(STree* root, int value, int arr[], int top)
{
	if (value == 0)
	{
		//print arr;
		return 0;
	}
	else 
	{
		arr[top++] = root->value;
		if (value > root->value)
		{
			value = value - root->value;
			if (root->lchild != NULL)
			{
				CoverPath(root->lchild, value, arr, top);
			}
			if (root->rchild != NULL)
			{
				CoverPath(root->rchild, value, arr, top);
			}
		}
		else
		{
			top--;
		}
	}
}