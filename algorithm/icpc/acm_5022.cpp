#include<iostream>
#include<queue>
using namespace std;
#define Max 100000
typedef pair<int, int> pii;
int N, M, ans=Max;
pii P[2][2];
int chk[101][101]={0, };
int bfs(int t, int n){
	int dir[101][101]={0, };
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	int cnt=0, nt=t?0:1;
	int gr=P[t][1].first, gc=P[t][1].second;
	int sr=P[t][0].first, sc=P[t][0].second;
	queue<pii> Q;
	dir[sr][sc]=-1;
	dir[P[nt][0].first][P[nt][0].second]=dir[P[nt][1].first][P[nt][1].second]=1;
	Q.push({sr, sc});
	while(int size=Q.size()){
		while(size--){
			pii cur=Q.front();Q.pop();
			if(cur.first==gr && cur.second==gc){
				if(n){
					for(int r=gr, c=gc, d=0;dir[r][c]!=-1;r-=dr[d-1], c-=dc[d-1]){
						chk[r][c]=1;
						d=dir[r][c];
					}
					chk[sr][sc]=1;
					cnt+=bfs(t^1, 0);
					for(int r=gr, c=gc, d=0;dir[r][c]!=-1;r-=dr[d-1], c-=dc[d-1]){
						chk[r][c]=0;
						d=dir[r][c];
					}
					chk[sr][sc]=0;
				}
				return cnt;
			}
			for(int i=0;i<4;++i){
				int nr=cur.first+dr[i], nc=cur.second+dc[i];
				if(nr<0 || nr>N || nc<0 || nc>M)	continue;
				if(chk[nr][nc] || dir[nr][nc])	continue;
				dir[nr][nc]=i+1;
				Q.push({nr, nc});
			}
		}
		cnt++;
	}
	return Max;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	cin>>P[0][0].first>>P[0][0].second>>P[0][1].first>>P[0][1].second;
	cin>>P[1][0].first>>P[1][0].second>>P[1][1].first>>P[1][1].second;
	ans=min(ans, bfs(0, 1));
	ans=min(ans, bfs(1, 1));
	if(ans>=Max)	cout<<"IMPOSSIBLE\n";
	else	cout<<ans<<"\n";
	return 0;
}
