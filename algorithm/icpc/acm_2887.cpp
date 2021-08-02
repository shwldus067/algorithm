#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
pii x[100000], y[100000], z[100000];
vector<pii> adj[100000];
bool visit[100000];
inline int abs(int k){return k<0?-k:k;}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>x[i].first>>y[i].first>>z[i].first;
		x[i].second=y[i].second=z[i].second=i;
	}
	sort(x, x+N);
	sort(y, y+N);
	sort(z, z+N);
	for(int i=1;i<N;++i){
		int c=x[i].second, n=x[i-1].second;
		int m=abs(x[i].first-x[i-1].first);
		adj[c].push_back({n, m});
		adj[n].push_back({c, m});
		c=y[i].second, n=y[i-1].second;
		m=abs(y[i].first-y[i-1].first);
		adj[c].push_back({n, m});
		adj[n].push_back({c, m});
		c=z[i].second, n=z[i-1].second;
		m=abs(z[i].first-z[i-1].first);
		adj[c].push_back({n, m});
		adj[n].push_back({c, m});
	}
	priority_queue<pii> pq;
	for(pii &pi:adj[0]){
		pq.push({-pi.second, pi.first});
	}
	int cnt=1;
	long long ans=0;
	visit[0]=1;
	while(pq.size()){
		int cost=pq.top().first, cur=pq.top().second;
		pq.pop();
		if(visit[cur])	continue;
		visit[cur]=1;
		ans+=cost;
		for(pii &p:adj[cur]){
			if(visit[p.first])	continue;
			pq.push({-p.second, p.first});
		}
	}
	cout<<-ans<<"\n";
	return 0;
}
