#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef vector<long long> vl;
typedef vector<int> vi;
typedef long long ll;
const int mod=1000000007;
ll init(vl& t, vi& a, int nx, int s, int e){
	if(s==e)	return t[nx]=a[s];
	int mid=(s+e)/2;
	ll ret=init(t, a, nx<<1, s, mid)*init(t, a, (nx<<1)+1, mid+1, e);
	return t[nx]=ret%mod;
}
ll update(vl& t, int nx, int s, int e, int i, int dx){
	if(i<s || i>e)	return t[nx];
	if(i==s && i==e)	return t[nx]=dx;
	int mid=(s+e)/2;
	ll ret=update(t, nx<<1, s, mid, i, dx)*update(t, (nx<<1)+1, mid+1, e, i, dx);
	return t[nx]=ret%mod;
}
ll mul(vl& t, int nx, int s, int e, int l, int r){
	if(e<l || r<s)	return 1;
	if(l<=s && e<=r)	return t[nx];
	int mid=(s+e)/2;
	ll ret=mul(t, nx<<1, s, mid, l, r)*mul(t, (nx<<1)+1, mid+1, e, l, r);
	return ret%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, n, size, a, b, c;
	cin>>N>>M>>K;
	M+=K;
	vi A(N);
	n=(int)ceil(log2(N));
	size=(1<<(n+1));
	vl seg(size);
	for(int i=0;i<N;i++)	cin>>A[i];
	init(seg, A, 1, 0, N-1);
	while(M--){
		cin>>a>>b>>c;
		if(a==1){
			A[b-1]=c;
			update(seg, 1, 0, N-1, b-1, c);
		}
		else{
			cout<<mul(seg, 1, 0, N-1, b-1, c-1)<<"\n";
		}
	}
}
