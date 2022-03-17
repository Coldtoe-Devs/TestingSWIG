#include "cameron.h"

#include <stdio.h>
#include <time.h>

int add3(int x) {
    return x + 3;
}

int getNumber()
{
	int number;
	char text[20]; 

	printf("Enter a number: ");
	scanf("%d", &number);

	sprintf(text, "%d", number);

	printf("\nYou have entered: %s\n", text);

	return 0;
}

int * getArray( ) {

	static int  r[10];
	int i;

	for ( i = 0; i < 10; ++i)
	{
		r[i] = i;
	}

	return r;
}
