#include<iostream>
using namespace std;
int N, M, seg[1<<18], arr[100000];
int init(int x, int s, int e){
	if(s==e)	return seg[x]=arr[s];
	int m=(s+e)/2;
	return seg[x]=min(init(x*2, s, m), init(x*2+1, m+1, e));
}
int query(int x, int s, int e, int l, int r){
	if(e<l || r<s)	return 1e9;
	if(l<=s && e<=r)	return seg[x];
	int m=(s+e)/2;
	return min(query(x*2, s, m, l, r), query(x*2+1, m+1, e, l, r));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)	cin>>arr[i];
	init(1, 0, N-1);
	while(M--){
		int a, b;
		cin>>a>>b;
		cout<<query(1, 0, N-1, a-1, b-1)<<"\n";
	}
	return 0;
}
