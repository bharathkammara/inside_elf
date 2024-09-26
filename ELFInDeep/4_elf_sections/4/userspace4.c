#include <stdio.h>

int myval = 5;
int uninitialized;

void hello()
{
	printf("Hello\n");
	return;
}

int main()
{
	hello();
	myval++;
	return 5;
}
