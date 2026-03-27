typedef char phrase[7]; // 2 == rows - 1. Makes sure there are exactly Three Rows
typedef int pair[2]; // ordered pairs
typedef row[9]; // There are 9 rows, but we put no allowance for specificity and ease of access
				// no data type?

#define TRUE 1
#define FALSE 0

typedef struct
{
	pair R[9][2];
	pair B[9][2];
	pair S[9][2];
	pair T[9][2];
	int nR = 0;
	int nB = 0;
	int nS = 0;
	int nT = 0;
	
	int good = FALSE, found = FALSE;
	int go = TRUE;
	int start = TRUE;
	int val = 0;
} records;

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
	for (int i = 0; i < nSize; i++) { // loop through the array
		if (a[i][0] == element[0] && a[i][1] == element[1]) { // check if element matches an ordered pair in the array
			return TRUE; // element is in the array
		}
	}
	return FALSE; // element is not in the array
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


int Remove(pair pos, struct records *g) 
				// pos, i'm assuming, stands for POSition (i.e. coordinates). pls correct me if i'm wrong :'D
				// also assuming that we pass a whole coordinate here, not just two ints
				// UPDATE: the pdf keeps mentioning that the parameter is (pos ∈ M), so I'm thinking that M mighttt be a structure and pos is its array alias?
{
	if (g->go == TRUE) // go is true
		removeElement(g->R, pos, &g->nR); // remove pos from set R
	else if (g->go == FALSE) // go is false
		removeElement(g->B, pos, &g->nB); // remove pos from set B
	removeElement(g->S, pos, &g->nS); // remove pos from set S
	removeElement(g->T, pos, &g->nT); // remove pos from set T
	
	// if (R == R - pos)
	// 	return 1;
	// else if (B == B - pos)
	// 	return 0;
	// S = S - pos;
	// T = T - pos;
}

int Replace(pair pos, struct records *g)
{
	g->found = FALSE; // found is false

	if (g->go == TRUE) {
		if (isElement(g->B, pos, g->nB) == TRUE) { // if pos is an element of B
			removeElement(g->B, pos, &g->nB); // remove pos from set B
			g->found = TRUE; // found is true
		}
		if (isElement(g->R, pos, g->nR) == TRUE) // if pos is an element of R <- in specs its a generic if, not elif
			g->found = TRUE; // found is true
		if (isElement(g->R, pos, g->nR) == FALSE) // if pos not is an element of R <- in specs its a generic if, not elif
			addElement(g->R, pos, &g->nR); // add pos to R
	}

	else if (g->go == FALSE) {
		if (isElement(g->R, pos, g->nR) == TRUE) { // if pos is an element of R
			removeElement(g->R, pos, &g->nR); // remove pos from set R
			g->found = TRUE; // found is true
		}
		if (isElement(g->B, pos, g->nB) == TRUE) // if pos is an element of B <- in specs its a generic if, not elif
			g->found = TRUE; // found is true
		if (isElement(g->B, pos, g->nB) == FALSE) // if pos not is an element of B <- in specs its a generic if, not elif
			addElement(g->B, pos, &g->nB); // add pos to B
	}

	if (g->found == TRUE && (isElement(g->S, pos, g->nS) == FALSE)) { // if found is true and pos is not in set S
		addElement(g->S, pos, &g->nS); // add pos to set S
		g->found = FALSE; // reset found (found is false)
	}
	
	if (g->found == TRUE && (isElement(g->S, pos, g->nS == TRUE)) && (isElement(g->T, pos, g->nT) == FALSE)) { // if found is true, pos is in set S, and pos is not in set T
		addElement(g->T, pos, &g->nT); // add pos to set T
		expand(pos, go, g); // expand(pos)
	}
	
	// found = 0;
	// if (B == B - pos && found == 1)
	// 		go && B ;	
	// else if (found == 1)
	// 		go && R ;
	// else if (R == (R == pos)) // unsure.. it's supposed to be R == R U pos but idk how to do the U
	// 		go && ;
	// if (S == (S == pos) || found == 0)
	// 	found && pos != S; // unsure.. t's supposed to be a pos is not an element of S
	// else if (T == (T == pos) && Expand(pos))
	// 	found && pos is an element of S && pos is NOT an element of T; // needs translation
}

