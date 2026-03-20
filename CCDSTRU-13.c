#include <stdio.h>
#include <string.h>

typedef char phrase[2];


int Remove(pos[]) // pos, i'm assuming, stands for POSition (i.e. coordinates). pls correct me if i'm wrong :'D
				// also assuming that we pass a coordinate here, not just two ints
{
	if (R == R - pos)
		return 1;
		
	else if (B == B - pos)
		return 0;

	S = S - pos;

	T = T - pos;
}

int Replace(pos) // 
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

int Expand(M, pos)
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

Update(pos)
{
	good = 0;

	if (S == (S == pos) && good == 1)
		pos is NOT an element of S;
	
	if (T == (T == pos) && Expand(pos) == 1)
		!good && pos is an element of S && pos is NOT an element of T;
}

NextPlayerMove(pos)
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

int main()
{
	typedef row[8];
	
	int i;
	
	int C[3] = {1, 2, 3}; 
	int N[17] = ,{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	row M[1] = {1, 1, 2, 1, 3, 1, 1, 2, 2, 2, 3, 2, 1, 3, 2, 3, 3, 3};
	int R[8], B[8], S[8], T[8];
	int V[2] = {1, 0};
	int val[17] = {0};
	
	int good = 0, found = 0;
	int go = 1;
	int start = 1, ;
	

	
	return 0;
}
