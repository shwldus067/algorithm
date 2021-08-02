#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, K, b[1001], lv[1001], used[1001];
vector<int> adj[1001];
void bfs(int t){
	queue<int> Q;
	for(int i=1;i<=N;++i)
		if(used[i]==t)	lv[i]=0, Q.push(i);
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
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
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
		bfs(0);
		flow=0;
		for(int i=1;i<=N;++i)
			if(used[i]==0 && dfs(i))	flow++, used[i]=1;
		ans+=flow;
	}while(flow);
	if(K==0){
		cout<<ans<<"\n";
		return 0;
	}
	do{
		bfs(1);
		flow=0;
		for(int i=1;i<=N;++i)
			if(used[i]==1 && dfs(i)){
				flow++;
				used[i]=2;
				if(!--K)	break;
			}
		ans+=flow;
	}while(flow && K);
	cout<<ans<<"\n";
	return 0;
} 
