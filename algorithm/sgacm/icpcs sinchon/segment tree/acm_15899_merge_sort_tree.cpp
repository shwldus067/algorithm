#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1000000007;
int N, M, C, color[200001], arr[200001], cnt;
vector<int> seg[(1<<19)+1];
bool visit[200001];
vector<int> adj[200001];
pair<int, int> sub[200001];
int dfs(int v){
	visit[v]=true;
	int child=0;
	for(int next:adj[v]){
		if(visit[next])	continue;
		child+=dfs(next);
	}
	arr[cnt]=color[v];
	sub[v]={cnt-child, cnt};
	++cnt;
	return 1+child;
}
void init(int x, int s, int e){
	if(s==e){
		seg[x].push_back(arr[s]);
		return;
	}
	int mid=(s+e)/2;
	init(x*2, s, mid), init(x*2+1, mid+1, e);
	auto &l=seg[x*2], &r=seg[x*2+1];
	merge(l.begin(), l.end(), r.begin(), r.end(), back_inserter(seg[x]));
}
int query(int x, int s, int e, int l, int r, int v){
	if(r<s || e<l)	return 0;
	if(l<=s && e<=r)
		return upper_bound(seg[x].begin(), seg[x].end(), v)-seg[x].begin();
	int mid=(s+e)/2;
	return query(x*2, s, mid, l, r, v)+query(x*2+1, mid+1, e, l, r, v);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>C;
	for(int i=1;i<=N;++i)	cin>>color[i];
	for(int i=1;i<N;++i){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	init(1, 0, N-1);
	int ans=0;
	while(M--){
		int a, b;
		cin>>a>>b;
		ans=(ans+query(1, 0, N-1, sub[a].first, sub[a].second, b))%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
