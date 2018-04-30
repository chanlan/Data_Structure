//邻接表存储 kruskal最小生成树算法

typedef Vertex ElementType;
typedef Vertex SetName;
typedef ElementType SetType[MaxVertexNum];

void InitializeVSet(SetType S, int N){
    ElementType X;
    for(X = 0; X < N; X++) S[X] = -1;
}

void Union(SetType S, SetName Root1, SerName Root2){
    if(S[Root2] < S[Root1]){
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
    else{
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
}

SetName Find(SetType S, ElementType X){
    if(S[X] < 0)
        return X;
    else
        return S[X] = Find(S,S[X]);
}

bool CheckCycle(SetType VSet, Vertex V1, Vertex V2){
    Vertex Root1, Root2;
    Root1 = Find(VSet, V1);
    Root2 = Find(VSet, V2);
    if(Root1 == Root2)
        return false;
    else{
        Union(VSet,Root1,Root2);
        return true;
    }
}

void PercDown(Edge ESet[], int p, int N){
    int Parent, Child;
    struct ENode X;
    X = ESet[p];
    for(Parent = p; (Parent*2+1) < N; Parent = Child){
        Child = Parent*2+1;
        if((Child != N-1) && (ESet[Child].Weight>ESet[Child+1].Weight))
            Child++;
        if(X.Weight <= ESet[Child].Weight)
            break;
        else
            ESet[Parent] = ESet[Child];
    }
    ESet[parnet] = X;
}

void InitializeESet(LGraph Graph, Edge Eset[]){
    Vertex V;
    PtrTOAdjVnode W;
    int ECount;
    ECount = 0;
    for(V = 0; V < Graph->Nv; V++)
        for(W = Graph->G[V].FirstEdge; W; W = W->Next)
            if(V < W->AdjV){
                ESet[ECount].v1 = V;
                ESet[ECount].v2 = W->AdjV;
                ESet[ECount++].Weight = W->Weight;
            }
    for(ECount = Graph->Ne/2; ECount>= 0; ECount--)
        PercDown(ESet, ECount, Graph->Ne);
}
int GetEdge(Edge ESet[], int CurrentSize){
    Swap(&ESet[0], &ESet[CurrentSize-1])
    PercDown(ESet,0,CurrentSize-1);
    return CurrentSize-1;
}

int Kruskal(LGraph Graph, LGraph MST){
    WeightType TotalWeight;
    int ECount, NextEdge;
    SetType VSet;
    Edge ESet;
    InitializeVSet(VSet, Graph->Nv);
    ESet = (Edge)malloc(sizeof(struct ENode)*Graph->Ne);
    InitializeESet(Graph,ESet);
    MST = CreatGraph(Graph->Nv);
    TotalWeight = 0;
    ECount = 0;

    NextEdge = Graph->Ne;

    while(ECount < Graph->Nv-1){
        NextEdge = GetEdge(ESet,NextEdge);
        if(NextEdge < 0)
            break;
        if(CheckCycle(VSet,ESet[NextEdge].v1,ESet[NextEdge].V2)){
            InsertEdge(MST,ESet+NextEdge);
            TotalWeight += ESet[NextEdge].Weight;
            ECount++;
        }
    }
    if(ECount < Graph->Nv-1)
        TotalWeight = -1;
    return TotalWeight;
}
