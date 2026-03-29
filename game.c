#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "CCDSTRU_13.h"
//#include "13_FUNCS.h"

typedef char phrase[7]; // 2 == rows - 1. Makes sure there are exactly Three Rows
typedef int pair[2]; // ordered pairs

#define TRUE 1
#define FALSE 0

typedef char str[11];

typedef struct
{
	pair R[9][2];
	pair B[9][2];
	pair S[9][2];
	pair T[9][2];
	int nR;
	int nB;
	int nS;
	int nT;
	
	int good, found;
	int go;
	int start;
	int val;
	int over;
} records;


/*================================================
					FUNCTIONS
================================================*/


void GameOver(str result)
{
	if (g->over == TRUE) {
		if (g->nR > g->nB) {
			strcpy(result, "R wins");
		}
		if (g->nR < g->nB) {
			strcpy(result, "B wins");
		}
		if (g->nR == g->nB) {
			strcpy(result, "Draw");
		}
	}
}	

void playedEndCard(str result)
{
	printf("\n=======================================\n");
	printf("%s! Thank you for Playing!\n", result);
	printf("=======================================\n");

}

void EndCard(struct records *g)
{
	printf("\n=======================================\n");
	printf("	Thank you for Playing!\n");
	printf("=======================================\n");
	
	g.over = 1; // update this 
}


void GameProper(struct records *g)
{
do
{
	movePrompt(g);
	
	do
	{
		if (R[0] == B[0] && R[1] == B[1])
			{Replace(g)};
			
		{
			Remove(g);
			Replace(g);
			Expand(g);
			Update(g);
			movePrompt(g); //
		}
	}
	while (F != 3 || g->val >= 20 || ((!(g.start)) && ((nR > 0 && nB == 0) || (nR == 0 && nB > 0)))
	
	str result;
	
	GameOver();
	
	playedEndCard(result);
}
}


void Instructions(struct records *g)
{
	int insChoice;
	
	system("cls");
	
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
		case 1: GameProper(g); break;
		case 2: EndCard(g); break;
		default: printf("Error. Please try again!"); Instructions(records g); break;
	}
}


/*================================================
					MAIN
================================================*/


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
	
	int choice1;
		
	printf("Welcome!\n"); // add design maybe?
	printf("[ENTER 1 TO START]		[ENTER 2 TO EXIT]");
	printf("[]: ");

	scanf("%d", &choice1);

	if (choice1 == g.start)
		Instructions(records g);
	
	else 
		EndCard(g);
	
	return 0;
}
	
