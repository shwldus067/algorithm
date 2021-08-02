#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N, d[50];
vector<int> adj[50];
bool cmp(int a, int b){
	return d[a]>d[b];
}
void dfs(int u){
	if(adj[u].size()==0)	return;
	for(int v:adj[u]){
		dfs(v);
	}
	sort(adj[u].begin(), adj[u].end(), cmp);
	int ret=0, cnt=1, size=adj[u].size();
	for(int i=0;i<size;++i){
		int tmp=d[adj[u][i]]+1+i;
		if(ret<tmp){
			ret=tmp;
		}
	}
	d[u]=ret;
}
int main(){
	int p;
	scanf("%d", &N);
	scanf("%d", &p);
	for(int i=1;i<N;++i){
		scanf("%d", &p);
		adj[p].push_back(i);
	}
	dfs(0);
	printf("%d\n", d[0]);
	return 0;
}
