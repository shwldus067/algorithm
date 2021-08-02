#include<iostream>
#include<vector>
using namespace std;
int N, S, D, ans;
vector<int> adj[100001];
bool visit[100001];
int dfs(int v){
	visit[v]=true;
	int ret=0, t=0, f=0;
	for(int i=adj[v].size()-1;i>=0;--i){
		int next=adj[v][i];
		if(visit[next])	continue;
		t=dfs(next);
		if(t>=D)	ans+=2;
		if(ret<t)	ret=t;
		f=1;
	}
	if(f==0)	return 0;
	return ret+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>S>>D;
	if(D==0){
		cout<<N*2-2<<"\n";
		return 0;
	}
	int a, b;
	for(int i=0;i<N-1;++i){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(S);
	cout<<ans<<"\n";
	return 0;
}
