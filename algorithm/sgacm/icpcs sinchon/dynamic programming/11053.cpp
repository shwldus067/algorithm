#include <stdio.h>
#define MAX 1050

int a[MAX];
int d[MAX];

int main(){
    int N, maxLength, maxResult;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < N; i++){
        maxLength = 0;
        for(int j = 0; j < i; j++){
            if(a[j]<a[i] && d[j]>maxLength) maxLength = d[j];
        }

        d[i] = maxLength + 1;
    }

    maxResult = 0;

    for(int i = 0; i < N; i++){
        if(d[i] > maxResult) maxResult = d[i];
    }

    printf("%d\n", maxResult);
    return 0;
}