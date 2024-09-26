#include <stdio.h>

int myval = 5;
int uninitialized;

void hello()
{
	return;
}

int main()
{
	hello();
	myval++;
	uninitialized++;
	return 5;
}
