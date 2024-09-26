#include <stdio.h>

void unused_call(void)
{
	printf("This should not be executed\n");
}

int main(int argc, char *argv[])
{
	printf("Hello World\n");
	return 0;
}
