#include <stdio.h>
#include <string.h>

void  main()
{
	char buf1[128] = "Hello";
	char buf2[] = "World";

	printf("%s\n", buf1);

	strcat(buf1, buf2);

	printf("%s\n", buf1);
}
