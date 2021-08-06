#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int parent[30001], depth[30001];
vector<int>	adj[30001];
void bfs(){
	queue<int> Q;
	parent[1]=0;
	depth[1]=0;
	Q.push(1);
	int size=0, dd=1;
	while(size=Q.size()){
		while(size--){
			int cur=Q.front();
			Q.pop();
			for(int nxt:adj[cur]){
				if(nxt==parent[cur])	continue;
				parent[nxt]=cur;
				depth[nxt]=depth[cur]+1;
				Q.push(nxt);
			}
		}
		++dd;
	}
}
int lca(int u, int v){
	if(depth[u]<depth[v])	swap(u, v);
	while(depth[u]>depth[v])	u=parent[u];
	if(u==v)	return u;
	while(u!=v){
		u=parent[u];
		v=parent[v];
	}
	return u;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, a, b, arr[5000];
	cin>>N;
	for(int i=1;i<N;++i){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs();
	cin>>M;
	int ans=0;
	cin>>b;
	M--;
	while(M--){
		cin>>a;
		int p=lca(a, b);
		ans+=depth[a]+depth[b]-depth[p]*2;
		b=a;
	}
	cout<<ans<<"\n";
	return 0;
}
