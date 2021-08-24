#include<iostream>
using namespace std;
int N, M, arr[5][5], ans;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, -1, 0, 1};
int dd[4][2]={{1, 2}, {0, 1}, {0, 3}, {2, 3}};
bool chk[6][6];
void sol(int r, int c, int n){
	if(c==M){
		sol(r+1, 0, n);
		return;
	}
	if(r==N){
		ans=max(ans, n);
		return;
	}
	if(!chk[r][c]){
		for(int i=0;i<4;++i){
			int a=dd[i][0], b=dd[i][1];
			int nr=r+dr[a], nc=c+dc[a];
			if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
			if(chk[nr][nc])	continue;
			int nnr=r+dr[b], nnc=c+dc[b];
			if(nnr<0 || nnr>=N || nnc<0 || nnc>=M)	continue;
			if(chk[nnr][nnc])	continue;
			chk[r][c]=chk[nr][nc]=chk[nnr][nnc]=1;
			sol(r, c+1, n+arr[r][c]+arr[r][c]+arr[nr][nc]+arr[nnr][nnc]);
			chk[r][c]=chk[nr][nc]=chk[nnr][nnc]=0;
		}
	}
	sol(r, c+1, n);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)	cin>>arr[i][j];
	sol(0, 0, 0);
	cout<<ans<<"\n";
	return 0;
}
