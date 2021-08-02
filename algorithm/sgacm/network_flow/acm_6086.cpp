#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int inf=(1<<31)-1;
int N, res=0, s, t, last=1;
int c[53][53], f[53][53];
vector<int> adj[53];
void bfs(){
	while(1){
		vector<int> prev(53, -1);
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
	cin>>N;
	char x, y;
	int z, u, v;
	s=0, t=25;
	for(int i=0;i<N;i++){
		cin>>x>>y>>z;
		if(x<='Z')	u=x-'A';
		else	u=x-'a'+26;
		if(y<='Z')	v=y-'A';
		else	v=y-'a'+26;
		c[u][v]+=z;
		c[v][u]+=z;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs();
	cout<<res<<"\n";
	return 0;
}
