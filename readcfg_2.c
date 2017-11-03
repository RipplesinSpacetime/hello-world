#include <stdio.h>
#include <string.h>

static int get_value(char* buf)
{
	char *ptr;
	int tmp;

	ptr = buf;
	if(buf == NULL)	
	{
		printf("invalid input!\n");
		return -1;
	}
	else
	{
		tmp = 0;
		while(*ptr == ' ') 
		{
			(char*)ptr++;
		}
		while(*ptr >= '0' && *ptr <= '9')
		{
			tmp = tmp*10 + (*ptr - '0');
			ptr = (char*)ptr + 1;
		}
	}

	return tmp;
}

void main(void)
{
	FILE* fpr;
	char buf[256] = {0};
	int tmp;
	int i;
	int len;
	static int count = 0;
	char *ptr;

	fpr = fopen("1.cfg", "r");

	if(fpr == NULL)
	{
		printf("Open file error!\n");
	}

	while(!feof(fpr))
	{
		fgets(buf, sizeof(buf), fpr);
		len = strlen(buf);
		if(len <= 0)
		{
			break;
		}
		printf("%d times: get data from file:len = %d, %s", ++count, len, buf);

		if(buf[0] != '#' && strchr(buf, '=') != NULL)
		{
			if(strstr(buf, "DATA") != NULL)
			{
				ptr = strstr(buf, "DATA");
				ptr = (char*)ptr + sizeof("DATA =");
				tmp = get_value(ptr);

				printf("DATA = %d\n", tmp);
			}

		}

	}

	fclose(fpr);
}









