#include <stdio.h>
#include <string.h>

#include "CCDSTRU_13.h"

int main()
{
	printf("Welcome!\n");
	printf("[ENTER 1 TO START]		[ENTER 2 TO EXIT]");
	printf("[]: ");

	scanf("%d", &choice1);

	if (choice1 == start)
		GameProper();
	
	else 
		EndCard();

	return 0;
}
