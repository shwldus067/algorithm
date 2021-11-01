#include<iostream>
using namespace std;
typedef long long ll;
int N, arr[100][100];
ll dp[100][100];
ll dfs(int r, int c){
	if(r==N-1 && c==N-1)	return 1;
	ll &ret=dp[r][c];
	if(ret!=-1)	return ret;
	if(arr[r][c]==0)	return 0;
	ret=0;
	int nr=r, nc=c+arr[r][c];
	if(nc<N)	ret+=dfs(nr, nc);
	nr+=arr[r][c], nc=c;
	if(nr<N)	ret+=dfs(nr, nc);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>arr[i][j], dp[i][j]=-1;
	dfs(0, 0);
	cout<<dp[0][0]<<"\n";
	return 0;
}
