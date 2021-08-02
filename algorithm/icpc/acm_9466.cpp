#include<iostream>
using namespace std;
int T, n, w[100001], g[100001], cnt;
bool chk[100001];
int dfs(int x){
	chk[x]=1;
	g[x]=cnt;
	int y=w[x], tt;
	if(y==x)	return 0;
	if(g[y]==cnt)	return y;
	if(chk[y])	return g[x]=0;
	if(tt=dfs(y)){
		if(tt==x)	return 0;
		return tt;
	}
	g[x]=0;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)	cin>>w[i], g[i]=0, chk[i]=0;
		cnt=0;
		for(int i=1;i<=n;++i){
			if(!chk[i])	++cnt, dfs(i);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(!g[i])	++ans;
		}
		cout<<ans<<"\n";
	}
}
