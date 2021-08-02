#include<stdio.h>
int N, M, H, ans=4;
bool A[31][11];
bool chk(){
	for(int i=1;i<=N;++i){
		int t=i;
		for(int j=1;j<=H;++j){
			if(A[j][t])	++t;
			else if(A[j][t-1])	--t;
		}
		if(t!=i)	return false;
	}
	return true;
}
void sol(int cnt, int g){
	if(ans!=4)	return;
	if(cnt==g){
		if(chk())	ans=ans>g?g:ans;
		return;
	}
	for(int j=1;j<N;++j){
		for(int i=1;i<=H;++i){
			if(A[i][j] || A[i][j+1] || A[i][j-1])	continue;
			A[i][j]=1;
			sol(cnt+1, g);
			A[i][j]=0;
			while(i<=H && !A[i][j-1] && !A[i][j+1])	++i;
		}
	}
}
int main(){
	scanf("%d %d %d", &N, &M, &H);
	while(M--){
		int a, b;
		scanf("%d %d", &a, &b);
		A[a][b]=1;
	}
	for(int i=0;i<4;++i){
		sol(0, i);
		if(ans!=4){
			printf("%d\n", ans);
			break;
		}
	}
	if(ans==4)	printf("-1\n");
	return 0;
}
