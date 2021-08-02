#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, G, R, arr[50][50], ldx, ans;
int dr[4]={-1, 1, 0, 0}, dc[4]={0, 0, -1, 1};
int visit[50][50], p[10];
pii land[10];
struct fld{
	int t, r, c;
};
queue<fld> Q;
void bfs();
void sol(int x, int g, int r){
	if(x==ldx){
		if(g==0 && r==0){
			for(int i=0;i<N;++i)for(int j=0;j<M;++j)	visit[i][j]=1e9;
			for(int i=0;i<ldx;++i){
				if(p[i]==1){
					visit[land[i].first][land[i].second]=1;
					Q.push({0, land[i].first, land[i].second});
				}
				else if(p[i]==2){
					visit[land[i].first][land[i].second]=1;
					Q.push({1, land[i].first, land[i].second});
				}
			}
			bfs();
		}
		return;
	}
	if(g+r>ldx-x)	return;
	if(g==ldx-x){
		for(int i=x;i<ldx;++i)	p[i]=1;
		sol(ldx, 0, r);
		for(int i=x;i<ldx;++i)	p[i]=0;
		return;
	}
	if(r==ldx-x){
		for(int i=x;i<ldx;++i)	p[i]=2;
		sol(ldx, g, 0);
		for(int i=x;i<ldx;++i)	p[i]=0;
		return;
	}
	if(g)	p[x]=1, sol(x+1, g-1, r);
	if(r)	p[x]=2, sol(x+1, g, r-1);
	p[x]=0;
	sol(x+1, g, r);
	return;
}
void bfs(){
	int cnt=2, flw=0, sz;
	while(sz=Q.size()){
		while(sz--){
			int t=Q.front().t, r=Q.front().r, c=Q.front().c;
			Q.pop();
			if(visit[r][c]==-1)	continue;
			for(int i=0;i<4;++i){
				int nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
				if(arr[nr][nc]==0 || visit[nr][nc]<cnt)	continue;
				if(visit[nr][nc]==cnt){
					if(t){
						flw++;
						visit[nr][nc]=-1;
						continue;
					}
					continue;
				}
				else if(visit[nr][nc]==cnt+1){
					if(t)	continue;
					flw++;
					visit[nr][nc]=-1;
					continue;
				}
				visit[nr][nc]=cnt;
				if(t)	visit[nr][nc]++;
				Q.push({t, nr, nc});
			}
		}
		cnt+=2;
	}
	if(flw>ans)	ans=flw;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>G>>R;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>arr[i][j];
			if(arr[i][j]==2){
				land[ldx++]={i, j};
			}
		}
	}
	sol(0, G, R);
	cout<<ans<<"\n";
	return 0;
}
