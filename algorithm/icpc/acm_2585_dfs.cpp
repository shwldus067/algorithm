#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
int N, K, MAX;
int x[1002], y[1002];
bool visit[1002];
int dist(int a, int b){
	int c=x[a]-x[b], d=y[a]-y[b];
	return c*c+d*d;
}
bool dfs(int cur, int cnt){
	if(cnt>K)	return false;
	visit[cur]=true;
	for(int i=1;i<N;++i){
		if(!visit[i] && dist(cur, i)<=MAX){
			if(dist(i, N)<=MAX || dfs(i, cnt+1))	return true;
		}
	}
	return false;
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
		MAX=m*m*100;
		for(int i=0;i<=N;++i)	visit[i]=false;
		if(dfs(0, 0))	ans=m, r=m-1;
		else	l=m+1;
	}
	cout<<ans<<"\n";
	return 0;
}
