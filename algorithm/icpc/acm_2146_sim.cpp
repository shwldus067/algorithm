#include<iostream>
#include<queue>
using namespace std;
const int inf=~(1<<31);
int N, res, cnt=0, visit[100][100], dist[100][100];
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
bool island[100][100];
queue<pair<int, int> > qu;
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
			if(chk(nr, nc)){
				if(!visit[nr][nc]){
					if(island[nr][nc]){
						visit[nr][nc]=n;
						Q.push({nr, nc});
					}
					else{
						visit[nr][nc]=n;
						dist[nr][nc]=1;
						qu.push({nr, nc});
					}
				}
				else if(visit[nr][nc]!=visit[r][c]){
					res=1;
					return ;
				}
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
			if(!visit[i][j] && island[i][j]){
				find(i, j, ++cnt);
				if(res==1){
					cout<<"1\n";
					return 0;
				}
			}
		}
	}
	int r, c, nr, nc, size, dis=2;
	res=inf;
	while(size=qu.size()){
		while(size--){
			r=qu.front().first, c=qu.front().second;
			qu.pop();
			for(int i=0;i<4;i++){
				nr=r+dr[i], nc=c+dc[i];
				if(chk(nr, nc) && !island[nr][nc]){
					if(visit[nr][nc]==0){
						visit[nr][nc]=visit[r][c];
						dist[nr][nc]=dis;
						qu.push({nr, nc});
					}
					else if(visit[nr][nc]!=visit[r][c]){
						res=min(res, dist[nr][nc]+dist[r][c]);
					}
				}
			}
		}
		if(res!=inf){
			cout<<res<<"\n";
			return 0;
		}
		dis++;
	}
	return 0;
}
