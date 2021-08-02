#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, S, D, d[500];
vector<pii> adj[500];
vector<int> parent[500];
void dijkstra(){
	for(int i=0;i<N;++i)	d[i]=1e9, parent[i].clear();
	priority_queue<pii> pq;
	pq.push({0, S});
	d[S]=0;
	while(pq.size()){
		int cur=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		if(cost!=d[cur])	continue;
		for(pii &p:adj[cur]){
			int next=p.first;
			int c=p.second;
			if(d[next]>cost+c){
				d[next]=cost+c;
				pq.push({-d[next], next});
				parent[next].clear();
				parent[next].push_back(cur);
			}
			else if(d[next]==d[cur]+c){
				parent[next].push_back(cur);
			}
		}
	}
}
void deline(){
	queue<int> Q;
	Q.push(D);
	while(Q.size()){
		int cur=Q.front();
		Q.pop();
		for(int pa:parent[cur]){
			for(pii &p:adj[pa]){
				if(p.first==cur){
					if(p.second!=1e9){
						p.second=1e9;
						Q.push(pa);
					}
					break;
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1){
		cin>>N>>M;
		if(N==0 && M==0)	break;
		cin>>S>>D;
		while(M--){
			int u, v, p;
			cin>>u>>v>>p;
			adj[u].push_back({v, p});
		}
		dijkstra();
		deline();
		dijkstra();
		if(d[D]==1e9)	cout<<"-1\n";
		else	cout<<d[D]<<"\n";
		for(int i=0;i<N;++i)	adj[i].clear();
	}
	return 0;
}
