#include<iostream>
#include<queue>
using namespace std;
int N, res, cnt=0, visit[100][100], dist[100][100];
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
bool island[100][100];
bool chk(int nr, int nc){
	if(nr<0 || nr>=N || nc<0 || nc>=N)	return false;
	return true;
}
void find(int r, int c, int n){
	queue<pair<int, int> > Q;
	visit[r][c]=n;
	Q.push({r, c});
	int nr, nc, cr, cc;
	while(Q.size()){
		cr=Q.front().first, cc=Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++){
			nr=cr+dr[i], nc=cc+dc[i];
			if(chk(nr, nc) && island[nr][nc] && !visit[nr][nc]){
				visit[nr][nc]=n;
				Q.push({nr, nc});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>island[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visit[i][j] && island[i][j])
				find(i, j, ++cnt);
		}
	}
	queue<pair<int, int> > Q;
	int r, c, nr, nc;
	for(r=0;r<N;r++)
		for(c=0;c<N;c++)
			if(!island[r][c])
				for(int i=0;i<4;i++){
					nr=r+dr[i], nc=c+dc[i];
					if(chk(nr, nc) && island[nr][nc]){
						visit[r][c]=visit[nr][nc];
						dist[r][c]=1;
						Q.push({r, c});
						break;
					}
				}
	res=~(1<<31);
	while(Q.size()){
		r=Q.front().first, c=Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++){
			nr=r+dr[i], nc=c+dc[i];
			if(chk(nr, nc)){
				if(island[nr][nc]){
					if(visit[r][c]!=visit[nr][nc])
						res=min(res, dist[r][c]);
				}
				else{
					if(visit[nr][nc]){
						if(visit[r][c]!=visit[nr][nc])
							res=min(res, dist[r][c]+dist[nr][nc]);
					}
					else{
						visit[nr][nc]=visit[r][c];
						dist[nr][nc]=dist[r][c]+1;
						Q.push({nr, nc});
					}
				}
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}
