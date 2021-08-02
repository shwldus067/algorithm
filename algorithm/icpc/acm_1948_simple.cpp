#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int N, M, mx[2][10001], ind[2][10001], st, ed, ans;
vector<pii> adj[2][10001];
queue<int> q;
void bfs(int f){
	auto& ad = adj[f];
	auto& m = mx[f];
	auto& in = ind[f];
	q.emplace(f ? ed : st);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=ad[u].size()-1;i>=0;i--){
			int v=ad[u][i].first, w=ad[u][i].second;
			m[v] = max(m[v], m[u] + w);
			if (f == 0 && (m[u] + w + mx[1][v] == mx[1][st])) ++ans;
			if (--in[v]==0) q.push(v);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int u, v, w;
		cin>>u>>v>>w;
		adj[0][u].push_back({v, w});
		adj[1][v].push_back({u, w});
		ind[0][v]++;
		ind[1][u]++;
	}
	cin>>st>>ed;
	bfs(1);
	bfs(0);
	cout<<mx[1][st]<<"\n"<<ans<<"\n";
	return 0;
}
