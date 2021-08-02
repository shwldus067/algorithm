#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const long long inf=50000000000;
int N, M, K;
vector<pair<int, int> > load[10001];
long long dp[10001][21];
struct dij{
	int v, cnt;
	long long c;
	dij(int v, long long c, int cnt):v(v), c(c), cnt(cnt){
	}
};
bool operator<(dij d1, dij d2){
	return d1.c>d2.c;
}
void dijkstra(){
	priority_queue<dij> pq;
	pq.push(dij(1, 0, 0));
	int cur, cnt, next;
	long long c, nc;
	while(pq.size()){
		cur=pq.top().v;
		c=pq.top().c;
		cnt=pq.top().cnt;
		pq.pop();
		if(dp[cur][cnt]<c){
			continue;
		}
		dp[cur][cnt]=c;
		for(int i=0;i<load[cur].size();i++){
			next=load[cur][i].first;
			nc=(long long)load[cur][i].second+c;
			if(cnt<K && c<dp[next][cnt+1]){
				dp[next][cnt+1]=c;
				pq.push(dij(next, c, cnt+1));
			}
			if(nc<dp[next][cnt]){
				dp[next][cnt]=nc;
				pq.push(dij(next, nc, cnt));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	int a, b, c;
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		load[a].push_back({b, c});
		load[b].push_back({a, c});
	}
	fill(&dp[1][0], &dp[N][K+1], inf);
	dijkstra();
	long long ans=inf;
	for(int i=0;i<=K;i++){
		ans=min(ans, dp[N][i]);
	}
	cout<<ans<<"\n";
	return 0;
}
