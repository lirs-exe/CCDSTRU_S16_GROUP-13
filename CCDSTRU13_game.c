#include <stdio.h>
#include "CCDSTRU13_functions.c"


// feel free to keep editing/refining the function codes, i'll continue figuring out the sequence of calling the functions in my own IDE. thanku !!

void EndCard()
{
	printf("\n=======================================\n");
	printf("	Thank you for Playing!\n");
	printf("=======================================\n");
}

void Instructions()
{
	int insChoice;
	
	printf("\n==========================\n");
	printf("      INSTRUCTIONS\n");
	printf("==========================\n\n");

	printf("         Hello!\n\n");
	
	printf("This is our Grid:\n\n");
	
	printf("                 X        \n\n");
	printf("         1       2       3\n");
	printf("     |	     |	     |	     |\n");
	printf("   1 | (1,1) | (1,2) | (1,3) |\n");
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("Y  2 | (2,1) | (2,2) | (2,3) |\n");
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("   3 | (3,1) | (3,2) | (3,3) |\n");
	printf("     |	     |	     |	     |\n\n\n");
	
	printf("The numbers within the () are Coordinates!\n\n");
	
	printf("We can think of them as values of (x,y)\n\n");
	
	printf("For example, in (1,2), x = 1 and y = 2 \n\n");

	printf("Take note of those Coordinates! You'll need them later!\n\n");
	
	printf("If ever you need to check them again, enter [3] in the prompt later.\n\n");
	
	printf("		  Ready?\n\n");
	
	printf("[ENTER 1 TO START]	[ENTER 2 TO EXIT]\n\n");
	printf("ENTER: ");
	
	scanf("%d", &insChoice);
	
	switch (insChoice)
	{
		case 1: break;
		case 2: EndCard(); break;
	}
}

void updateGrid(records *g) { // use this to update grid after every move
	char grid[3][3];
	pair currentPair;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			currentPair[0] = i+1; // +1 because coordinates start at 1
			currentPair[1] = j+1;
			
			if (isElement(g->R, currentPair, g->nR) == TRUE) {
				if (isElement(g->S, currentPair, g->nS) == TRUE) {
					grid[i][j] = 'R'; // uppercase R if already marked
				} else {
					grid[i][j] = 'r'; // lowercase r if not marked
				}
			} else if (isElement(g->B, currentPair, g->nB) == TRUE) {
				if (isElement(g->S, currentPair, g->nS) == TRUE) {
					grid[i][j] = 'B'; // uppercase B if already marked
				} else {
					grid[i][j] = 'b'; // lowercase b if not marked
				}
			} else {
				grid[i][j] = ' '; // empty/unclaimed
			}
		}
	}
	
	printf("                 X        \n\n");
	printf("         1       2       3\n");
	printf("     |	     |	     |	     |\n");
	printf("   1 |   %c   |   %c   |   %c   |\n", grid[0][0], grid[0][1], grid[0][2]);
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("Y  2 |   %c   |   %c   |   %c   |\n", grid[1][0], grid[1][1], grid[1][2]);
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("   3 |   %c   |   %c   |   %c   |\n", grid[2][0], grid[2][1], grid[2][2]);
	printf("     |	     |	     |	     |\n");
	printf("     ---------Move %d---------\n\n", g->val);
}

void movePrompt(records *g) {
	updateGrid(g);
	pair move = {1, 1};
	if (g->go == TRUE) {
		// ask for x
		do {
			if (move[0] > 3 || move[0] < 1) {
				printf("Invalid input!\n");
			}
			printf("It is the RED player's turn. Please input valid x coordinate: ");
			scanf("%d", &move[0]);
		} while (move[0] > 3 || move[0] < 1);
		// ask for y
		do {
			if (move[1] > 3 || move[1] < 1) {
				printf("Invalid input!\n");
			}
			printf("It is the RED player's turn. Please input valid y coordinate: ");
			scanf("%d", &move[1]);
		} while (move[1] > 3 || move[1] < 1);
	} else if (g->go == FALSE) {
		// ask for x
		do {
			if (move[0] > 3 || move[0] < 1) {
				printf("Invalid input!\n");
			}
			printf("It is the BLUE player's turn. Please input valid x coordinate: ");
			scanf("%d", &move[0]);
		} while (move[0] > 3 || move[0] < 1);
		// ask for y
		do {
			if (move[1] > 3 || move[1] < 1) {
				printf("Invalid input!\n");
			}
			printf("It is the BLUE player's turn. Please input valid y coordinate: ");
			scanf("%d", &move[1]);
		} while (move[1] > 3 || move[1] < 1);
	}
	
	NextPlayerMove(move, g);

}

// commenting this for now because im rewriting things
/* void Grid()
{
	printf("                 X        \n\n");
	printf("         1       2       3\n");
	printf("     |	     |	     |	     |\n");
	printf("   1 | (1,1) | (1,2) | (1,3) |\n");
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("Y  2 | (2,1) | (2,2) | (2,3) |\n");
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("   3 | (3,1) | (3,2) | (3,3) |\n");
	printf("     |	     |	     |	     |\n\n\n");
}

void Instructions()
{
	printf("\n==========================\n");
	printf("      INSTRUCTIONS\n");
	printf("==========================\n\n");

	printf("         Hello!\n\n");
	
	printf("This is our Grid:\n\n");
	
	printf("                 X        \n\n");
	printf("         1       2       3\n");
	printf("     |	     |	     |	     |\n");
	printf("   1 | (1,1) | (1,2) | (1,3) |\n");
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("Y  2 | (2,1) | (2,2) | (2,3) |\n");
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("   3 | (3,1) | (3,2) | (3,3) |\n");
	printf("     |	     |	     |	     |\n\n\n");
	
	printf("The numbers within the () are Coordinates!\n\n");
	
	printf("We can think of them as values of (x,y)\n\n");
	
	printf("For example, in (1,2), x = 1 and y = 2 \n\n");

	printf("Take note of those Coordinates! You'll need them later!\n\n");
	
	printf("If ever you need to check them again, enter [3] in the prompt later.\n\n");
	
	printf("		  Ready?\n\n");
	
	printf("[ENTER 1 TO START]	[ENTER 2 TO EXIT]\n\n");
	printf("ENTER: ");
	
	scanf("%d", &insChoice);
	
	switch (insChoice)
	{
		case 1: break;
		case 2: EndCard(); break;
	}
}

void playedEndCard()
{
	printf("\n=======================================\n");
	printf("%s Won! Thank you for Playing!\n", );
	printf("=======================================\n");

}

void GameProper()
{
	Instructions();
	
	printf("                 X        \n\n");
	printf("         1       2       3\n");
	printf("     |	     |	     |	     |\n");
	printf("   1 |       |       |       |\n");
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("Y  2 |       |       |       |\n");
	printf("     |	     |	     |	     |\n");
	printf("     -------------------------\n");
	printf("     |	     |	     |	     |\n");
	printf("   3 |       |       |       |\n");
	printf("     |	     |	     |	     |\n\n\n");
	
	while(!over)
	{
		printf("ENTER: ");
		scanf("%d", &nextChoice);
		
		switch (nextChoice)
			{
				case 0: EndCard(); break; // exit
				case 1: break; // continues game
				case 2: break;
				case 3: break; 
			}
	}
	
	if (over)
		{playedEndCard()};
}
 */
