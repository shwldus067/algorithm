#include<iostream>
#include<queue>
using namespace std;
struct str{
	int r, c, dir, cost;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int dd[5]={0, 0, 2, 1, 3};
	int dr[4]={0, 1, 0, -1}, dc[4]={1, 0, -1, 0};
	int M, N, arr[100][100];
	bool visit[100][100][4]={0, };
	int r1, c1, d1, r2, c2, d2;
	cin>>M>>N;
	for(int i=0;i<M;++i)for(int j=0;j<N;++j)	cin>>arr[i][j];
	cin>>r1>>c1>>d1>>r2>>c2>>d2;
	r1--;c1--;r2--;c2--;
	d1=dd[d1];d2=dd[d2];
	queue<str> Q;
	Q.push({r1, c1, d1, 0});
	visit[r1][c1][d1]=1;
	int ans=0;
	while(Q.size()){
		int r=Q.front().r, c=Q.front().c;
		int dir=Q.front().dir, cost=Q.front().cost;
		Q.pop();
		if(r==r2 && c==c2 && dir==d2){
			ans=cost;
			break;
		}
		
		int nd=dir==3?0:dir+1;
		if(!visit[r][c][nd]){
			visit[r][c][nd]=cost+1;
			Q.push({r, c, nd, cost+1});
		}
		nd=dir==0?3:dir-1;
		if(!visit[r][c][nd]){
			visit[r][c][nd]=cost+1;
			Q.push({r, c, nd, cost+1});
		}
		
		int nr=r, nc=c;
		for(int i=0;i<3;++i){
			nr=nr+dr[dir], nc=nc+dc[dir];
			if(nr<0 || nr>=M || nc<0 || nc>=N)	break;
			if(arr[nr][nc]==1)	break;
			if(!visit[nr][nc][dir]){
				visit[nr][nc][dir]=1;
				Q.push({nr, nc, dir, cost+1});
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
