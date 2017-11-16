bool Del_Min(sqList &L, ElemType &value) {
	if (L.length == 0)
		return false;
	value = L.data[0];
	int pos = 0
	for(int i=1; i<L.length; i++)
		if (L.data[i] < value) {
			value = L.data[i];
			pos = i;
		}
	L.data[pos] = L.data[L.length - 1];
	L.length--;
	return true;
}
void Reverse(SqList &L) {
	ElemType temp;
	for (i = 0; i < L.length / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - i - 1] = temp;
	}
}
void Del_X_1(SqList &L, ElemType X) {
	int k;
	for (i = 0; i < L.length; i++)
		if (L.data[i] != X) {
			L.data[K] = L.data[i];
			k++;
		}
	L.length = k;
}
void Del_X_2(Sqlist &L, ElemType X) {
	int k = 0, i = 0;
	while (i < L.length) {
		if (L.data[i] == x)
			k++;
		else
			L.data[i - k] = L.data[i];
		i++;
	}
	L.length = L.length - k;
}
bool Del_S_t2(SqList &L, ElemType , ElemType t) {
	if (s >= t || L.length == 0)
		return false;
	for (i = 0; i < L.length&& L.data[i] < s; i++);
	if (i >= L.length)
		return false;
	for (j = i; j < L.length&&L.data[j] <= t; j++);
	for (; j < L.length; i++, j++)
		L.data[i] = L.data[j];
	L.length = i;
	return true;
 }

bool Del_S_t(SqList &L, ElemType s, ElemType t) {
	int i, k=0;
	if(L.length == 0 || s>=t)
		return false;
	for(i = 0; i< L.length; i++){
		if(L.data[i] >= s && L.data[i] <= t)
			k++;
		else
			L.data[i-k] = L.data[i];
	}
	L.length -= k;
	return true;
}
bool Delete_Same(SqList &L){
	if (L.length == 0)
		return false;
	for(i=0, j=1; j<length; j++)
		if(L.data[i] != L.data[j])
			L.data[++i] = L.data[j];
	L.length = i+1;
	return true;
}
bool Merge(SqList A, Sqlist B, SqList &C){
	if(A.length +B.length > C.maxSize)
		return false;
	int i =0, j=0, k=0;
	while(i < A.length && j<B.length){
		if(A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while(i < A.length)
		C.data[k++] = A.data[i++];
	while(i < B.length)
		C.data[k++] = B.data[j++];
	C.length = k;
	return true;
}
typedef int DataType;
void Reverse(DataType A[], int left, int right, int arraySize){
	if(left >= right || right >= arraySize)
		return ;
	int mid = (left + right)/2;
	for(int i=0; i<mid -left;i++){
		DataType temp = A[left +i];
		A[left + i] = A[right - i];
		A[right-i] = temp;
	}
}
void exchange(DataType A[], int m, int n, int arraySize){
	Reverse(A, i, m+n-1, arraySize);
	Reverse(A, 0, n-1, arraySize);
	Reverse(A, n, m+n-1, arraySize);
}
void SearchExchangeInsert(ElemType A[], ElemType x){
	int low =0, high = n-1, mid;
	while(low <= high){
		mid = (low +high)/2;
		if(A[mid] == x) break;
		else if(A[mid] < x) low = mid +1;
		else high = mid -1;
	}
	if (A[mid] == x && mid != n-1){
		t = A[mid]; 
		A[mid] = A[mid+1];
		A[mid+1] = t;
	}
	if (low >high){
		for(i = n-1; i>high; i--) A[i+1] = A[i];
		A[i+1] = x;
	}
}



