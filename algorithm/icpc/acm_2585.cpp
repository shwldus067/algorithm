#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
int N, K;
int x[1002], y[1002];
bool visit[1002];
int dist(int a, int b){
	int c=x[a]-x[b], d=y[a]-y[b];
	return (int)ceil(sqrt(c*c+d*d)/10);
}
bool bfs(int m){
	for(int i=0;i<=N;++i)	visit[i]=false;
	queue<pair<int, int> > Q;
	Q.push({0, 0});
	while(Q.size()){
		int cur=Q.front().first, cnt=Q.front().second;
		Q.pop();
		if(cur==N){
			return true;
		}
		if(cnt>K)	continue;
		for(int i=1;i<=N;++i){
			if(visit[i])	continue;
			if(dist(cur, i)<=m){
				visit[i]=true;
				Q.push({i, cnt+1});
			}
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		cin>>x[i]>>y[i];
	}
	N++;
	x[N]=y[N]=10000;
	int l=0, r=1415, ans;
	while(l<=r){
		int m=(l+r)/2;
		if(bfs(m))	ans=m, r=m-1;
		else	l=m+1;
	}
	cout<<ans<<"\n";
	return 0;
}
