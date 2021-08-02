#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, S, D, d[500];
int arr[500][500];
struct cmp{
	bool operator()(pii a, pii b){
		return a.second>b.second;
	}
};
void dijkstra(){
	for(int i=0;i<N;++i)	d[i]=-1;
	priority_queue<pii, vector<pii>, cmp> pq;
	pq.push({S, 0});
	while(pq.size()){
		int cur=pq.top().first;
		int cost=pq.top().second;
		pq.pop();
		if(d[cur]!=-1)	continue;
		d[cur]=cost;
		for(int i=0;i<N;++i){
			if(arr[cur][i]==-1)	continue;
			if(d[i]!=-1)	continue;
			pq.push({i, cost+arr[cur][i]});
		}
	}
}
void deline(){
	queue<int> Q;
	Q.push(D);
	while(Q.size()){
		int cur=Q.front();
		Q.pop();
		for(int i=0;i<N;++i){
			if(d[cur]==d[i]+arr[i][cur] && arr[i][cur]!=-1){
				arr[i][cur]=-1;
				Q.push(i);
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
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j)	arr[i][j]=-1;
		}
		cin>>S>>D;
		while(M--){
			int u, v, p;
			cin>>u>>v>>p;
			arr[u][v]=p;
		}
		dijkstra();
		deline();
		dijkstra();
		cout<<d[D]<<"\n";
	}
	return 0;
}
