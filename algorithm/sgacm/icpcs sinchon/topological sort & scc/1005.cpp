#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 1050
using namespace std;

vector<int> adj[MAXN];
int time[MAXN];
int dp[MAXN];

void init(){ // initialization
	for(int i = 0; i < MAXN; i++){
		adj[i].clear();
		dp[i] = -1;
		time[i] = 0;
	}
}

int dfs(int cur){
	if(dp[cur] != -1) return dp[cur];
	int ret = 0;
	for(int next : adj[cur]){
		ret = max(ret, dfs(next));
	}
	return dp[cur] = ret + time[cur]; // memoization
}

int main(){
	int T;
	int N, M, W;
	scanf("%d", &T);
	while(T--){
		init();
		scanf("%d %d", &N, &M);
		
		for(int i = 1; i <= N; i++){
			scanf("%d", time + i);
		}

		for(int i = 0, u, v; i < M; i++){
			scanf("%d %d", &u, &v);
			adj[v].push_back(u); // transpose graph of the given graph
		}

		scanf("%d", &W);
		dfs(W); // dp w/ memoization
		printf("%d\n", dp[W]);
	}
}