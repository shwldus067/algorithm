#include<iostream>
#include<vector>
using namespace std;
int N, M, b[1001], cnt;
int visit[1001];
vector<int> adj[1001];
bool dfs(int v){
	visit[v]=cnt;
	for(int next:adj[v]){
		if(!b[next]){
			b[next]=v;
			return true;
		}
	}
	for(int next:adj[v]){
		if(visit[b[next]]!=cnt && dfs(b[next])){
			b[next]=v;
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
	int ans=0;
	for(int i=1;i<=N;++i){
		cnt++;
		if(dfs(i))	ans++;
		cnt++;
		if(dfs(i))	ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
