#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int R, C;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, -1, 0, 1};
char arr[100][101];
void sol(int r, int t){
	int col=C-1, c=-1;
	if(t==1)	col=0;
	for(;col>=0 && col<C;col+=t){
		if(arr[r][col]=='x'){
			c=col;
			arr[r][c]='.';
			break;
		}
	}
	if(c==-1)	return;
	int maxrow[100], maxr;
	int chk[100][100]={0, }, cnt=1;
	queue<pii> Q;
	for(int i=0;i<4;++i){
		int nr=r+dr[i], nc=c+dc[i];
		if(nr<0 || nr>=R || nc<0 || nc>=C)	continue;
		if(arr[nr][nc]!='x' || chk[nr][nc])	continue;
		for(int k=0;k<C;++k)	maxrow[k]=-1;
		maxr=nr;
		Q.push({nr, nc});
		chk[nr][nc]=cnt;
		maxrow[nc]=nr;
		while(Q.size()){
			int rr=Q.front().first, cc=Q.front().second;
			Q.pop();
			for(int j=0;j<4;++j){
				int nrr=rr+dr[j], ncc=cc+dc[j];
				if(nrr<0 || nrr>=R || ncc<0 || ncc>=C)	continue;
				if(arr[nrr][ncc]!='x' || chk[nrr][ncc])	continue;
				chk[nrr][ncc]=cnt;
				maxrow[ncc]=max(maxrow[ncc], nrr);
				maxr=max(maxr, nrr);
				Q.push({nrr, ncc});
			}
		}
		if(maxr!=R-1)	break;
		++cnt;
	}
	if(maxr==R-1)	return;
	int minr=100;
	for(int k=0;k<C;++k){
		if(maxrow[k]==-1)	continue;
		for(int i=maxrow[k]+1;i<=R;++i){
			if(minr<=i-maxrow[k]-1)	break;
			if(i==R || arr[i][k]=='x'){
				minr=min(minr, i-maxrow[k]-1);
				break;
			}
		}
	}
	for(int k=0;k<C;++k){
		for(int i=R-1;i>=0;--i){
			if(chk[i][k]==cnt){
				arr[i][k]='.';
				arr[i+minr][k]='x';
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, r, t=1;
	cin>>R>>C;
	for(int i=0;i<R;++i)	cin>>arr[i];
	cin>>N;
	while(N--){
		cin>>r;
		r=R-r;
		sol(r, t);
		t=t==1?-1:1;
	}
	for(int i=0;i<R;++i)	cout<<arr[i]<<"\n";
	return 0;
}
