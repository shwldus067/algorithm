#include<cstdio>
#include<cstring>
int dp[1001][1001];
int main(){
	char A[1001]={1,}, B[1001]={1,}, ans[1001];
	char d[1001][1001];
	scanf("%s %s", A+1, B+1);
	int as=strlen(A), bs=strlen(B);
	for(int i=1;i<as;++i){
		for(int j=1;j<bs;++j){
			if(A[i]==B[j])	dp[i][j]=dp[i-1][j-1]+1, d[i][j]=0;
			else if(dp[i-1][j]<dp[i][j-1])	dp[i][j]=dp[i][j-1], d[i][j]=1;
			else	dp[i][j]=dp[i-1][j], d[i][j]=2;
		}
	}
	int x=as-1, y=bs-1, res=dp[x][y]-1;
	while(x && y){
		if(!d[x][y])	ans[res--]=A[x], --x, --y;
		else if(d[x][y]==1)	--y;
		else	--x;
	}
	printf("%d\n%s\n", dp[as-1][bs-1], ans);
	return 0;
}
