#include <stdio.h>
#include <string.h>

#include "CCDSTRU_13.h"
#include "13_FUNCS.h"

int main()
{
	int i;
	
	int C[3] = {1, 2, 3}; 
	int N[17] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	row M[1] = {1, 1, 2, 1, 3, 1, 1, 2, 2, 2, 3, 2, 1, 3, 2, 3, 3, 3};
	records gameRecords;
	int V[2] = {1, 0};


	int choice1; // stores the player's entry to the "start" prompt. is passed to the game ui function

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
