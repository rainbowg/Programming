#include <stdio.h>
/*
把二元查找树转变成排序的双向链表
题目：
输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
要求不能创建任何新的结点，只调整指针的指向。
    10
   /  \
  6   14
 / \  / \
4  8 12 16
转换成双向链表
4=6=8=10=12=14=16。
解题思路：树结构的算法多数应用递归算法，递归算法的核心是找到相似的子问题。
该题的子问题为每次递归运算后返回的都是双向链表，这样只需要考虑如何将根节点和左右子树
串联，以及如何返回双向链表。
*/
typedef struct SearchTree
{
	SearchTree	*lchild; //树结构中为左孩子，双链表中指向前一个节点
	SearchTree	*rchild; //树结构中为右孩子，双链表中指向后一个节点
	int			value;
}STree;

STree* H;
/*
初始head和tail均为空，root不能为空；
递归到叶子节点，并设其前驱和后继均为自己（构成一段段小链表）；
叶节点返回并由根节点相连接（链表之间相互连接）；
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