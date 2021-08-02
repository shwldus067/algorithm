#include<iostream>
#include<vector>
using namespace std;
int N, M, b[101];
vector<int> adj[101];
int visit[101], cnt;
bool dfs(int v){
	visit[v]=cnt;
	for(int n:adj[v]){
		if(b[n]==0){
			b[n]=v;
			return true;
		}
	}
	for(int n:adj[v]){
		if(visit[b[n]]!=cnt && dfs(b[n])){
			b[n]=v;
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
	int ans=0;
	for(int i=1;i<=N;++i){
		cnt++;
		if(dfs(i))	ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
