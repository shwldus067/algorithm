#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, k;
vector<pair<int, int> > adj[1001];
priority_queue<int> d[1001];
struct dij{
	int v, c;
	dij(){}
	dij(int v, int c):v(v), c(c){}
};
bool operator<(dij d1, dij d2){
	return d1.c>d2.c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int a, b, c;
	while(m--){
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
	}
	d[1].push(0);
	priority_queue<dij> pq;
	pq.push(dij(1, 0));
	int v, nv, nc;
	while(pq.size()){
		v=pq.top().v, c=pq.top().c;
		pq.pop();
		if(d[v].top()<c)	continue;
		for(int i=0;i<adj[v].size();i++){
			nv=adj[v][i].first;
			nc=adj[v][i].second+c;
			if(d[nv].size()<k){
				d[nv].push(nc);
				pq.push(dij(nv, nc));
			}
			else if(d[nv].top()>nc){
				d[nv].pop();
				d[nv].push(nc);
				pq.push(dij(nv, nc));
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i].size()==k)	cout<<d[i].top()<<"\n";
		else	cout<<"-1\n";
	}
	return 0;
}
