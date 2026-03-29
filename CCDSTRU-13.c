#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CCDSTRU13_game.c"

int isGameOver (records *g) {
	int gameOver = FALSE;
	
	// splitting the propositions for readability
	if ((9 - (g->nR + g->nB)) == 3) {
		printf("Game over! (available cells = 3, nR = %d, nB = %d)\n", g->nR, g->nB);
		gameOver = TRUE;
	} else if (g->val >= 20) {
		printf("Game over! (turn > 20)\n");
		gameOver = TRUE;
	} else if (g->start == FALSE) {
		if (g->nR > 0 && g->nB == 0) {
			printf("Game over! (no more blue cells)\n");
			gameOver = TRUE;
		} else if (g->nR == 0 && g->nB > 0) {
			printf("Game over! (no more red cells)\n");
			gameOver = TRUE;
		}
	}
	
	return gameOver;
}

void GameProper (records *g) {
	// instructions
	Instructions();
	system("cls");
	
	// main game
	do {
		movePrompt(g);
/* 		if (g->go == TRUE) {
			g->go = FALSE;
		} else {
			g->go = TRUE;
		} */
	} while (isGameOver(g) == FALSE);
	
	// ending
	updateGrid(g);
	GameOver(g);
	printf("\n");
	EndCard();
}


int main()
{
	records g;
	
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

	if (choice1 == 1)
		GameProper(&g);
	else 
		EndCard();

	return 0;
}
