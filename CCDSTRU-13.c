#include <stdio.h>
#include <string.h>

#include "CCDSTRU_13.h"
#include "13_FUNCS.h"

int main()
{
	struct records g;
	g.nR = 0;
	g.nB = 0;
	g.nS = 0;
	g.nT = 0;
	
	g.good = FALSE;
	g.found = FALSE;
	g.go = TRUE;
	g.start = TRUE;
	g.val = 0;


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
