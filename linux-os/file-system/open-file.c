/*************************************************************************
    > File Name: open-file.c
    > Author: DHD
    > Mail: 
    > Created Time: 2020年07月20日 星期一 23时21分02秒
 ************************************************************************/
#include<stdio.h>
#include<unistd.h>

int main()
{
    char * filename = "test";
	FILE * fd = fopen(filename, "rw");

	printf("pid: %d\n", getpid());
	while(1) {
		sleep(1);
	}

	fclose(fd);
	return 0;
}
