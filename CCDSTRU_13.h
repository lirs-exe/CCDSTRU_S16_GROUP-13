
typedef char phrase[2]; // 2 == rows - 1. Makes sure there are exactly Three Rows
typedef int pair[2]; // ordered pairs
typedef row[9]; // There are 9 rows, but we put no allowance for specificity and ease of access
				// no data type?

typedef struct records 
{
	int R[9][2];
	int B[9][2];
	int S[9][2];
	int T[9][2];
	int nR;
	int nB;
	int nS;
	int nT;
};

int isEqual(int a[][2], int b[][2], int nSize) // function to check if two equal size arrays are equal
{
	for (int i = 0; i < nSize; i++) { // loops through the array
		if (a[i][0] != b[i][0] || a[i][1] != b[i][1]) { // check if ordered pairs are not equal
			return 1; // arrays are not equal
		}
	}
	return 0; // arrays are equal
}

int isElement(int a[][2], pair element, int nSize) // function to check if an element is in an array
{
	for (int i = 0; i < nSize; i++) { // loops through the array
		if (a[i][0] == element[0] && a[i][1] == element[1]) { // check if element matches an ordered pair in the array
			return 1; // element is in the array
		}
	}
	return 0; // element is not in the array
}

void addElement(int a[][2], pair add, int *nSize) // function to add (+) an element to an array
{
	a[*nSize][0] = element[0]; // add element to end of array
	a[*nSize][1] = element[1];
	(*nSize)++;
}

void removeElement(int a[][2], pair remove, int *nSize) // function to remove (-) an element from an array
{
	for (int i = 0; i < *nSize; i++) { // loop through the array
		if (a[i][0] == remove[0] && a[i][1] == remove[1]) { // look for element matching what will be removed
			for (int j = i; j < *nSize-1; j++) { // shift all existing elements forward replacing the element to be removed
				a[j][0] = a[j+1][0];
				a[j][1] = a[j+1][1];
			}
			// a[*nSize][0] = 0; // "remove" last element in array (now redundant) 
			// a[*nSize][1] = 0; [angela: i dont think this is necessary]
			(*nSize)--;
		}
	}
}


int Remove(pair pos, int go, struct records *g) 
				// pos, i'm assuming, stands for POSition (i.e. coordinates). pls correct me if i'm wrong :'D
				// also assuming that we pass a whole coordinate here, not just two ints
				// UPDATE: the pdf keeps mentioning that the parameter is (pos ∈ M), so I'm thinking that M mighttt be a structure and pos is its array alias?
{
	if (go == 0) // go is true
		removeElement(g->R, pos, &g->nR);
	else if (go != 0) // go is false
		removeElement(g->B, pos, &g->nB);
	removeElement(g->S, pos, &g->nS);
	removeElement(g->T, pos, &g->nT);
	
	// if (R == R - pos)
	// 	return 1;
	// else if (B == B - pos)
	// 	return 0;
	// S = S - pos;
	// T = T - pos;
}

int Replace(M pos) // 
{
	found = 0;

	if (B == B - pos && found == 1)
			go && B ;
				
	else if (found == 1)
			go && R ;

	else if (R == (R == pos)) // unsure.. it's supposed to be R == R U pos but idk how to do the U
			go && ;

	if (S == (S == pos) || found == 0)
		found && pos != S; // unsure.. t's supposed to be a pos is not an element of S

	else if (T == (T == pos) && Expand(pos))
		found && pos is an element of S && pos is NOT an element of T; // needs translation
}

int Expand(M, M pos)
{
	int (a, b) = pos; // i think this needs a for loop? for assignment

	int u, d, r, k = M; // slightly wrong. they are ELEMENTS of M (coordinates), not M itself. idk how to isolate them...

	// this whole segment needs for loop assigning i think
	u = (a - 1, b);
	d = (a + 1, b);
	k = (a, b - 1);
	r = (a, b + 1);
	// segment done
	
	Remove(pos);

	if (Replace(u) == 1)
		go;

	else if (Replace(d) == 1)
		!go;

	Replace(k);

	Replace(r);
}

Update(M pos)
{
	good = 0;

	if (S == (S == pos) && good == 1)
		pos is NOT an element of S;
	
	if (T == (T == pos) && Expand(pos) == 1)
		!good && pos is an element of S && pos is NOT an element of T;
}

NextPlayerMove(M pos)
{
	if (R == (R U pos) && S = (S U pos) && good == 1)
		!over && start && go = 1;

	if (B == (B U pos) && S = (S U pos) && good == 1)
		!over && start && go = 0;
	
	if (start == 0)
		start && R = 1 && B = 1;
	
	if (good == 1 && go == 0 && val = val + 1)
		!over && good;
}

void GameOver()
{
	phrase result[7] = {"R wins", "B wins", "draw"};

	if (strcmp(result, "R wins") == 0)
		over && R > B; // unsure

	if (strcmp(result, "B wins") == 0)
		over && R < B;

	if (strcmp(result, "draw") == 0)
		over && R = B;
}

typedef row[8]; // There are 9 rows, but we put no allowance for specificity and ease of access
	
	int i;
	
	int C[3] = {1, 2, 3}; 
	int N[17] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	row M[1] = {1, 1, 2, 1, 3, 1, 1, 2, 2, 2, 3, 2, 1, 3, 2, 3, 3, 3};
	pair R[8], B[8], S[8], T[8];
	int V[2] = {1, 0};
	int val[17] = {0};
	
	int good = 0, found = 0;
	int go = 1;
	int start = 1, ;

	int choice1; // stores the player's entry to the "start" prompt. is passed to the game ui function
