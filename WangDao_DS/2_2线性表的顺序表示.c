//2.2.1顺序表的定义
//静态分配顺序表
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;
// 动态分配顺序表
#define InitSize 100
typedef struct {
	ElemType *data;
	int MaxSize, length;
}SqList;
//C:
L = (ElemType*)malloc(sizeof(SqList));
//C++:
L = new ElemType[InitSize];
//注意表的索引从0开始，位置i从1开始
bool ListInsert(SqList &L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}
bool ListDelete(SqList &L, int i, int &e) {
	if (i < 1 || i >L.length)
		return false;
	e = L.Data[i - 1];
	for (int j = i; j < L.length; j++) 
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}
//按值查找（顺序查找）
int LocateElem(SqList L, ElemType e) {
	int i;
	for (i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}