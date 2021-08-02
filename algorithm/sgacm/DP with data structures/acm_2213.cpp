#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<vector<int> > vvi;
int n;
int w[10001], dp[10001][2];
bool ch[10001];
vector<int> r;
void dfs(int u, int p, const vvi &tree){
	int t;
	for(int v=0;v<tree[u].size();v++){
		t=tree[u][v];
		if(t==p)	continue;
		dfs(t, u, tree);
		dp[u][0]+=dp[t][1];
		dp[u][1]+=dp[t][1]>dp[t][0] ? dp[t][1]:dp[t][0];
	}
	dp[u][0]+=w[u];
	return;
}
void trace(int u, int p, int s, const vvi &tree){
	int t;
	if(s==0){
		r.push_back(u);
		for(int v=0;v<tree[u].size();v++){
			t=tree[u][v];
			if(t==p)	continue;
			trace(t, u, 1, tree);
		}
	}
	else{
		for(int v=0;v<tree[u].size();v++){
			t=tree[u][v];
			if(t==p)	continue;
			if(dp[t][1]>=dp[t][0]){
				trace(t, u, 1, tree);
			}
			else{
				trace(t, u, 0, tree);
			}
		}
	}
}
int main(){
	scanf("%d", &n);
	vvi tree(n+1);
	for(int i=1;i<=n;i++)	scanf("%d", &w[i]);
	int a, b;
	for(int i=1;i<n;i++){
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0, tree);
	int m=dp[1][0]>dp[1][1] ? 0:1;
	printf("%d\n", dp[1][m]);
	trace(1, 0, m, tree);
	sort(r.begin(), r.end());
	for(int i=0;i<r.size();i++)	printf("%d ", r[i]);
	return 0;
}
