#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, M, p[2501];
vector<pii> adj[2501];
ll d[2501], ans=1e18;
pair<ll, ll> d2[2501];
void dik1(){
	for(int i=0;i<2501;++i)	d[i]=1e18;
	priority_queue<pair<ll, int> > pq;
	pq.push({0, N});
	d[N]=0;
	while(pq.size()){
		ll dis=-pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		for(pii nxt:adj[cur]){
			ll ndis=dis+nxt.second;
			if(d[nxt.first]>ndis){
				d[nxt.first]=ndis;
				pq.push({-ndis, nxt.first});
			}
		}
	}
}
void dik2(){
	for(int i=1;i<=N;++i)	d2[i]={1e18, p[i]};
	priority_queue<pair<ll, pair<int, int> > > pq;
	pq.push({0, {1, p[1]}});
	d2[1]={0, p[1]};
	while(pq.size()){
		ll dis=-pq.top().first;
		int cur=pq.top().second.first, cost=pq.top().second.second;
		pq.pop();
		ans=min(ans, dis+d[cur]*cost);
		for(pii nxt:adj[cur]){
			ll ndis=dis+(ll)nxt.second*cost;
			int n=nxt.first, ncost=min(p[n], cost);
			if(d2[n].first+d2[n].second*d[n]>ndis+ncost*d[n]){
				d2[n]={ndis, ncost}; 
				pq.push({-ndis, {n, ncost}});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;++i)	cin>>p[i];
	int a, b, c;
	while(M--){
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dik1();
	dik2();
	cout<<ans<<"\n";
	return 0;
}
