#include "cameron.h"

#include <stdio.h>

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