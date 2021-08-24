#include<iostream>
using namespace std;
int N, seg[400001], lazy[400001];
void lazy_update(int x, int s, int e){
	if(!lazy[x])	return;
	seg[x]=(e-s+1)-seg[x];
	if(s!=e){
		lazy[x*2]^=1;
		lazy[x*2+1]^=1;
	}
	lazy[x]=0;
}
int update(int x, int l, int r, int s, int e){
	lazy_update(x, s, e);
	if(e<l || r<s)	return seg[x];
	if(l<=s && e<=r){
		lazy[x]^=1;
		lazy_update(x, s, e);
		return seg[x];
	}
	int mid=(s+e)/2;
	return seg[x]=update(x*2, l, r, s, mid)+update(x*2+1, l, r, mid+1, e);
}
int query(int x, int l, int r, int s, int e){
	lazy_update(x, s, e);
	if(e<l || r<s)	return 0;
	if(l<=s && e<=r)	return seg[x];
	int mid=(s+e)/2;
	return query(x*2, l, r, s, mid)+query(x*2+1, l, r, mid+1, e);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int M, O, S, T;
	cin>>N>>M;
	while(M--){
		cin>>O>>S>>T;
		if(O)	cout<<query(1, S, T, 1, N)<<"\n";
		else	update(1, S, T, 1, N);
	}
	return 0;
}
