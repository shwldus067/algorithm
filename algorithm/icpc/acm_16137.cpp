#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int> > pip;
int N, M, arr[10][10], K, ans=1e9;
int d[10][10][20];
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
void bfs(){
	memset(d, -1, sizeof(d));
	queue<pip> Q;
	Q.push({0, {0, 0}});
	d[0][0][0]=0;
	while(Q.size()){
		int t=Q.front().first, nt;
		int r=Q.front().second.first, c=Q.front().second.second;
		Q.pop();
		if(arr[r][c]>1 && t%arr[r][c]){
			nt=(t+1)%arr[r][c];
			if(d[r][c][nt]==-1){
				d[r][c][nt]=d[r][c][t]+1;
				Q.push({nt, {r, c}});
			}
		}else{
			for(int i=0;i<4;++i){
				int nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
				if(arr[r][c]>1 && arr[nr][nc]>1)	continue;
				if(arr[nr][nc]){
					nt=(d[r][c][t]+1)%arr[nr][nc];
					if(d[nr][nc][nt]==-1){
						d[nr][nc][nt]=d[r][c][t]+1;
						Q.push({nt, {nr, nc}});
					}
				}
			}
		}
	}
	if(d[K][K][0]!=-1)	ans=min(ans, d[K][K][0]);
}
bool chk(int i, int j){
	bool v=0, h=0;
	if(j-1>=0 && arr[i][j-1]==0)	h=1;
	if(j+1<N && arr[i][j+1]==0)	h=1;
	if(i-1>=0 && arr[i-1][j]==0)	v=1;
	if(i+1<N && arr[i+1][j]==0)	v=1;
	return !(h&&v);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>arr[i][j];
	K=N-1;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		if(arr[i][j]==0 && chk(i, j)){
			arr[i][j]=M;
			bfs();
			arr[i][j]=0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
