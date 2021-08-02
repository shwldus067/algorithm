#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> plp;
ll d[2501][2501];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, p[2501], a, b, c;
	cin>>N>>M;
	vector<vector<pii> > adj(N+1, vector<pii>());
	for(int i=1;i<=N;++i)	cin>>p[i];
	while(M--){
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	for(int i=1;i<=N;++i)for(int j=0;j<2501;++j)	d[i][j]=-1;
	priority_queue<plp> pq;
	pq.push({0, {1, p[1]}});
	while(pq.size()){
		ll cs=-pq.top().first;
		int cur=pq.top().second.first, pr=pq.top().second.second;
		pq.pop();
		if(cur==N){
			cout<<cs<<"\n";
			break;
		}
		if(d[cur][pr]!=-1)	continue;
		d[cur][pr]=cs;
		for(pii &nxt:adj[cur]){
			int npr=min(pr, p[nxt.first]);
			if(d[nxt.first][npr]!=-1)	continue;
			pq.push({-(cs+1ll*nxt.second*pr), {nxt.first, npr}});
		}
	}
	return 0;
}
