#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int inf=987654321;
int N, P, c[802][802], f[802][802], res=0, s=2, t=3;
vector<int> adj[802];
void bfs(){
	while(1){
		vector<int> prev(801, -1);
		queue<int> Q;
		Q.push(s);
		while(!Q.empty() && prev[t]==-1){
			int cur=Q.front();
			Q.pop();
			for(int v=0;v<adj[cur].size();v++){
				int next=adj[cur][v];
				if(prev[next]!=-1)	continue;
				if(c[cur][next]-f[cur][next]<=0)	continue;
				prev[next]=cur;
				Q.push(next);
				if(next==t)	break;
			}
		}
		if(prev[t]==-1)	break;
		int minv=inf;
		for(int x=t;x!=s;x=prev[x]){
			minv=min(minv, c[prev[x]][x]-f[prev[x]][x]);
		}
		for(int x=t;x!=s;x=prev[x]){
			f[prev[x]][x]+=minv;
			f[x][prev[x]]-=minv;
		}
		res+=minv;
	}
	return;
}
void add_edge(int u, int v, int n){
	adj[u].push_back(v);
	adj[v].push_back(u);
	c[u][v]=n;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>P;
	int u, v;
	for(int i=0;i<P;i++){
		cin>>u>>v;
		add_edge(2*u, 2*v-1, 1);
		add_edge(2*v, 2*u-1, 1);
	}
	add_edge(1, 2, inf);
	add_edge(3, 4, inf);
	for(int i=3;i<=N;i++){
		add_edge(2*i-1, 2*i, 1);
	}
	bfs();
	cout<<res<<"\n";
	return 0;
}
