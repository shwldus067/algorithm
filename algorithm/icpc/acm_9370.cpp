#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int T, n, m, t, s, g, h, a, b, d;
int sd[2001], dd[2001];
vector<pii> adj[2001];
void dijk(int start, int *dist){
	priority_queue<pii> pq;
	pq.push({0, start});
	while(pq.size()){
		int cur=pq.top().second, dis=-pq.top().first;
		pq.pop();
		if(dist[cur]!=-1)	continue;
		dist[cur]=dis;
		for(pii p:adj[cur]){
			if(dist[p.first]!=-1) continue;
			pq.push({-dis-p.second, p.first});
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool des[2001];
	cin>>T;
	while(T--){
		cin>>n>>m>>t>>s>>g>>h;
		for(int i=1;i<=n;++i){
			des[i]=0;
			sd[i]=dd[i]=-1;
			adj[i]=vector<pair<int, int> >();
		}
		for(int i=0;i<m;++i){
			cin>>a>>b>>d;
			adj[a].push_back({b, d});
			adj[b].push_back({a, d});
		}
		for(int i=0;i<t;++i){
			cin>>a;
			des[a]=1;
		}
		dijk(s, sd);
		int k=sd[g]<sd[h]?h:g;
		dijk(k, dd);
		for(int i=1;i<=n;++i){
			if(!des[i] || sd[i]==-1 || dd[i]==-1)	continue;
			if(sd[i]==sd[k]+dd[i])	cout<<i<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
