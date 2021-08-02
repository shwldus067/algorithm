#include<iostream>
using namespace std;
int N, M, tree1[100001], tree2[100001], arr[100001];
int query(int s, int e){
	int ret=1e9;
	int i=s, j=s+(s&-s);
	while(j<=e){
		ret=min(ret, tree1[i]);
		i=j;
		j+=j&-j;
	}
	ret=min(ret, arr[i]);
	i=e, j=e-(e&-e);
	while(j>=s){
		ret=min(ret, tree2[i]);
		i=j;
		j-=j&-j;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		int tp;
		cin>>tp;
		arr[i]=tree1[i]=tree2[i]=tp;
	}
	for(int i=1;i<=N;++i){
		int x=i+(i&-i);
		if(x>N)	continue;
		tree2[x]=min(tree2[x], tree2[i]);
	}
	for(int i=N;i>0;--i){
		int x=i-(i&-i);
		if(x==0)	continue;
		tree1[x]=min(tree1[x], tree1[i]);
	}
	while(M--){
		int a, b;
		cin>>a>>b;
		cout<<query(a, b)<<"\n";
	}
	return 0;
}
