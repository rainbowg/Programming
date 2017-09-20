#include <stdlib.h>
#include <stdio.h>
#define Type int

enum Color{
	Red = 0,
	Black =1
};

enum Kind {
	precursor = 0,
	successor = 1
};

typedef struct Node
{
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	Type  value;
	Color color;
}*R_BTree;


//nil is all leaves' child
R_BTree nil = (R_BTree)malloc(sizeof(struct Node)); 
R_BTree root = nil;

void RotateLeft(R_BTree node);
void RotateRight(R_BTree node);
void Search(Type value);
void Insert(Type value);
void InsertMaintain(R_BTree node);
void Delect(Type value);
void DelectMaintain(R_BTree node);


void RotateLeft(R_BTree node)
{
	R_BTree rnode = node->right;
	node->right = rnode->left;
	if (rnode->left)
		rnode->left->parent = node;
	rnode->left = node;
	rnode->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = rnode;
		else
			node->parent->right = rnode;
	}
	else
		root = rnode;
	node->parent = rnode;
}

void RotateRight(R_BTree node)
{
	R_BTree rnode = node->left;
	node->left = rnode->right;
	if (rnode->right)
		rnode->right->parent = node;
	rnode->right = node;
	rnode->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->right)
			node->parent->right = rnode;
		else
			node->parent->left = rnode;
	}
	else
		root = rnode;
	node->parent = rnode;
}

R_BTree CreateNode(Type value)
{
	R_BTree node = (R_BTree)malloc(sizeof(struct Node));
	node->value = value;
	node->parent = nil;
	node->left = nil;
	node->right = nil;

	return node;
}

R_BTree Search(R_BTree pnode,Type value)
{
	R_BTree node = root;
	while (node != nil)
	{
		if (node->value < value)
			node = node->left;
		else if (node->value > value)
			node->right;
		else
		{
			return node;
		}
		pnode = node;
	}
	return nil;
}
void Insert(Type value)
{
	R_BTree pnode = NULL, nnode = NULL;
	R_BTree node = Search(pnode, value);

	if (node)
		return;
	nnode = CreateNode(value);
	if (pnode)
	{
		nnode->parent = pnode;
		if (pnode->value < value)
			pnode->left = nnode;
		else
			pnode->right = nnode;
		nnode->color = Red;
		InsertMaintain(nnode);
	}
	else
	{
		root = nnode;
		root->color = Black;
	}
}

void InsertMaintain(R_BTree node)
{
	if (node->parent->color == Black)
		return;
	//unode: uncle node
	R_BTree unode = NULL, pnode = node->parent;
	if(pnode = pnode->parent->left)
	{
		unode = pnode->parent->right;
		while (node)
		{
			if (unode && unode->color == Red)
			{
				// case 1
				pnode->parent->color = Red;
				pnode->color = unode->color = Black;
				node = pnode->parent;
				continue;
			}
			if (node == pnode->right)
			{
				//case 2
				RotateLeft(pnode);
			}
			//case 3
			RotateRight(node);
			node->color = Black;
			unode->color = Red;
			break;
		}
	}
	else
	{
		// same as above, but left and right change each other
	}
}

R_BTree findNode(R_BTree node, Kind kind = precursor)
{
	R_BTree tnode = NULL;

	switch (kind)
	{
	case precursor:
		if (node->left != nil)
		{
			tnode=node->left;
			while (tnode != nil)
			{
				tnode = tnode->right;
			}
			return tnode;
		}
		break;
	case successor:
		if (node->right != nil)
		{
			tnode = node->right;
			while (tnode != nil)
			{
				tnode = tnode->left;
			}
			return tnode;
		}
		break;
	}
}

void Delete(Type value)
{
	R_BTree pnode = NULL;
	R_BTree node = Search(pnode, value);
	R_BTree tnode = NULL;

	if (!node)
		return;
	tnode = findNode(node);
	if (tnode != nil)
	{
		node->value = tnode->value;
		tnode->parent->right = tnode->left;
		if (tnode->left != nil)
			tnode->left->parent = tnode->parent;
	}
	else
	{
		tnode = node;
		if (tnode->parent != nil)
		{
			if (tnode == tnode->parent->left)
				tnode->parent->left = tnode->right;
			if (tnode->right != nil)
				tnode->right->parent = tnode->parent;
		}
		else
		{
			root = tnode->right;
			tnode->color = Black;
			return;
		}
	}
	if (tnode->color == Black)
	{
		DelectMaintain(tnode);
	}
	delete tnode;
}
void DelectMaintain(R_BTree node)
{
	//bnode: brother node
	R_BTree bnode = NULL;
	if (node == node->parent->right)
	{
		bnode = node->parent->left;
		if (bnode->color == Red)
		{
			bnode->color = Black;
			node->parent->color = Red;
			RotateLeft(node->parent);
			bnode = node->parent->right;
		}
		else
		{
			if (bnode->left->color == Black && bnode->right->color == Black)
			{
				bnode->color = Red;
				node = node->parent;
			}
			else if (bnode->left->color == Red && bnode->right->color == Black)
			{
				bnode->left->color = Black;
				bnode->color = Red;
				RotateRight(bnode);
				bnode = node->parent->right;
			}
			else
			{
				bnode->color = node->parent->color;
				node->parent->color = Black;
				bnode->right->color = Black;
				RotateLeft(node->parent);
				root = node;
			}
		}
	}
	else
	{

	}
}

void main()
{
	
}