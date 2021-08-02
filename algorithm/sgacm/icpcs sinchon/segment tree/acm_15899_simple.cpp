#include<iostream>
#include<vector>
using namespace std;
const int mod=1000000007;
int N, M, C, ans, color[200001], tree[200001];
bool visit[200001];
vector<int> adj[200001], q[200001];
void update(int i, int d){
	while(i<=C){
		tree[i]+=d;
		i+=i&-i;
	}
}
int query(int i){
	int ret=0;
	while(i>0){
		ret+=tree[i];
		i-=i&-i;
	}
	return ret;
}
void dfs(int v){
	visit[v]=true;
	for(int u:q[v])	update(u, 1);
	ans=(ans+query(C)-query(color[v]-1))%mod;
	for(int next:adj[v]){
		if(visit[next])	continue;
		dfs(next);
	}
	for(int u:q[v])	update(u, -1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>C;
	for(int i=0;i<N;++i){
		cin>>color[i];
	}
	for(int i=1;i<N;++i){
		int a, b;
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	while(M--){
		int a, b;
		cin>>a>>b;
		q[a-1].push_back(b);
	}
	dfs(0);
	cout<<ans<<"\n";
	return 0;
}
