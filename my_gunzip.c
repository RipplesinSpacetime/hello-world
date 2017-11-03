#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

int my_gunzip(const char* in, const char* out)
{
	FILE* fp2;
	char buf[1024];
	int len = 0;
	int ret = 0;
}
void main()
{
	DIR *dir;
	struct dirent *entry;
	char real_name[PATH_MAX];
	char exe[128];
	char* name; 
	char* ptr;
	
	dir = opendir("./");
	while((entry = readdir(dir)) != NULL)
	{
		name = entry->d_name;
		ptr = strchr(name, '.');
		if(!memcmp(ptr, ".gzip", sizeof(".gzip")))
		{
			printf("%s\n", name);
			break;
		}
	}
}
