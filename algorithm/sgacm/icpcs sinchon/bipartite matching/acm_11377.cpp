#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, K, b[1001], visit[1001], used[1001], cnt;
vector<int> adj[1001];
bool dfs(int v){
	visit[v]=cnt;
	for(int n:adj[v]){
		if(b[n]==0 || visit[b[n]]!=cnt && dfs(b[n])){
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
	int ans=0, k=0;
	for(int i=1;i<=N;++i){
		cnt++;
		if(used[i]==0 && dfs(i)){
			used[i]=1;
			ans++;
		}
	}
	for(int i=1;i<=N;++i){
		cnt++;
		if(used[i]==1 && k<K && dfs(i)){
			ans++;
			k++;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
