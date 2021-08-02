#include<cstdio>
int N, arr[8];
bool chk[9];
void print(int n){
	if(n==N){
		for(int i=0;i<N;++i)	printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=N;++i){
		if(!chk[i]){
			chk[i]=1;
			arr[n]=i;
			print(n+1);
			chk[i]=0;
		}
	}
}
int main(){
	scanf("%d", &N);
	print(0);
	return 0;
}
