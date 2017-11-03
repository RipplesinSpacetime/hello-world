#include <stdio.h>

int main()
{
	int i = 2;
	char c1 = 'c';
	char c2 = 'g';
	printf("Hello,world!\n");
	printf("Goodbye\n");

	printf("i = %d, !i = %d, !!!i = %d\n", i, !i, !!!i);

	for(i = 0; i < 255; i++)
	{
		printf("!i = %d\n", !i);
	}

	printf("c1 = %d, c2 = %d\n", c1, c2);
	printf("c1 = %c, c2 = %c\n", c1, c2);
	printf("c1 = %02x, c2 = %02x\n", c1, c2);

	printf("%.1f\n", 55*100*6.8);
}

