#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElemType int
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
void Reverse(int R[], int from, int to) {
	int i, temp;
	for (i = 0; i < (to - from + 1) / 2; i++) {
		temp = R[from + i];
		R[from + i] = R[from + i] = R[to - i];
		R[to - i] = temp;
	}
}
void Converse(int R[], int n, int p) {
	Reverse(R, 0, p - 1);
	Reverse(R, p, n - 1);
	Reverse(R, 0, n - 1);
}

int M_Search(int A[], int B[], int n) {
	int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
	while (s1 != d1 || s2 != d2) {
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if (A[m1] == B[m2]) 
			return A[m1];
		if (A[m1] < B[m2]) {
			if ((s1 + d1) % 2 == 0) {
				s1 = m1;
				d2 = m2;
			}
			else {
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		else {
			if ((s2 + d2) % 2 == 0) {
				d1 = m1;
				s2 = m2;
			}
			else {
				d1 = m1;
				s2 = m2 + 1;
			}
		}
	}
	return A[s1] < B[s2] ? A[s1] : B[s2];
}
int Majority(int A[], int n) {
	int i, c, count = 1;
	c = A[0];
	for (i = 1; i < n; i++)
		if (A[i] == c)
			count++;
		else
			if (count > 0)
				count--;
			else {
				c = A[i];
				count = 1;
			}
			if (count > 0)
				for (i = count = 0; i < n; i++)
					if (A[i] == c)
						count++;
			if (count > n / 2) return c;
			else return - 1;
}

