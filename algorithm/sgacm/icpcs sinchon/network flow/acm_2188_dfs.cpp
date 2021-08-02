#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> adj[402];
bool visit[402];
int dfs(int a){
	if(a==401)	return true;
	for(int i=0;i<adj[a].size();i++){
		int b=adj[a][i];
		if(visit[b])	continue;
		visit[b]=true;
		if(dfs(b)){
			adj[a][i]=adj[a].back();
			adj[a].pop_back();
			adj[b].push_back(a);
			return true;
		}
	}
	return false;
}
int maxflow(){
	int res=0;
	while(1){
		for(int i=0;i<402;++i)	visit[i]=false;
		if(!dfs(0))	break;
		res++;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		int t;
		cin>>t;
		while(t--){
			int x;
			cin>>x;
			adj[i].push_back(x+200);
		}
	}
	for(int i=1;i<=N;++i){
		adj[0].push_back(i);
	}
	for(int i=1;i<=M;++i){
		adj[i+200].push_back(401);
	}
	cout<<maxflow()<<"\n";
	return 0;
}
