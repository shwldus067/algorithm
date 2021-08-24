#include<iostream>
#include<queue>
using namespace std;
int M, N, arr[500][500], dp[500][500], ans=0;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
int dfs(int r, int c){
	if(r==M-1 && c==N-1)	return 1;
	int &ret=dp[r][c];
	if(ret!=-1)	return ret;
	ret=0;
	for(int i=0;i<4;++i){
		int nr=r+dr[i], nc=c+dc[i];
		if(nr<0 || nr>=M || nc<0 || nc>=N)	continue;
		if(arr[nr][nc]>=arr[r][c])	continue;
		ret+=dfs(nr, nc);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	cin>>M>>N;
	for(int i=0;i<M;++i)for(int j=0;j<N;++j)	cin>>arr[i][j], dp[i][j]=-1;
	cout<<dfs(0, 0)<<"\n";
	return 0;
}
