#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define MAXN 10050

using namespace std;

vector<int> adj[MAXN];
vector<vector<int>> SCC;
stack<int> S;

int dfsnum[MAXN];
int sccnum[MAXN];
int idx = 0;
int top = -1;
int ord = 0;


int V, E;

void init(){
	for(int i = 0; i < MAXN; i++){
		dfsnum[i] = -1;
		sccnum[i] = -1;
	}
}

int dfs(int cur){
	S.push(cur);

	dfsnum[cur] = ord++;
	int res = dfsnum[cur];

	for(int next : adj[cur]){
		if(dfsnum[next] == -1) res = min(res, dfs(next));
		else if(sccnum[next] == -1) res = min(res, dfsnum[next]);
	}

	if(res == dfsnum[cur]){
		vector<int> C;
		int curV;
		do{
			curV = S.top();
			C.push_back(curV);
			sccnum[curV] = idx;
			S.pop();
		}while(curV != cur);
		sort(C.begin(), C.end());
		SCC.push_back(C);
		idx++;
	}
	return res;
}

void input(){
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
}

void output(){
	printf("%d\n", idx);
	for(auto& cv : SCC){
		for(int v : cv) printf("%d ", v);
		printf("-1\n");
	}
}

void solve(){
	for(int i = 1; i <= V; i++) if(dfsnum[i] == -1) dfs(i);
	sort(SCC.begin(), SCC.end());
}

int main(){
	init();
	input();
	solve();
	output();
}