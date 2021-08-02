#include <stdio.h>

int arr[3000][3000];
int N;
int cnt1, cnt2, cnt3;

void chk(int x, int y, int l){
    if(l == 0) return;
    int t1 = 0, t2 = 0, t3 = 0;
    for(int i = x; i < l + x; i++){
        for(int j = y; j < l + y; j++){
            if(arr[i][j] == -1) t1++;
            else if(arr[i][j] == 0) t2++;
            else t3++;
        }
    }
    if(t1 == l*l) cnt1++;
    else if(t2 == l*l) cnt2++;
    else if(t3 == l*l) cnt3++;
    else{
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                chk(x + i*l/3, y + j*l/3, l/3);
            }
        }
    }
    
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    chk(0, 0, N);
    printf("%d\n%d\n%d\n", cnt1, cnt2, cnt3);
}