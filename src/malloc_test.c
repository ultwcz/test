#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef unsigned long long LL;

int *test_malloc(LL size)
{
	int *data = (int *)malloc(sizeof(int) * size);

	return data;
}


int main(int argv, char *argc[])
{
	while (1) {
		int *test = test_malloc(1000);	
		if (!test)
			fprintf(stderr, "malloc failed\n");
	}

	exit(0);
}
