#include<stdio.h>
#include<string.h>
int dp[2][1001];
bool d[1000][1000];
int main(){
	char A[1001], B[1001], ans[1001];
	scanf("%s %s", A, B);
	int as=strlen(A), bs=strlen(B), t=0;
	for(int i=0;i<as;++i){
		for(int j=0;j<bs;++j){
			int k=dp[t][j+1];
			if(A[i]==B[j])	k=dp[t][j]+1;
			else if(k<dp[t^1][j])	d[i][j]=1, k=dp[t^1][j];
			dp[t^1][j+1]=k;
		}
		t^=1;
	}
	int x=as-1, y=bs-1, res=dp[t][bs];
	printf("%d\n", res);
	while(res){
		if(A[x]==B[y])	ans[--res]=A[x], --x, --y;
		else if(d[x][y])	--y;
		else	--x;
	}
	printf("%s\n", ans);
	return 0;
}
