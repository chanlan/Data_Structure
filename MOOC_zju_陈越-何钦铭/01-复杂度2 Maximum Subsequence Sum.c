#include <stdio.h>
int a[100005];
int main()
{
    int temp,k,start,end1,sum;
    sum=-1;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<k;i++){
        temp=0;
        for(int j=i;j<k;j++){
            temp=temp+a[j];
            if(temp>sum){
                sum=temp;
                start=a[i];
                end1=a[j];
            }
        }
    }
    if(sum<=-1)
        printf("0 %d %d",a[0],a[k-1]);
    else
        printf("%d %d %d",sum, start, end1);
    
    
    return 0;
}
