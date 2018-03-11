#include <cstdio>

int main(){
    int k;
    scanf("%d", &k);
    int this_sum = 0, max_sum = -1;
    int first = 0, end = 0, tmp_first = 0;
    int flag = 0;
    int neg_begin = 0, neg_end = 0;
    int is_first = 1;
    for(int i = 0; i < k; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp >=0) flag = 1;
        this_sum += tmp;
        if(this_sum >= 0 && is_first){
            tmp_first = tmp;
            is_first = 0;
        }

        if(this_sum > max_sum){
            max_sum = this_sum;
            end = tmp;
            first = tmp_first;
        }
        if(this_sum < 0){
            this_sum = 0;
            is_first = 1;
        }
        if(i == 0) neg_begin = tmp;
        if(i == k-1) neg_end = tmp;
    }
    if(flag)
        printf("%d %d %d", max_sum, first, end);
    else
        printf("0 %d %d", neg_begin, neg_end);
    return 0;
}
