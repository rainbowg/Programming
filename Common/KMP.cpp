/*
重要概念：
前缀：除了最后一个字符以外，一个字符串的全部头部组合；
后缀：除了第一个字符以外，一个字符串的全部尾部组合；
如字符串：“bread”
前缀：b, br, bre, brea
后缀：read, ead, ad, d

部分匹配值：就是前缀和后缀的最长的共有元素的长度；
以“ABCDABD”为例，
- “A”的前后缀都为空集，共有元素的长度为0；
- “AB”的前缀为[A]，后缀为[B]，共有元素长度为0；
- ...
- “ABCDAB”的前缀为[A, AB, ABC, ABCD, ABCDA]，后缀为[BCDAB, CDAB, DAB, AB, B]，共有元素为“AB”，长度为2；
- ...
“部分匹配”的实质是字符串头部和尾部（有时候）会有重复。

next数组可以理解为，通过“最长相同前后缀长度值右移一位，然后初始值赋为-1”

优化next数组：如求字符串“ABAB”的next数组为“-1，0，0，1”。当该数组与“ABACABABC”进行匹配时，“B”和“C”匹配失败，
利用next数组跳到1的位置（也是字符“B”），必然失配。


KMP算法时间分析：
我们发现如果某个字符匹配成功，模式串首字符的位置保持不动，如果匹配失败，模式串会跳到next[j]和字符。整个算法最坏的
的情况是，当模式串首个字符位于n-m的位置才匹配成功，算法结束。
所以，如果文本串长度为n，模式串长度为m，那么匹配过程时间复杂度为O(n)，算上计算next数组的时间O(m)，KMP整体为O(n+m)

*/

#include <iostream>
#include <vector>

using namespace std;

void GetNext(char* temp, int* next)
{
	next[0] = -1;
	int pre = -1, post = 0;

	while (post < strlen(temp))
	{
		if (pre == -1 || temp[pre] == temp[post])
		{
			++pre;
			++post;
			// 原始方法
			next[post] = pre;

			// 优化Next数组
			/*if (temp[pre] != temp[post])
				next[post] = pre;
			else
				next[post] = next[pre];*/
		}
		else
			pre = next[pre];
	}
}

int KMPSearch(char* temp, char* array, int* next)
{
	int pos = -1;
	int pArray = 0, pTemp = 0;
	int lenTemp = strlen(temp), lenArray = strlen(array);
	while (pTemp < lenTemp && pArray < lenArray)
	{
		if (pTemp == -1 || array[pArray] == temp[pTemp])
		{
			pArray++;pTemp++;
		}
		else
		{
			pTemp = next[pTemp];
		}

	}

	if (pTemp == strlen(temp))
		pos = pArray - pTemp;

	return pos;
}

//int main()
//{
//	char temp[] = "ABCDABCE"; 
//	char array[] = "BBC ABCEABCDABD ABCDABCEAB";
//	int next[8] = { 0 };
//	int i;
//	GetNext(temp, next);
//	if (-1 < 8)
//		cout << "true" << endl;
//	for (int i = 0; i < strlen(temp); i++)
//	{
//		cout << next[i] << " ";
//	}
//
//	cout << endl << "find pos:　" << KMPSearch(temp, array, next);
//
//	cin >> i;
//	/*system("pause");*/
//}



































