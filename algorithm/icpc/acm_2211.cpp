#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, A, B, C, cnt=0;
	pii dis[1001];
	vector<pii> adj[1001];
	pii tree[1000];
	cin>>N>>M;
	while(M--){
		cin>>A>>B>>C;
		adj[A].push_back({B, C});
		adj[B].push_back({A, C});
	}
	for(int i=1;i<=N;++i)	dis[i]={1e6, 0};
	priority_queue<pii> pq;
	pq.push({0, 1});
	dis[1].first=0;
	while(pq.size()){
		pii cur=pq.top();
		pq.pop();
		if(dis[cur.second].first<-cur.first)	continue;
		tree[cnt++]={cur.second, dis[cur.second].second};
		for(pii p:adj[cur.second]){
			if(dis[p.first].first>-cur.first+p.second){
				dis[p.first].first=-cur.first+p.second;
				dis[p.first].second=cur.second;
				pq.push({-dis[p.first].first, p.first});
			}
		}
	}
	cout<<cnt-1<<"\n";
	for(int i=1;i<cnt;++i)	cout<<tree[i].first<<' '<<tree[i].second<<"\n";
	return 0;
}
