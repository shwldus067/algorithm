#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, b[101], lv[101];
vector<int> adj[101];
bool used[101];
void bfs(){
	queue<int> Q;
	for(int i=1;i<=N;++i){
		if(!used[i])	lv[i]=0, Q.push(i);
		else	lv[i]=-1;
	}
	while(Q.size()){
		int cur=Q.front();
		Q.pop();
		for(int n:adj[cur]){
			if(b[n] && lv[b[n]]==-1)
				lv[b[n]]=lv[cur]+1, Q.push(b[n]);
		}
	}
}
bool dfs(int v){
	for(int n:adj[v]){
		if(!b[n] || lv[b[n]]==lv[v]+1 && dfs(b[n])){
			b[n]=v;
			used[v]=true;
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	int ans=0, flow;
	do{
		bfs();
		flow=0;
		for(int i=1;i<=N;++i)
			if(!used[i])	flow+=dfs(i);
		ans+=flow;
	}while(flow);
	cout<<ans<<"\n";
	return 0;
}
