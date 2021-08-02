#include<iostream>
#include<queue>
using namespace std;
const int inf=~(1<<31);
int N, M, res=inf;
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
char wall[1000][1000];
bool visit[1000][1000], b;
bool chk(int nr, int nc){
	return nr>=0 && nr<N && nc>=0 && nc<M;
}
void dfs(int r, int c, int n){
	if(res<n+(N-r)+(M-c))	return ;
	if(r==N-1 && c==M-1){
		if(res>n)	res=n;
		return ;
	}
	int nr, nc;
	for(int i=0;i<4;i++){
		nr=r+dr[i], nc=c+dc[i];
		if(!chk(nr, nc) || visit[nr][nc])	continue;
		if(wall[nr][nc]=='0'){
			visit[nr][nc]=true;
			dfs(nr, nc, n+1);
			visit[nr][nc]=false;
		}
		else if(!b){
			visit[nr][nc]=true;
			b=true;
			dfs(nr, nc, n+1);
			b=false;
			visit[nr][nc]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			cin>>wall[i][j];
		}
	visit[0][0]=true;
	dfs(0, 0, 1);
	if(res==inf)	cout<<"-1\n";
	else	cout<<res<<"\n";
	return 0;
}
