#include<iostream>
#include<vector>
using namespace std;
int N, S, D, ans;
vector<int> adj[100001];
bool visit[100001];
int dfs(int u){
	visit[u]=true;
	int ret=0;
	for(int v:adj[u]){
		if(visit[v])	continue;
		int n=dfs(v);
		if(n>D)	ans+=2;
		if(n>ret)	ret=n;
	}
	return ret+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>S>>D;
	for(int i=1;i<N;++i){
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(S);
	cout<<ans<<"\n";
	return 0;
}
