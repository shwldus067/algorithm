#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int N, H, ans, root;
vector<vector<pii> > adj;
int dfs(int cur){
	int ret=0;
	for(pii &nxt:adj[cur]){
		int w=dfs(nxt.first)+nxt.second;
		if(w>H){
			ans+=w-H;
			w=H;
		}
		ret=max(ret, w);
	}
	return ret;
}
int main(){
	scanf("%d %d", &N, &H);
	adj.resize(N+1);
	for(int i=1;i<=N;++i){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a==0)	root=i;
		adj[a].push_back({i, b});
	}
	dfs(root);
	printf("%d\n", ans);
	return 0;
}
