/*
��ư���min������ջ�����ݽṹ��ջ��
����ջ�����ݽṹ��Ҫ�����һ��min�������ܹ��õ�ջ����СԪ�ء�
Ҫ����min��push�Լ�pop��ʱ�临�Ӷȶ���O(1)��
����˼·������Ŀ�г���ʱ�临�Ӷ�ΪO(1)ʱ��Ӧ�ÿ������ÿռ任ʱ��
���������ʵ���⻹������ջ������һ���ֶΣ�����������Сֵ
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
		//ֻҪֵ����Сջջ��ֵ��ͬ��ɾ��
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
		//��ʹ��ֵ����Сջջ��ֵ��ͬҲ��ջ����֤��ջ�߼�
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