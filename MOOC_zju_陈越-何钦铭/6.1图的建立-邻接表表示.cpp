//ͼ���ڽӱ��ʾ��
#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

//�ڽӵ�Ķ���
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};

//�����ͷ���Ķ���
typedef struct VNode{
	PtrToAdjVNode FirstEdge;
	DataType Data;
} AdjList[MaxVertexNum];

//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;