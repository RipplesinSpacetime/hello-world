#include <stdio.h>

void main()
{
	char buf[128];

	snprintf(buf, sizeof(buf), "cp ./a.out ./b.out");

	system(buf);

	//system("reboot");
}


