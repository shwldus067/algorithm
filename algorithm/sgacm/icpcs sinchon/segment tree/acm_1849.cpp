#include<iostream>
using namespace std;
int N, seg[400001], arr[100001];
int update(int x, int i, int d, int s, int e){
	if(e<i || i<s)	return seg[x];
	if(s==e)	return seg[x]=d;
	int mid=(s+e)/2;
	return seg[x]=update(x*2, i, d, s, mid)+update(x*2+1, i, d, mid+1, e);
}
int query(int x, int d, int s, int e){
	if(s==e)	return s;
	int mid=(s+e)/2;
	if(seg[x*2]>=d)	return query(x*2, d, s, mid);
	return query(x*2+1, d-seg[x*2], mid+1, e);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;++i)	update(1, i, 1, 1, N);
	for(int i=1;i<=N;++i){
		int t;
		cin>>t;
		int idx=query(1, t+1, 1, N);
		arr[idx]=i;
		update(1, idx, 0, 1, N);
	}
	for(int i=1;i<=N;++i)	cout<<arr[i]<<"\n";
	return 0;
}
