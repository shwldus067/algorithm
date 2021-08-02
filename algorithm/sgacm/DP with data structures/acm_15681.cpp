#include<iostream>
#include<vector>
using namespace std;
int dp[100001];
int dfs(int u, int p, const vector<vector<int> > &tree){
	for(int v=0;v<tree[u].size();v++){
		if(tree[u][v]==p)	continue;
		dp[u]+=dfs(tree[u][v], u, tree);
	}
	return ++dp[u];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, r, q;
	cin>>n>>r>>q;
	vector<vector<int> > tree(n+1);
	for(int i=0;i<n-1;i++){
		int u, v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(r, -1, tree);
	while(q--){
		int u;
		cin>>u;
		cout<<dp[u]<<"\n";
	}
	return 0;
}
