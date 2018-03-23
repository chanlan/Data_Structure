#include <cstdio>
#include <cstdlib>

typedef struct PNode* List;
struct Node {
    int Address;
    int Data;
    int Next;
}array[100001];

struct PNode {
    int Address;
    int Data;
    List link;
};

int main(){
    int firstAddress, totalNode, reverseNum, realNum = 0;
    scanf("%d %d %d", &firstAddress, &totalNode, &reverseNum);
    for(int i = 0; i < totalNode; i++) {
        int tmp;
        scanf("%d", &tmp);
        scanf("%d %d", &array[tmp].Data, &array[tmp].Next);
        array[tmp].Address = tmp;
    }
    List head = (List)malloc(sizeof(struct Node));
    head->link = NULL;
    List Rear = head;
    while(firstAddress != -1){
        realNum++;
        List tmpNode = (List) malloc(sizeof(struct PNode));
        tmpNode->Address = array[firstAddress].Address;
        tmpNode->Data = array[firstAddress].Data;
        tmpNode->link = Rear->link;
        Rear->link = tmpNode;
        Rear = tmpNode;
        firstAddress = array[firstAddress].Next;
    }
    //reverse
    List PRear, PProcess, PNext, PTmpHead, PPreHead;
    PPreHead = head;
    PRear = PPreHead->link;
    int count = 0;
    while(count < realNum/reverseNum) {
        count++;
        PTmpHead = PRear;
        PProcess = PRear;
        PNext = PProcess->link;
        for (int i = 1; i < reverseNum; i++) {
            PProcess = PNext;
            PNext = PNext->link;
            PProcess->link = PTmpHead;
            PTmpHead = PProcess;
        }
        PPreHead->link = PTmpHead;
        PPreHead = PRear;
        PRear->link = PNext;
        PRear = PNext;
    }

    List tmp = head->link;
    while(tmp->link){
        printf("%05d %d %05d\n",tmp->Address, tmp->Data, tmp->link->Address);
        tmp = tmp->link;
    }
    printf("%05d %d -1",tmp->Address, tmp->Data);
    return 0;
}
