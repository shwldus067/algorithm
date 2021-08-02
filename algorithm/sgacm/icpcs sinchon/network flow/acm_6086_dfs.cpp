#include<iostream>
#include<vector>
using namespace std;
const int inf=~(1<<31);
int N, res=0, s, t, last=1;
int c[53][53], f[53][53];
bool visit[53];
vector<int> adj[53];
int dfs(int a, int flow){
	if(visit[a])	return 0;
	visit[a]=true;
	if(a==t)	return flow;
	for(int b:adj[a]){
		int cur=c[a][b]-f[a][b];
		if(cur<=0)	continue;
		int res=dfs(b, min(flow, cur));
		if(res){
			f[a][b]+=res;
			f[b][a]-=res;
			return res;
		}
	}
	return 0;
}
int maxflow(){
	int res=0;
	while(1){
		fill(&visit[0], &visit[53], false);
		int flow=dfs(s, inf);
		if(!flow)	break;
		res+=flow;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	char x, y;
	int z, u, v;
	s=0, t=25;
	for(int i=0;i<N;++i){
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
	cout<<maxflow()<<"\n";
	return 0;
}
