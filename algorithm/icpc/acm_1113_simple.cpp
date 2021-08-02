#include<iostream>
using namespace std;
int N, M;
char arr[52][52];
bool chk[52][52];
int dr[4]={1, -1, 0, 0}, dc[4]={0, 0, -1, 1};
void dfs(int pr, int pc){
	chk[pr][pc]=1;
	for(int i=0;i<4;++i){
		int r=pr+dr[i], c=pc+dc[i];
		if(r<0 || r>N+1 || c<0 || c>M+1 || chk[r][c])	continue;
		dfs(r, c);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	char m=0;
	int ans=0;
	for(int i=1;i<=N;++i)for(int j=1;j<=M;++j){
			cin>>arr[i][j];
			arr[i][j]-='0';
			m=max(m, arr[i][j]);
		}
	for(char k=2;k<=m;++k){
		for(int i=0;i<N+2;++i)for(int j=0;j<M+2;++j){
				if(arr[i][j]>=k)	chk[i][j]=1;
				else	chk[i][j]=0;
			}
		dfs(0, 0);
		for(int i=1;i<=N;++i)for(int j=1;j<=M;++j)
			if(!chk[i][j])	ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
