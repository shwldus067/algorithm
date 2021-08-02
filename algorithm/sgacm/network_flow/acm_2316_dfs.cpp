#include<iostream>
#include<vector>
using namespace std;
int N, P, u, v, res;
vector<int> adj[801];
bool visit[801];
bool dfs(int x){
	if(x==2)	return true;
	for(int i=0;i<adj[x].size();i++){
		int next=adj[x][i];
		if(!visit[next]){
			visit[next]=true;
			if(dfs(next)){
				visit[next]=false;
				adj[x][i]=adj[x].back();
				adj[x].pop_back();
				adj[next].push_back(x);
				return true;
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>P;
	for(int i=1;i<=N;i++){
		adj[i].push_back(400+i);
	}
	for(int i=0;i<P;i++){
		cin>>u>>v;
		adj[u+400].push_back(v);
		adj[v+400].push_back(u);
	}
	for(res=0;dfs(401);res++){
		for(int i=1;i<=N;i++){
			visit[i]=visit[400+i]=false;
		}
	}
	cout<<res<<"\n";
	return 0;
}
