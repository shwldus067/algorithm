#include<iostream>
using namespace std;
int N, Q;
long long arr[100001], tree[100001];
void update(int i, long long d){
	while(i<=N){
		tree[i]+=d;
		i+=(i&-i);
	}
}
long long query(int i){
	long long ret=0;
	while(i>0){
		ret+=tree[i];
		i-=(i&-i);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;++i){
		cin>>arr[i];
		update(i, arr[i]);
	}
	while(Q--){
		int x, y, a, t;
		long long b;
		cin>>x>>y>>a>>b;
		if(y<x){
			t=y;
			y=x;
			x=t;
		}
		cout<<query(y)-query(x-1)<<"\n";
		update(a, b-arr[a]);
		arr[a]=b;
	}
	return 0;
}
