#include <stdio.h>

void main()
{
	char i = 32;
	char j = 5 ;
	char *ptr = &i;

	sscanf(ptr, "%c", &j);
	printf("%d\n",(unsigned int)i);
	printf("%d\n",(unsigned int)j);
	printf("%d\n",(unsigned int)(*ptr));

}
