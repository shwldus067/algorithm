#include<iostream>
using namespace std;
struct shark{
	int r, c, d;
}S[401];
int N, M, K;
struct arr{
	int n, t, e;
}A[20][20];
int dr[5]={0, -1, 1, 0, 0}, dc[5]={0, 0, 0, -1, 1};
int dd[401][5][4];
bool done[401];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int tp;
			cin>>tp;
			if(tp){
				S[tp]={i, j, 0};
				A[i][j]={tp, 1, 0};
			}
		}
	}
	for(int i=1;i<=M;++i)	cin>>S[i].d;
	for(int i=1;i<=M;++i){
		for(int j=1;j<5;++j)for(int k=0;k<4;++k)
				cin>>dd[i][j][k];
	}
	int ans=2;
	while(1){
		if(ans>1002){
			ans=1;break;
		}
		int f=1;
		for(int i=2;i<=M;++i){
			if(!done[i]){
				f=0;break;
			}
		}
		if(f)	break;
		for(int i=1;i<=M;++i){
			if(done[i])	continue;
			f=0;
			int r=S[i].r, c=S[i].c, d=S[i].d;
			for(int j=0;j<4;++j){
				int nd=dd[i][d][j];
				int nr=r+dr[nd], nc=c+dc[nd];
				if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
				if(!A[nr][nc].n || A[nr][nc].t+K<ans){
					S[i]={nr, nc, nd};
					A[nr][nc]={i, ans, 1};
					f=1;break;
				}
				else if(A[nr][nc].e && A[nr][nc].t==ans){
					done[i]=1;f=1;break;
				}
			}
			if(f)	continue;
			for(int j=0;j<4;++j){
				int nd=dd[i][d][j];
				int nr=r+dr[nd], nc=c+dc[nd];
				if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
				if(A[nr][nc].n==i){
					S[i]={nr, nc,nd};
					A[nr][nc]={i, ans, 0};
					break;
				}
			}
		}
		ans++;
	}
	cout<<ans-2<<"\n";
	return 0;
}
