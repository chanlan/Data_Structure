#define MAXTABLESIZE 100000 //允许开辟的最大散列表的长度
typedef int ElementType;
typedef int Index;
typedef Index Position;
//散列单元状态类型,分别对应:有合法元素,空单元,有已删除元素.
typedef enum { Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry Cell;//散列表单元类型
struct HashEntry{
	ElementType Data;//存放元素
	EntryType Info;//单元状态
};

typedef struct TblNode *HashTable; //散列表的类型
struct TblNode{//散列表结点的定义
	int TableSize;//散列表的最大长度
	Cell *Cells; //存放散列单元的数组
};

int NextPrime( int N ){
//返回大于N且不超过MAXTABLESIZXE的最小素数
	int i, p = (N%2) ? N+2 : N+1;
	while( p <= MAXTABLESIZE){
		for( i = (int)sqrt(p); i >2 i--)
			if( !(p%i) ) break;
		if( i == 2 ) break;
		else p += 2;
	}
	return p;
}

HashTable CreatTable( int TableSize ){
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Cells = (Cell*)malloc(H->TableSize * sizeof(Cell))
	for( i = 0; i < H->TableSize; i++)
		H->Cells[i].info = Empty;
	return H;
}