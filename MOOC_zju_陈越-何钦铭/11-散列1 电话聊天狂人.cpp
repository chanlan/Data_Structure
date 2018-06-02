#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define MAXLENGTH 11
#define MAXD 5
#define MAXTABLESIZE 1000000

typedef struct LNode* List;
typedef List Position;
struct LNode{
	char Data[MAXLENGTH+1];
	List Next;
	int Count;
};

typedef struct TblNode* HashTable;
struct TblNode{
	int TableSize;
	List Heads;
};

int Hash( int key, int P){
	return key % P;
}

int NextPrime( int N ){
	int i, p = (N%2) ? N+2 : N+1;
	while( p < MAXTABLESIZE){
		for(i = sqrt(p); i > 2; i--)
			if(!(p%i)) break;
		if( i == 2 ) break;
		else p += 2;
	}
	return p;
}

Position Find(HashTable H, char key[]){
	Position P;
	int Pos;
	Pos = Hash(atoi(key+MAXLENGTH-MAXD), H->TableSize);
	P = H->Heads[Pos].Next;
	while(P && strcmp(P->Data, key))
		P = P->Next;
	return P;
}

HashTable CreateTable( int TableSize ){
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = TableSize;
	H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode));
	for(i = 0; i < H->TableSize; i++){
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].Next = NULL;
		H->Heads[i].Count = 0;
	}
	return H;
}

bool Insert(HashTable H, char key[]){
	Position P, NewCell;
	int Pos;
	P = Find(H, key);
	if(!P){
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, key);
		NewCell->Count = 1;
		Pos = Hash(atoi(key+MAXLENGTH-MAXD), H->TableSize);
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else{
		P->Count++;
		return false;
	}
}

void scanAndOutput( HashTable H ){
	int i, maxCnt, pCnt;
	maxCnt = pCnt = 0;
	char minPhone[MAXLENGTH+1];
	minPhone[0] = '\0';
	List Ptr;
	for(i = 0; i < H->TableSize; i++){
		Ptr = H->Heads[i].Next;
		while(Ptr){
			if(Ptr->Count > maxCnt){
				pCnt = 1;
				maxCnt = Ptr->Count;
				strcpy(minPhone, Ptr->Data);
			}
			else if(Ptr->Count == maxCnt){
				pCnt++;
				if(strcmp(minPhone, Ptr->Data) > 0)
					strcpy(minPhone, Ptr->Data);
			}
			Ptr = Ptr->Next;
		}
	}
	printf("%s %d", minPhone, maxCnt);
	if(pCnt > 1) printf(" %d", pCnt);
	printf("\n");
}

void destroyTable( HashTable H ){
    int i;
    Position P, tmp;
    for(i = 0; i < H->TableSize; i++){
        P = H->Heads[i].Next;
        while(P){
            tmp = P->Next;
            free(P);
            P = tmp;
        }
    }
    free(H->Heads);
	free(H);
}

int main(){
	int N;
	scanf("%d", &N);
	char key[MAXLENGTH+1];
	HashTable H = CreateTable(N*2);
	for(int i = 0; i < N; i++){
		scanf("%s", key);
		Insert(H, key);
		scanf("%s", key);
		Insert(H, key);
	}
	scanAndOutput(H);
	destroyTable(H);
	return 0;
}
