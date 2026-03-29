#define TRUE 1
#define FALSE 0

typedef char phrase[7]; // 2 == rows - 1. Makes sure there are exactly Three Rows
typedef int pair[2]; // ordered pairs


typedef struct
{
	pair R[9];
	pair B[9];
	pair S[9];
	pair T[9];
	int nR;
	int nB;
	int nS;
	int nT;
	
	int good;
	int found;
	int go;
	int start;
	int val;
	int over;
} records;

// - - - UTILITY - - -
int isEqual(int a[][2], int b[][2], int nSize);
int isElement(int a[][2], pair element, int nSize);
void addElement(int a[][2], pair add, int *nSize);
void removeElement(int a[][2], pair remove, int *nSize);

// - - - SPECIFIED FUNCTIONS - - -
void Remove(pair pos, records *g);
void Replace(pair pos, records *g);
void Expand(pair pos, records *g);
void Update(pair pos, records *g);
void NextPlayerMove(pair pos, records *g);
void GameOver(records *g);