#include<iostream>
#include<vector>
using namespace std;
int n, point, res;
bool visit[10001];
vector<pair<int, int> > adj[10001];
void dfs(int v, int l){
	if(visit[v])	return;
	visit[v]=true;
	if(res<l){
		res=l;
		point=v;
	}
	for(int i=adj[v].size()-1;i>=0;--i){
		dfs(adj[v][i].first, l+adj[v][i].second);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int a, b, c;
	for(int i=1;i<n;++i){
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dfs(1, 0);
	fill(visit, visit+n+1, false);
	dfs(point, 0);
	cout<<res<<"\n";
	return 0;
}
