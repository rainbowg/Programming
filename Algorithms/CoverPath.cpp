/*
�ڶ�Ԫ�����ҳ���Ϊĳһֵ������·��������
��Ŀ������һ��������һ�ö�Ԫ����
�����ĸ���㿪ʼ���·���һֱ��Ҷ��������������н���γ�һ��·����
��ӡ����������������ȵ�����·����
���� ��������22�����¶�Ԫ��
   10
  /  \
 5    12
/ \
4  7
���ӡ������·����10, 12��10, 5, 7��
��Ԫ���ڵ�����ݽṹ����Ϊ��
struct BinaryTreeNode // a node in the binary tree
{
int m_nValue; // value of node
BinaryTreeNode *m_pLeft; // left child of node
BinaryTreeNode *m_pRight; // right child of node
};
��ĿҪ�������ݽṹ�������Ҫ����Ч�ʵĻ�Ӧ���ڸýṹ������������
��Ԫ���ڵ�����ݽṹ����Ϊ��
struct BinaryTreeNode // a node in the binary tree
{
int m_nValue; // value of node
BinaryTreeNode *m_pLeft; // left child of node
BinaryTreeNode *m_pRight; // right child of node
int minValue; //the minimun value of this subtree with this node as root
int maxValue��//the maximum value
};

��Ҫ���ǻ������⣺
*/
#include<stdio.h>

typedef struct SearchTree
{
	SearchTree	*lchild; //���ṹ��Ϊ���ӣ�˫������ָ��ǰһ���ڵ�
	SearchTree	*rchild; //���ṹ��Ϊ�Һ��ӣ�˫������ָ���һ���ڵ�
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