int Expand(pair pos, struct records *g)
{
	// int (a, b) = pos; // i think this needs a for loop? for assignment <- wont make an (a, b) pair anymore since it doesnt seem to be necessary
	
	// int u, d, r, k = M; // slightly wrong. they are ELEMENTS of M (coordinates), not M itself. idk how to isolate them... <- this is just a fact being stated so idt it needs to be coded in
	
	// // this whole segment needs for loop assigning i think
	// u = (a - 1, b);
	// cell to left of pos
	pair u;
	u[0] = pos[0] - 1; // a-1
	u[1] = pos[1]; // b
	
	// d = (a + 1, b);
	// cell to right of pos
	pair d;
	d[0] = pos[0] + 1; // a+1
	d[1] = pos[1]; // b
	
	// k = (a, b - 1);
	// cell under pos
	pair k;
	k[0] = pos[0]; // a
	k[1] = pos[1] - 1; // b-1
	
	// r = (a, b + 1);
	// cell on top of pos
	pair r;
	r[0] = pos[0]
	r[1] = pos[1] + 1
	
	// // segment done
	
	// Remove(pos);
	Remove(pos, go, records);
	
	// if (Replace(u) == 1)
	// 	go;
	// else if (Replace(d) == 1)
	// 	!go;
	// ^^ this is mistranslated i believe
	if (g->go == TRUE) {
		Replace(u, records);
	} else {
		Replace(d, records);
	}
	Replace(k, records);
	Replace(r, records);
}

Update(pair pos, struct records *g)
{
	g->good = FALSE;

	if (isElement(g->S, pos, &g->nS) == FALSE) {
		addElement(g->S, pos, &g->nS);
		g->good = TRUE;
	}
	if (g->good == FALSE && (isElement(g->T, pos, &g->nT) == FALSE) && (isElement(g->S, pos, &g->nS) == TRUE)) {
		addElement(g->T, pos, &g->nT);
		Expand(pos, g); // not sure pa
	}
	
	// good = 0;
	// if (S == (S == pos) && good == 1)
	// 	pos is NOT an element of S;
	// if (T == (T == pos) && Expand(pos) == 1)
	// 	!good && pos is an element of S && pos is NOT an element of T;
}

NextPlayerMove(pair pos, struct records *g)
{
	if (g->over == FALSE && g->start == TRUE && g->go == TRUE) { // over = false, start = true, go = true
		addElement(g->R, pos, &g->nR); // add pos to R
		addElement(g->S, pos, &g->nS); // add pos to S
		g->good = TRUE; // good = true
	}
	if (g->over == FALSE && g->start == TRUE && g->go == FALSE) { // over = false, start = true, go = false
		addElement(g->B, pos, &g->nB); // add pos to B
		addElement(g->S, pos, &g->nS); // add pos to S
		g->good = TRUE; // good = true
	}
	if (g->over == FALSE && g->start == FALSE && ((g->go == TRUE && (isElement(g->R, pos, g->nR) == TRUE)) || (g->go == FALSE && (isElement(g->B, pos, g->nB) == TRUE)))) { // im not translating this just trust me bro
		Update(pos, g); // update(pos)
		g->good = TRUE; // good = true
	}
	
	if (g->start == TRUE && g->nR == 1 && g->nB == 1) { // start = true, size of R = 1, size of B = 1
		g->start == FALSE; // start = false
	}
	if(g->over == FALSE && g->good == TRUE) { // over = false, start = true
		g->good == FALSE; // negate good
		if (g->go == TRUE) { // negate go
			g->go = FALSE;
		} else {
			g->go = TRUE;
		}
		g->val = g->val + 1; // val + 1
	}
	/* if (R == (R U pos) && S = (S U pos) && good == 1)
		!over && start && go = 1;

	if (B == (B U pos) && S = (S U pos) && good == 1)
		!over && start && go = 0;
	
	if (start == 0)
		start && R = 1 && B = 1;
	
	if (good == 1 && go == 0 && val = val + 1)
		!over && good; */
}

void GameOver(struct records *g)
{
	if (g->over == TRUE) {
		if (g->nR > g->nB) {
			printf("R wins!");
		}
		if (g->nR < g->nB) {
			printf("B wins!");
		}
		if (g->nR == g->nB) {
			printf("Draw!");
		}
	}
	/* phrase result[3] = {"R wins", "B wins", "draw"};

	if (strcmp(result, "R wins") == 0)
		over && R > B; // unsure

	if (strcmp(result, "B wins") == 0)
		over && R < B;

	if (strcmp(result, "draw") == 0)
		over && R = B; */
}

typedef row[8]; // There are 9 rows, but we put no allowance for specificity and ease of access
	
	