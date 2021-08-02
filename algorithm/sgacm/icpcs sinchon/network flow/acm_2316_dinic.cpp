#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, P, u, v, res, lv[801], work[801];
vector<int> adj[801];
int c[801][801], f[801][801];
bool bfs(){
	fill(lv, lv+801, -1);
	lv[401]=0;
	queue<int> Q;
	Q.push(401);
	while(Q.size()){
		int cur=Q.front();
		Q.pop();
		for(int next:adj[cur]){
			if(lv[next]==-1 && c[cur][next]>f[cur][next]){
				lv[next]=lv[cur]+1;
				Q.push(next);
			}
		}
	}
	return lv[2]!=-1;
}
int dfs(int x){
	if(x==2)	return true;
	for(int &i=work[x];i<adj[x].size();i++){
		int next=adj[x][i];
		if(lv[next]==lv[x]+1 && c[x][next]>f[x][next]){
			if(dfs(next)){
				f[x][next]++;
				f[next][x]--;
				return true;
			}
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>P;
	for(int i=3;i<=N;i++){
		adj[i].push_back(400+i);
		adj[400+i].push_back(i);
		c[i][i+400]=1;
	}
	for(int i=0;i<P;i++){
		cin>>u>>v;
		adj[u+400].push_back(v);
		adj[v].push_back(u+400);
		adj[v+400].push_back(u);
		adj[u].push_back(v+400);
		c[u+400][v]=c[v+400][u]=1;
	}
	while(bfs()){
		fill(work, work+801, 0);
		while(dfs(401)){
			res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}
