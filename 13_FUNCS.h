void EndCard()
{
	printf("\n=======================================\n");
	printf("	Thank you for Playing!\n");
	printf("=======================================\n");
	
	over = 1; // update this 
}

void Grid()
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
