#include<iostream>
#include<algorithm>
using namespace std;
struct str{
	int u, v, w;
	bool operator<(const str &a)const{
		return w<a.w;
	}
}adj[100000];
int parent[1001];
int find(int u){
	int &ret=u;
	while(ret!=parent[ret])	ret=parent[ret];
	return ret;
}
void merge(int u, int v){
	if(u<v)	parent[v]=u;
	else	parent[u]=v;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, u, v, w, pu, pv, ans=0;
	cin>>N>>M>>K;
	for(int i=1;i<=N;++i)	parent[i]=i;
	while(K--){
		cin>>u;
		parent[u]=0;
	}
	for(int i=0;i<M;++i){
		cin>>u>>v>>w;
		adj[i]={u, v, w};
	}
	sort(adj, adj+M);
	for(int i=0;i<M;++i){
		if((pu=find(adj[i].u))!=(pv=find(adj[i].v))){
			merge(pu, pv);
			ans+=adj[i].w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
