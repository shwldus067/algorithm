#include<cstdio>
using namespace std;
int N, M, ans;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, -1, 0, 1};
int dp[50][50];
bool visit[50][50];
char board[50][51];
int dfs(int r, int c, int n){
	visit[r][c]=1;
	dp[r][c]=n;
	int dd=board[r][c]-'0';
	for(short i=0;i<4;++i){
		int nr=r+dr[i]*dd, nc=c+dc[i]*dd;
		if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
		if(board[nr][nc]=='H')	continue;
		if(visit[nr][nc])	return -1;
		if(dp[nr][nc]>=n+1)	continue;
		if(dfs(nr, nc, n+1)==-1)	return -1;
	}
	visit[r][c]=0;
	if(ans<n)	ans=n;
	return 0;
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;++i)	scanf("%s", board+i);
	if(dfs(0, 0, 1)==-1)	printf("-1\n");
	else	printf("%d\n", ans);
	return 0;
}
