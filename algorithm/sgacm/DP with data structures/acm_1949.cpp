#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > vvi;
int N;
int num[10001], dp[10001][2];
void dfs(int u, int p, const vvi &tree){
	int n;
	for(int v=0;v<tree[u].size();v++){
		n=tree[u][v];
		if(n==p)	continue;
		dfs(n, u, tree);
		dp[u][0]+=max(dp[n][0], dp[n][1]);
		dp[u][1]+=dp[n][0];
	}
	dp[u][1]+=num[u];
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	vvi tree(N+1);
	for(int i=1;i<=N;i++)	cin>>num[i];
	for(int i=0;i<N-1;i++){
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0, tree);
	cout<<max(dp[1][0], dp[1][1])<<"\n";
	return 0;
}
