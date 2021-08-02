#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, b[1001], lv[1001], used[1001];
vector<int> adj[1001];
void bfs(){
	queue<int> Q;
	for(int i=1;i<=N;++i)
		if(used[i]<2)	lv[i]=0, Q.push(i);
		else	lv[i]=-1;
	while(Q.size()){
		int cur=Q.front();
		Q.pop();
		for(int next:adj[cur]){
			if(b[next] && lv[b[next]]==-1)
				lv[b[next]]=lv[cur]+1, Q.push(b[next]);
		}
	}
}
bool dfs(int v){
	for(int u:adj[v]){
		if(!b[u] || lv[b[u]]==lv[v]+1 && dfs(b[u])){
			b[u]=v;
			used[v]++;
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
	for(int i=1;i<=N;++i){
		int n;
		cin>>n;
		while(n--){
			int w;
			cin>>w;
			adj[i].push_back(w);
		}
	}
	int ans=0, flow;
	do{
		bfs();
		flow=0;
		for(int i=1;i<=N;++i)
			if(used[i]<2)	flow+=dfs(i);
		ans+=flow;
	}while(flow);
	cout<<ans<<"\n";
	return 0;
} 
