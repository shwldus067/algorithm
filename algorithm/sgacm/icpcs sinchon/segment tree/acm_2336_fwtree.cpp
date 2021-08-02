#include<iostream>
using namespace std;
int N, tree[500001], f[500001], s[500001], t[500001];
void update(int i, int d){
	while(i<=N){
		tree[i]=min(tree[i], d);
		i+=(i&-i);
	}
}
int query(int i){
	int ret=1e9;
	while(i>0){
		ret=min(ret, tree[i]);
		i-=(i&-i);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<=N;++i)	tree[i]=1e9;
	for(int i=1;i<=N;++i){
		cin>>f[i];
	}
	for(int i=1;i<=N;++i){
		int tp;
		cin>>tp, s[tp]=i;
	}
	for(int i=1;i<=N;++i){
		int tp;
		cin>>tp, t[tp]=i;
	}
	int ans=0;
	for(int i=1;i<=N;++i){
		int x=f[i];
		if(query(s[x])>t[x])	++ans;
		update(s[x], t[x]);
	}
	cout<<ans<<"\n";
	return 0;
}
