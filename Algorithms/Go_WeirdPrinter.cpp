/*
Google(����):
һ����ֵĴ�ӡ����ӡʱ�����������������������
1��ÿ��ֻ�ܴ�ӡͬһ���ַ���ɵ��������У�����ֻ��ӡһ���ַ���
2��ÿ�δ�ӡ�������κ�λ�ÿ�ʼ�����κ�λ�ý�������ӡ���ַ��Ὣԭ�����е��ַ�����
����һ��ֻ����Сд��ĸ���ַ�������������Ǽ����øô�ӡ����ӡ������ַ�����������ٴ�ӡ������
�ַ������Ȳ�����100��

����1��
����: "aaabbb:
���: 2
˵�����ȴ�ӡaaa���ڴ�ӡbbb��

����2��
���룺"aba"
�����2
˵�����ȴ�ӡaaa�������м��λ�ô�ӡb����֮ǰ��a��

˼·��
(����)
��. һ���򵥵��뷨�ǣ��������ַ����м��β�ͬ���ַ����ʹ�ӡ���Σ������Ǵ�ӡ���ǵ������
����aabbc���Ǿʹ�ӡ���Ρ�����һ��̰�Ĳ��ԣ�������ĳЩ����²���ȡ�����Ž⣬����aabba��
�����ȴ�ӡaaaaa��Ȼ���ӡbb��ֻ��Ҫ���Ρ�

��. ��ô��������������ÿ���������������ߵĴ�ӡ���䣨��Ҫ�����յ㣩��
���Ƿ���ͨ����¼Ŀǰ��ȷ��ӡ�����ĸ�λ�ã����ǿ���ֱ�������һ�δ�ӡ����㡣
��Ϊ��������Ҫ�ӵ�һ��������λ�ÿ�ʼ��ӡ���������ǿ��еģ����Ǹ��Ӷ���ָ�����������Ż��Ŀ����ԡ�

��. ���֮ǰ����˼·���������۲��ܽ�һ�£���ӡ�������ַ������ص㣺
����ĳһ�δ�ӡ����ӡ�����ɸ�'a'������������aaaaaa��������֮���ӡ���ַ����޷������������
�� ������ַ������ڲ���ӡ�����ǲ���������ַ�����һ�ˣ����硱abbbaa������abbada����
�� ������ַ������ⲿ��ӡ����ȫ����������ַ��������硱bbaaaaaa������bbaaaaaaccc����
�� ��������ַ�����һ�ˣ����硱baaaaa������baaacccccc����
������˵�ĵ��������������������������ַ�����ӡ�ڡ�a����ɵ��ַ������ⲿ��
��ʵ�ϣ������ӡ��һ���ַ������ٴ�ӡһЩ�ַ���������ַ����Ķ˵������˷ѣ�
Ҳ����˵�����ǵ����ַ����Ĳ���һ��ʼ��ȫû�б�Ҫ��ӡ��Ҳ��������մ�ӡ�������Ӱ�졣
���ԣ����ǿ��Լٶ�����ӡʱ�������˷ѣ��ȼ���ĳ�δ�ӡ���Ը���ǰ��ĳһ�δ�ӡ�ģ��������˵�ģ��ڲ���
Ҳ���Բ����ǣ����ǲ��ܸ���ǰ��ĳһ�δ�ӡ�Ķ˵㡣

��. ����һ����֪��Ŀ���ַ���s�����ǿ��Ǵ�ӡ������ַ�������ߵ��ַ�s[0]���Ǵδ�ӡ��
�����ܿ����ڴ�ӡ�����У��Ѹôδ�ӡ�ŵ���һ�δ�ӡ�������������������ǣ����ڢ��еļٶ���
�����Ĵ�ӡҪô����δ�ӡ���ڲ����������˵㣩��Ҫô����δ�ӡ���ⲿ���������ڸ��ַ���Ŀ���ַ���������˵㣬
������δ�ӡҲ�������ڱ�Ĵ�ӡ���ڲ�������һ�����ǾͿ���ö�ٰ���s[0]���Ǵδ�ӡ�ĳ���L��
Ȼ���ԭĿ���ַ�����Ϊs[0 ~ L-1]��s[L ~ N-1]����ԭ�ַ�������ΪN����
���У���a�еļٶ���֪s[0]==s[L-1]�����������Ϊ�˵㲻�����ǣ���
s[0 ~ L-1]�����ٴ�ӡ����ʵ�ʵ��� s[1 ~ L-1]�����ٴ�ӡ������Ҳ����s[0 ~ L-2]�����ٴ�ӡ��������
������Ϊ��ӡ������һ���ַ����Ĵ�ӡ���������Լӱ䶯�����һ���Ĵ�ӡ���������ı��ӡ����
�����߿�����һ������α䶯�ģ���s[L ~ N-1]�Ĵ�ӡ��ǰ���ַ��Ĵ�ӡû�й�ϵ��
���Կ���һ���µ�Ŀ���ַ�������ͬ���ķ����������㡣
���������������L=1ʱ��s[0]==s[L-1]��Ȼ��������ʱ�Ĵ�Ϊ1 + s[1 ~ N-1]����С��ӡ������
L=Nʱ��Ӧ����s[0]==s[L-1]==s[N-1]�����������˵���ȣ���Ϊs[1 ~ N-1]����С��ӡ������

��. �ֱ�����s[1 ~ L-1]��s[L ~ N-1]����С��ӡ��������ӵõ��ض�L�µĴ�ӡ������
ö������L���Եõ��Ĵ�ȡ��Сֵ���ɵõ����մ𰸡�
������һ������ֳ�����С�������������ķ������������Ͷ�̬�滮��
״̬��ʾΪf[i][j]��ʾ��i��j����Ӵ����ٴ�ӡ������
������Բ��õ��Ƶķ�ʽ��Ӧ�ȴ�С����ö������ĳ��ȣ���Ϊ������Ĵ����ɶ�����Ĵ�ȷ���ģ�
�����п��ܵ�����Ĵ𰸶��������Ҳ�ɲ��ü��仯�����ĵݹ���ʽʵ�֣�
�߽�����Ϊ������Ϊ1��������ַ������ٴ�ӡ����Ϊ1��ö�����������ʱ�临�Ӷ�ΪO(n^2)��
ö�ٷֶε��ʱ�临�Ӷ�ΪO(n)�����ܵ�ʱ�临�Ӷ�ΪO(n^3)������ռ临�Ӷ�ΪO(n^2)��

(����)
�����������������ٴ�ӡ�ַ����Ĵ����ķ�ʽֻ���Ǣ��е��ڲ����ⲿ�����Ǹ��Ǳ߽硣
��˱��Ĳ����ַ��������(Start)��ʼ��ӡ��ѭ�����ұ߿�ʼ����(i)��
1�������������Ԫ�ص���StartԪ�أ����ַ���[start,i]��[i+1,end]
(count = count[start,i]+count[i+1,end])��Ȼ��ݹ�����ָ��������ַ�����
2�����������Ԫ�ز�����Start�����ַ�����Ϊstart��[start+1,end]���� 
(count = 1 + count[start+1,end])��Ȼ��ݹ�����ָ���һ���ַ�����
3��ÿ��Start������ӡ�󶼻�������С�Ĵ�ӡ�����������ء�
*/
#include <iostream>
#include <map>
#define MAXVALUE 100

using namespace std;

int WeirdPrinterCount(char* str, int start, int end)
{
	if (end <= start)
		return 0;
	else if (end - start == 1)
		return 1;
	else
	{
		int minCount = MAXVALUE, temp;
		for (int i = end-1; i > start; i--)
		{
			if (str[i] == str[start])
			{
				temp = WeirdPrinterCount(str, start + 1, i + 1)
					+ WeirdPrinterCount(str, i + 1, end);
			}
			else
			{
				temp = 1 + WeirdPrinterCount(str, start + 1, end);
			}
			if (temp < minCount)
				minCount = temp;
		}
		
		return minCount;
	}
}


void main()
{
	char str[] = "baaacccc";
	int i;
	cout << WeirdPrinterCount(str, 0, strlen(str)) << endl;
	cin >> i;
}