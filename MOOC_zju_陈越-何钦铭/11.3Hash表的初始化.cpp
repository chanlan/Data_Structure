typedef struct HashTbl* HashTable;
struct HashTbl{
    int TableSize;
    Cell* TheCells;
}H;
HashTable InitializeTable(int TableSize){
    HashTable H;
    int i;
    if(TableSize < MinTableSize){
        Error("散列表太小");
        return NULL;
    }
    H = (HashTable)malloc(sizeof(struct HashTbl));
    if(H == NULL)
        FatalError("空间溢出");
    H->TableSize = NextPrime(TableSize);
    H->TheCells = (Cell*)malloc(sizeof(Cell)*H->TableSize);
    if(H->TheCells == NULL)
        FatalError("空间溢出");
    for(i = 0; i < H->TableSize; i++)
        H->TheCells[i].Info = Empty;
    return H;
}
