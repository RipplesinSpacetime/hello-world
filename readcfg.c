#include <stdio.h>
#include <string.h>

void main(void)
{
	FILE* fpr;
	FILE* fpw;
	char buf[256] = {0};
	int tmp;
	int i;
	char *ptr;

	system("cp 1.cfg 1.bak");
	fpr = fopen("1.cfg", "r");
	fpw = fopen("1.bak", "w");


	if(fpr == NULL)
	{
		printf("Open file error!\n");
	}

	while(!feof(fpr))
	{
		fgets(buf, sizeof(buf), fpr);
		if(feof(fpr)) 
		{	
			break;
		}

		if(buf[0] != '#' && strchr(buf, '=') != NULL)
		{
			if(strstr(buf, "HELLO") != NULL)
			{
				sprintf(buf, "HELLO = 1\n");
			}
			else if(strstr(buf, "WORLD") != NULL)
			{
				sprintf(buf, "WORLD = 2\n");
			}
			else if(strstr(buf, "GOODBYE") != NULL)
			{
				sprintf(buf, "GOODBYE = 3\n");
			}
			else if(strstr(buf, "DATA") != NULL)
			{
				ptr = strstr(buf, "DATA");
				ptr = (char*)ptr + sizeof("DATA =");
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

				printf("DATA = %d\n", tmp);
			}

		}

		fputs(buf, fpw);
	}

	fclose(fpr);
	fclose(fpw);
}
