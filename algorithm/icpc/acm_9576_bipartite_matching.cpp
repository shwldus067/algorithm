#include<iostream>
using namespace std;
int T, N, M, cnt=0;
pair<int, int> adj[1001];
int b[1001];
int visit[1001];
bool dfs(int v){
	if(visit[v]==cnt)	return false;
	visit[v]=cnt;
	for(int i=adj[v].first;i<=adj[v].second;i++){
		if(b[i]==-1 || dfs(b[i])){
			b[i]=v;
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>M;
		fill(adj, adj+N+1, make_pair(0, 0));
		for(int i=1;i<=M;i++){
			int p, q;
			cin>>p>>q;
			adj[i]={p, q};
		}
		fill(b, b+1001, -1);
		int s=0;
		for(int i=1;i<=M;i++){
			cnt++;
			if(dfs(i))	s++;
		}
		cout<<s<<"\n";
	}
	return 0;
}
