#include <stdio.h>
#include <sys/sysinfo.h>

void main()
{
	struct sysinfo info;

	sysinfo(&info);

	printf("%d\n", info.uptime);
}
