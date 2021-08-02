#include<iostream>
using namespace std;
int N, M, H, ans=4;
int A[10][30];
int find(int n, int h){
	if(h==H)	return n;
	return find(n+A[n][h], h+1);
}
void sol(int r, int c, int cnt){
	if(cnt>3)	return;
	if(cnt>=ans)	return;
	int f=1;
	for(int i=0;i<N;++i){
		if(i!=find(i, 0)){
			f=0;
			break;
		}
	}
	if(f){
		if(ans>cnt)	ans=cnt;
		return;
	}
	for(int j=c;j<H;++j){
		if(!A[r][j] && !A[r+1][j]){
			A[r][j]=1;A[r+1][j]=-1;
			sol(r, j+1, cnt+1);
			A[r][j]=A[r+1][j]=0;
		}
	}
	for(int i=r+1;i<N-1;++i){
		for(int j=0;j<H;++j){
			if(!A[i][j] && !A[i+1][j]){
				A[i][j]=1;A[i+1][j]=-1;
				sol(i, c+1, cnt+1);
				A[i][j]=A[i+1][j]=0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>H;
	while(M--){
		int a, b;
		cin>>a>>b;
		--a;
		A[b-1][a]=1;A[b][a]=-1;
	}
	sol(0, 0, 0);
	if(ans==4)	cout<<"-1\n";
	else cout<<ans<<"\n";
	return 0;
}
