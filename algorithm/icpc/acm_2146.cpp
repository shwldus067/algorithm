#include<iostream>
#include<queue>
using namespace std;
int N, res, cnt=0, island[100][100];
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
bool visit[100][100];
bool chk(int nr, int nc){
	if(nr<0 || nr>=N || nc<0 || nc>=N)	return false;
	return true;
}
void find(int r, int c, int n){
	queue<pair<int, int> > Q;
	Q.push({r, c});
	visit[r][c]=true;
	int nr, nc, cr, cc, i_num=n*2-1;
	island[r][c]=i_num;
	bool out=false;
	while(Q.size()){
		cr=Q.front().first, cc=Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++){
			nr=cr+dr[i], nc=cc+dc[i];
			if(chk(nr, nc)){
				if(island[nr][nc]){
					if(!visit[nr][nc]){
						visit[nr][nc]=true;
						island[nr][nc]=i_num;
						Q.push({nr, nc});
					}
				}
				else out=true;
			}
		}
		if(out)	island[cr][cc]++;
	}
}
int bfs(int n){
	int out=2*n, in=out-1;
	queue<pair<int, int> > Q;
	fill(&visit[0][0], &visit[N-1][N], false);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(island[i][j]==out){
				visit[i][j]=true;
				Q.push({i, j});
			}
			else if(island[i][j]==in){
				visit[i][j]=true;
			}
		}
	}
	int ans=0, s, nr, nc, r, c;
	while(s=Q.size()){
		while(s--){
			r=Q.front().first, c=Q.front().second;
			Q.pop();
			for(int i=0;i<4;i++){
				nr=r+dr[i], nc=c+dc[i];
				if(!chk(nr, nc))	continue;
				if(island[nr][nc]){
					if(!visit[nr][nc])	return ans;
				}
				else{
					if(!visit[nr][nc]){
						visit[nr][nc]=true;
						Q.push({nr, nc});
					}
				}
			}
		}
		ans++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int c;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>island[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(island[i][j] && !visit[i][j]){
				find(i, j, ++cnt);
			}
		}
	}
	res=~(1<<31);
	for(int i=1;i<=cnt;i++)
		res=min(res, bfs(i));
	cout<<res<<"\n";
	return 0;
}
