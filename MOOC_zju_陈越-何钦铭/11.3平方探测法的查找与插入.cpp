Position Find(HashTable H, ElementType Key){
	Position CurrentPos, NewPos;
	int CNum = 0;
	NewPos = CurrentPos = Hash(key, H->TableSize);//初始散列位置
	while(H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != key){
		//字符串类型的关键字要用strcmp
		if(++CNum % 2){
			NewPos = CurrentPos + (CNum+1)*(CNum+1)/4; //增量为+[(CNum+1)/2]^2
		}
		else{
			NewPos = CurrentPos - CNum*CNum)/4; //增量为-(CNum/2)^2
			while(NewPos < 0)
				NewPos += H->TableSize;
		}
	}
	return NewPos;
}

bool Insert(HashTable H, ElementType Key){
	Position Pos = Find(H, key);
	if(H->Cells[Pos].Info != Legitimate){
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = key;
		return true;
	}
	else{
		printf("键值已存在");
		return false;
	}
}