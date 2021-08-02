#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int inf=(1<<31)-1;
int N, P, s=1, t=2, res=0;
int c[401][401], f[401][401];
vector<vector<int> > adj(401);
void bfs(){
	while(1){
		vector<int> prev(401, -1);
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
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>P;
	int u, v;
	for(int i=0;i<P;i++){
		cin>>u>>v;
		c[u][v]=1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs();
	cout<<res<<"\n";
	return 0;
}
