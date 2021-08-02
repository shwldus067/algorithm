#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 32005

using namespace std;

vector<int> adj[MAXN];
vector<int> ans;
int N, M;
int indegree[MAXN];
bool visit[MAXN]; 

void dfs(int cur){ // topological sort w/ dfs
	visit[cur] = true;
	ans.push_back(cur);
	for(auto next : adj[cur]){
		indegree[next]--;
		if(indegree[next] == 0) dfs(next);
	}
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0, a, b; i < M; i++){
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++; // counts indegree for each node
	}
	
	for(int i = 1; i <= N; i++){
		if(indegree[i] == 0 && visit[i] == false) dfs(i);
	}

	for(auto e : ans) printf("%d ", e);
}