#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF=987654321;
vector<pair<int, int> > dis[801];

void dijkstra(int s, int N, int* dij){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
	int v, vd, w, u, ud;
	dij[s]=0;
	PQ.push({0, s});
	while(!PQ.empty()){
		v=PQ.top().second;
		vd=PQ.top().first;
		PQ.pop();
		if(dij[v]<vd)	continue;
		if(dij[v]!=INF){
			for(w=0;w<dis[v].size();w++){
				u=dis[v][w].first;
				ud=dij[v]+dis[v][w].second;
				if(ud<dij[u]){
					dij[u]=ud;
					PQ.push({ud, u});
				}
			}
		}
	}
}

int main(){
	int N, E, a, b, c, res;
	cin>>N>>E;
	for(int e=0;e<E;e++){
		cin>>a>>b>>c;
		dis[a].push_back({b, c});
		dis[b].push_back({a, c});
	}
	cin>>a>>b;
	int dij_1[N+1];
	int dij_a[N+1];
	int dij_b[N+1];
	fill(&dij_1[0], &dij_1[N+1], INF);
	fill(&dij_a[0], &dij_a[N+1], INF);
	fill(&dij_b[0], &dij_b[N+1], INF);
	dijkstra(1, N, dij_1);
	dijkstra(a, N, dij_a);
	dijkstra(b, N, dij_b);
	res=min(dij_1[a]+dij_a[b]+dij_b[N], dij_1[b]+dij_b[a]+dij_a[N]);
	if(res>=INF || res<0){
		cout<<-1<<"\n";
	}
	else{
		cout<<res<<"\n";
	}
	return 0;
}
