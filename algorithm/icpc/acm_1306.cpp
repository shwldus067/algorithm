#include<iostream>
using namespace std;
int N, M, arr[1000001], tree[1000001];
void update(int i, int d){
	while(i<=1e6){
		tree[i]+=d;
		i+=(i&-i);
	}
}
int query(int i){
	int ret=0;
	while(i){
		ret+=tree[i];
		i-=(i&-i);
	}
	return ret;
}
int sol(){
	int l=1, r=1000000, ans=-1;
	while(l<=r){
		int m=(l+r)/2;
		if(query(m)<M)	l=m+1;
		else	r=m-1, ans=m;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>arr[i];
	}
	M=2*M-1;
	for(int i=1;i<M;++i)	update(arr[i], 1);
	for(int i=M;i<=N;++i){
		update(arr[i], 1);
		cout<<sol()<<" ";
		update(arr[i-M+1], -1);
	}
	return 0;
}
