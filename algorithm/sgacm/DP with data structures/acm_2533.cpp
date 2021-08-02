#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > vvi;
int N;
int dp[1000001][2];
void dfs(int u, int p, const vvi &tree){
	int t;
	for(int v=0;v<tree[u].size();v++){
		t=tree[u][v];
		if(p==t)	continue;
		dfs(t, u, tree);
		dp[u][0]+=dp[t][1]<dp[t][0] ? dp[t][1]:dp[t][0];
		dp[u][1]+=dp[t][0];
	}
	dp[u][0]++;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	vvi tree(N+1);
	int a, b;
	for(int i=1;i<N;i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0, tree);
	cout<<(dp[1][0]<dp[1][1] ? dp[1][0]:dp[1][1])<<"\n";
	return 0;
}
