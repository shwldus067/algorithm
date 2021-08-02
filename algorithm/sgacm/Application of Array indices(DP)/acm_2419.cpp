#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int dp[301][301];
int pos[301];
const int inf=(1<<31)-1;
int g(int from, int to, int rem){
	if(!rem)	return 0;
	int l=min(from, to);
	int r=max(from, to);
	int &ret=dp[from][to];
	if(ret!=-1)	return ret;
	ret=inf;
	if(r!=n)	ret=min(ret, g(l, r+1, rem-1)+rem*(pos[r+1]-pos[to]));
	if(l!=0)	ret=min(ret, g(r, l-1, rem-1)+rem*(pos[to]-pos[l-1]));
	return ret;
}
int f(int zidx, int find){
	fill(&dp[0][0], &dp[300][301], -1);
	return g(zidx, zidx, find);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)	cin>>pos[i];
	pos[n]=0;
	sort(pos, pos+n+1);
	int zidx=lower_bound(pos, pos+n+1, 0)-pos;
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx, i*m-f(zidx, i));
	}
	cout<<mx<<"\n";
	return 0;
}
