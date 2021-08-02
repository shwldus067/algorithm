#include<iostream>
using namespace std;
int N, M, r, c, d, A[50][50], ans;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
bool chk[50][50][2500];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	cin>>r>>c>>d;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)	cin>>A[i][j];
	while(1){
		if(!chk[r][c][0]){
			chk[r][c][0]=1;ans++;
		}
		chk[r][c][ans]=1;
		int find=0;
		for(int i=0;i<4;++i){
			d=d ? d-1:3;
			int nr=r+dr[d], nc=c+dc[d];
			if(A[nr][nc] || chk[nr][nc][0])	continue;
			r=nr, c=nc, find=1;
			break;
		}
		if(find)	continue;
		int br=r-dr[d], bc=c-dc[d];
		if(A[br][bc] || chk[br][bc][ans])	break;
		r=br, c=bc;
	}
	cout<<ans<<"\n";
}
