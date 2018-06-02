#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define MAXTABLESIZE 100000
typedef struct LNode* List;
typedef List Position;
struct LNode{
    char id[11];
    char passwd[17];
    List Next;
};

typedef struct TblNode* HashTable;
struct TblNode{
    int TableSize;
    List Heads;
};

int Hash(int key, int TableSize){
	return (key % TableSize);
}

int nextPrime(int N){
    int i, p = (N % 2) ? N+2 : N+1;
    while( p < MAXTABLESIZE ){
        for(int i = sqrt(p); i > 2; i--)
            if(!(p % i)) break;
        if(i == 2) break;
        else p += 2;
    }
    return p;
}

Position Find(HashTable H, char key[]){
    Position P;
    int pos;
    pos = Hash(atoi(key+3), H->TableSize);
    P = H->Heads[pos].Next;
    while(P && strcmp(P->id, key))
        P = P->Next;
    return P;
}

HashTable CreateTable(int TableSize){
    HashTable H;
    int i;
    H = (HashTable)malloc(sizeof(struct TblNode));
    H->TableSize = TableSize;
	H->Heads = (List)malloc(sizeof(struct LNode)*TableSize);
    for(int i = 0; i < H->TableSize; i++){
        H->Heads[i].id[0] = '\0';
        H->Heads[i].passwd[0] = '\0';
        H->Heads[i].Next = NULL;
    }
    return H;
}

bool Insert(HashTable H, char key[], char passwd[]){
    Position P, NewNode;
    int pos;
    P = Find(H, key);
    if(!P){
        NewNode = (Position)malloc(sizeof(struct LNode));
        strcpy(NewNode->id, key);
        strcpy(NewNode->passwd, passwd);
        pos = Hash(atoi(key+3), H->TableSize);
        NewNode->Next = H->Heads[pos].Next;
        H->Heads[pos].Next = NewNode;
        return true;
    }
    else
        return false;
}

void destroyTable(HashTable H){
    int i;
	Position P, Tmp;
	for(int i = 0; i < H->TableSize; i++){
		P = H->Heads[i].Next;
		while(P){
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->Heads);
	free(H);
}

int main(){
    int N;
    char commond;
    scanf("%d", &N);
    char tmp_id[11], tmp_passwd[17];
    HashTable H = CreateTable(nextPrime(N));
    while(N--){
        scanf("\n%c", &commond);
        scanf("%s %s", tmp_id, tmp_passwd);
        if(commond == 'L'){
            Position ptr = Find(H, tmp_id);
            if(ptr){
                if(!strcmp(ptr->passwd, tmp_passwd))
                    printf("Login: OK\n");
                else
                    printf("ERROR: Wrong PW\n");
            }
            else
                printf("ERROR: Not Exist\n");
        }
        else{
            if(Insert(H, tmp_id, tmp_passwd))
                printf("New: OK\n");
            else
                printf("ERROR: Exist\n");
        }
    }
	destroyTable(H);
    return 0;
}