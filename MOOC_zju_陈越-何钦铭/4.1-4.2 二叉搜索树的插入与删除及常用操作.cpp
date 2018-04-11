typedef struct TNode* Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

Position Find(ElementType X, BinTree BST){
	if(!BST) return NULL;
	if(X > BST->Data)
		return Find(X, BST->Right);
	else if(X < BST->Data)
		return Find(X, BST->Left);
	else return BST;
}

Position IterFind(ElementType X, BinTree BST){
	while(BST){
		if(X > BST->Data)
			BST = BST->Right;
		else if(X < BST->Data)
			BST = BST->Left;
		else return BST;
	}
	return NULL;
}
Position FindMin(BinTree BST){
	if(!BST) return NULL;
	else if (!BST->Left) 
		return BST;
	else
		return FindMin(BST->Left);
}
Position FindMax(BinTree BST){
	if(BST)
		while(BST->Right) BST = BST->Right;
	return BST;
}

BinTree Insert(BinTree BST, ElementType X){
	if(!BST){
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else{
		if(X < BST->Data)
			BST->Left = Insert(BST->Left, X);
		else if( X > BST->Data)
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}
BinTree Delete(BinTree BST, ElementType X){
	Position Tmp;
	if(!BST)
		printf("NOT FOUND");
	else{
		if(X > BST->Data)
			BST->Left = Delete(BST->Right, X);
		else if(X < BST->Data)
			BST->Right = Delete(BST->Left, X);
		else{
			if(BST->Left && BST->Right){
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				BST->Right = Delete(BST->Right, BST->Data);
			}else{
				Tmp = BST;
				if(!BST->Left)
					BST = BST->Right;
				else
					BST = BST->Left;
				free(Tmp);
			}
		}
	}
}