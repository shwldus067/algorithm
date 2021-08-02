#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1000000007;
int N, M, C, l[200001], r[200001], cnt, ans;
int tree[200001];
vector<int> adj[200001];
struct Color{
	int x, v, c;
	bool operator <(const Color& a){
		if(c==a.c)	return x<a.x;
		return c<a.c;
	}
}color[4000001];
void dfs(int x, int p){
	l[x]=++cnt;
	for(int next:adj[x]){
		if(next==p)	continue;
		dfs(next, x);
	}
	r[x]=cnt;
}
void update(int i){
	while(i<=N){
		++tree[i];
		i+=i&-i;
	}
}
int query(int i){
	int ret=0;
	while(i>0){
		ret+=tree[i];
		i-=i&-i;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>C;
	for(int i=0;i<N;++i){
		cin>>color[i].c;
		color[i].x=1;
		color[i].v=i;
	}
	for(int i=1;i<N;++i){
		int a, b;
		cin>>a>>b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, 0);
	M+=N;
	for(int i=N;i<M;++i){
		cin>>color[i].v>>color[i].c;
		color[i].v--;
		color[i].x=2;
	}
	sort(color, color+M);
	for(int i=0;i<M;++i){
		if(color[i].x==1){
			update(l[color[i].v]);
		}
		else{
			ans=(ans+query(r[color[i].v])-query(l[color[i].v]-1))%mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
