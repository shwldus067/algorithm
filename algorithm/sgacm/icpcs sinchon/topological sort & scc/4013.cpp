#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#define MAXN 500050

using namespace std;

vector<vector<int>> SCC;
vector<int> adj[MAXN];
vector<int> adjd[MAXN];
vector<int> res;
int val[MAXN];
int sccnum[MAXN];
int dfsnum[MAXN];
int sval[MAXN];
int dp[MAXN];
int S, P;
int ord = 0;
int idx = 0;
stack<int> st;
int dfs(int cur){
	int ret = dfsnum[cur] = ord++;
	st.push(cur);
	for(int next : adj[cur]){
		if(dfsnum[next] == -1) ret = min(ret, dfs(next));
		if(sccnum[next] == -1) ret = min(ret, dfsnum[next]);
	}
	if(ret == dfsnum[cur]){
		vector<int> C;
		int tmp;
		do{
			tmp = st.top();
			st.pop();
			C.push_back(tmp);
			sccnum[tmp] = idx;
		}while(tmp != cur);
		SCC.push_back(C);
		idx++;
	}
	return ret;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
	for(int i = 1; i <= N; i++){
		scanf("%d", val + i);
	}
	scanf("%d %d", &S, &P);
	for(int i = 0, t; i < P; i++){
		scanf("%d", &t);
		res.push_back(t);
	}
	fill(dfsnum, dfsnum + N + 1, -1);
	fill(sccnum, sccnum + N + 1, -1);
	dfs(S);
	for(int i = 1; i <= N; i++){
		if(sccnum[i] == -1) continue;
		for(int next : adj[i]){
			if(sccnum[next] == -1) continue;
			if(sccnum[i] != sccnum[next]) adjd[sccnum[i]].push_back(sccnum[next]);
		}
	}

	for(int i = 1; i <= N; i++){
		if(sccnum[i] == -1) continue;
		sval[sccnum[i]] += val[i];
	}
	int ans = 0;
	for(int i = idx - 1; i >= 0; i--){
		dp[i] += sval[i];
		for(int next : adjd[i]){
			dp[next] = max(dp[next], dp[i]);
		}
	}
	for(int end : res){
		if(sccnum[end] == -1) continue;
		ans = max(ans, dp[sccnum[end]]);
	}
	printf("%d\n", ans);
	return 0;
}