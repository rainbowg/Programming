/*
设计包含min函数的栈（数据结构：栈）
定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。
要求函数min、push以及pop的时间复杂度都是O(1)。
解题思路：当题目中出现时间复杂度为O(1)时，应该考虑利用空间换时间
除下面代码实现外还可以在栈中增加一个字段，用来储存最小值
|_______..._______|
|_7(value)_2(min)_|
|_2(value)_2(min)_|
|_5(value)_5(min)_|
|_6(value)_6(min)_|
*/
#include <stdio.h>

typedef struct Stack
{
	Stack   *prev;
	int		value;
}Stack;

class MinStack
{
public:
	MinStack();
	int Pop(int &value);
	int Push(int value);
	int Min(int &value);
private:
	Stack	*top;
	Stack   *minTop;
};

MinStack::MinStack()
{
	top = NULL;
	minTop = NULL;
}

int MinStack::Pop(int &value)
{
	Stack *tmp;
	if (top != NULL)
	{
		tmp = top;
		value = top->value;
		top = top->prev;
		delete(tmp);
		tmp = NULL;
		//只要值与最小栈栈顶值相同就删除
		if (minTop->value == value)
		{
			Stack *minTmp;
			minTmp = minTop;
			minTop = minTop->prev;
			delete(minTmp);
			minTmp = NULL;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

int MinStack::Push(int value)
{
	Stack *tmp = new Stack();
	if (tmp != NULL)
	{
		tmp->value = value;
		tmp->prev = top;
		top = tmp;
		//即使该值与最小栈栈顶值相同也入栈，保证出栈逻辑
		if (value <= minTop->value)
		{
			Stack *minTmp = new Stack();
			if (minTmp != NULL)
			{
				minTmp->value = value;
				minTmp->prev = minTop;
				minTop = minTmp;
			}
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

int MinStack::Min(int &value)
{
	if (minTop != NULL)
	{
		value = minTop->value;
		return 0;
	}
	return -1;
}