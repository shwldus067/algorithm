#include<iostream>
using namespace std;
int N, M, r, c, d, A[50][50], ans;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	cin>>r>>c>>d;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)	cin>>A[i][j];
	while(1){
		if(!A[r][c])	A[r][c]=2, ans++;
		int i=5, nr, nc;
		while(--i){
			d=d ? d-1:3;
			nr=r+dr[d], nc=c+dc[d];
			if(!A[nr][nc]){
				r=nr, c=nc;break;
			}
		}
		if(!i){
			nr=r-dr[d], nc=c-dc[d];
			if(A[nr][nc]==1)	break;
			r=nr, c=nc;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
