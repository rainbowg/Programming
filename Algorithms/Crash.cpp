#include <stdlib.h>
#include <string>

void Crash(void)
{
	int i = 0;
	int j = 1;
	j /= i;
}

int main(void)
{
	char buf[10];
	memset(buf, 0, 10);
	
	Crash();

	strcpy_s(buf, "123456789123");
	system("pause");

	return 0;
}