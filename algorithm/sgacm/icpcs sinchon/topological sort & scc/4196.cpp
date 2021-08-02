#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#define MAXN 100050
using namespace std;

vector<vector<int>> SCC;
vector<int> adj[MAXN];
stack<int> S;

int dfsnum[MAXN];
int sccnum[MAXN];
int indeg[MAXN];
int ord = 0, idx = 0;

int N, M;

int dfs(int cur){
	int res = dfsnum[cur] = ord++;
	S.push(cur);
	for(int next : adj[cur]){
		if(dfsnum[next] == -1) res = min(res, dfs(next));
		else if(sccnum[next] == -1) res = min(res, dfsnum[next]);
	}
	if(res == dfsnum[cur]){
		int curV;
		vector<int> C;
		do{
			curV = S.top();
			S.pop();
			C.push_back(curV);
			sccnum[curV] = idx;
		}while(curV != cur);
		SCC.push_back(C);
		idx++;
	}
	return res;
}

void init(){
	for(int i = 0; i < MAXN; i++){
		adj[i] = vector<int>();
	}
	SCC = vector<vector<int>>();
	fill(dfsnum, dfsnum + MAXN, -1);
	fill(sccnum, sccnum + MAXN, -1);
	fill(indeg, indeg + MAXN, 0);
	ord = idx = 0;
}

void input(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		init();
		input();

		for(int i = 0; i < N; i++){
			if(dfsnum[i] == -1) dfs(i);
		}

		for(int i = 0; i < N; i++){
			for(int j : adj[i]){
				if(sccnum[i] != sccnum[j]) indeg[sccnum[j]]++;
			}
		}

		int ans = 0;
		for(int i = 0; i < idx; i++) if(indeg[i] == 0) ans++;
		printf("%d\n", ans);
	}
}