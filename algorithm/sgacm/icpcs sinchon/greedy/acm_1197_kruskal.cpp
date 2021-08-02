#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int V, E, parent[10000], r[10000];
struct edge{
	int x, y, d;
	edge(int x, int y, int d):x(x), y(y), d(d){}
	bool operator<(edge &e){
		return d<e.d;
	}
};
int find(int u){
	while(u!=parent[u])	u=parent[u];
	return u;
}
void merge(int u, int v){
	u=find(u), v=find(v);
	if(u==v)	return;
	if(r[u]>r[v])	parent[v]=u;
	else{
		parent[u]=v;
		if(r[u]==r[v])	++r[v];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>V>>E;
	vector<edge> adj;
	while(E--){
		int a, b, c;
		cin>>a>>b>>c;
		adj.push_back(edge(a-1, b-1, c));
	}
	sort(adj.begin(), adj.end());
	for(int i=0;i<V;++i)	parent[i]=i;
	int ans=0, size=adj.size();
	for(int i=0;i<size;++i){
		int u=adj[i].x, v=adj[i].y;
		if(find(u)!=find(v)){
			ans+=adj[i].d;
			merge(u, v);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
