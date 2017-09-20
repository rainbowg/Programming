#include <stdio.h>
/*
�Ѷ�Ԫ������ת��������˫������
��Ŀ��
����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
    10
   /  \
  6   14
 / \  / \
4  8 12 16
ת����˫������
4=6=8=10=12=14=16��
����˼·�����ṹ���㷨����Ӧ�õݹ��㷨���ݹ��㷨�ĺ������ҵ����Ƶ������⡣
�����������Ϊÿ�εݹ�����󷵻صĶ���˫����������ֻ��Ҫ������ν����ڵ����������
�������Լ���η���˫������
*/
typedef struct SearchTree
{
	SearchTree	*lchild; //���ṹ��Ϊ���ӣ�˫������ָ��ǰһ���ڵ�
	SearchTree	*rchild; //���ṹ��Ϊ�Һ��ӣ�˫������ָ���һ���ڵ�
	int			value;
}STree;

STree* H;
/*
��ʼhead��tail��Ϊ�գ�root����Ϊ�գ�
�ݹ鵽Ҷ�ӽڵ㣬������ǰ���ͺ�̾�Ϊ�Լ�������һ�ζ�С������
Ҷ�ڵ㷵�ز��ɸ��ڵ������ӣ�����֮���໥���ӣ���
*/
void *SearchTreeChangetoDLink(STree* head, STree* tail, STree* root)
{
	STree *lEnd = NULL, *rStart=NULL;
	if (root == NULL)
		return NULL;

	if (root->lchild == NULL)
	{
		head = root;
	}
	else
	{
		SearchTreeChangetoDLink(head, lEnd, root->lchild);
		root->lchild = lEnd;
		lEnd->rchild = root;
	}

	
	if (root->rchild == NULL)
	{
		tail = root;
	}
	else
	{
		SearchTreeChangetoDLink(rStart, tail, root->rchild);
		root->rchild = rStart;
		rStart->lchild = root;
	}	
}