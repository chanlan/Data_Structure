#define KEYLENGTH 15;
typedef char ElementType[KEYLENGTH];
typedef int Index;
typedef struct LNode* PtrToLNode;
struct LNode{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode* HashTable;
struct TblNode{
    int TableSize;
    List Heads;
};

HashTable CreatTable(int TableSize){
    HashTable H;
    int i;
    H = (HashTable)malloc(sizeof(struct TblNode));
    H->TableSize = NextPrime(TableSize);
    H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode));
    for(i = 0; i < H->TableSize; i++){
        H->Heads[i].Data[0] = '\0';
        H->Heads[i].Next = NULL;
    }
    return H;
}

Position Find(HashTable H, ElementType key){
    Position P;
    Index Pos;
    Pos = Hash(key, H->TableSize);
    P = H->Heads[Pos].Next;
    while(P && strcmp(P->Data, key))
        P = P->next;
    return P;
}
bool Insert(HashTable H, ElementType Key){
    Position P, NewCell;
    Index Pos;
    P = Find(H, key);
    if(!P){
        NewCell = (Position)malloc(sizeof(struct LNode));
        strcpy(NewCell->Data, key);
        Pos = Hash(key, H->TableSize);
        NewCell->Next = H->Heads[Pos].next;
        H->Heads[Pos].Next = NewCell;
        return true;
    }
    else{
        printf("键值已存在");
        return false;
    }
}
void DestroyTable(HashTable H){
    int i;
    Position P, Tmp;
    for(i = 0; i < H->TableSize; i++){
        P = H->Head[i].Next;
        while(P){
            Tmp = P->Next;
            free(P);
            P = Tmp;
        }
    }
    free( H->Heads );
    free(H);
}