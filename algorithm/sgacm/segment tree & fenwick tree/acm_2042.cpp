#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll init(vector<ll>& tr, vector<ll>& a, int nx, int s, int e){
	if(s==e)	return tr[nx]=a[s];
	return tr[nx]=init(tr, a, nx<<1, s, (s+e)/2)
				+init(tr, a, (nx<<1)+1, (s+e)/2+1, e);
}
ll sum(vector<ll>& tr, int nx, int s, int e, int l, int r){
	if(l>e || r<s)	return 0;
	else if(l<=s && e<=r)	return tr[nx];
	else	return sum(tr, nx<<1, s, (s+e)/2, l, r)
					+sum(tr, (nx<<1)+1, (s+e)/2+1, e, l, r);
}
void update(vector<ll>& tr, int nx, int s, int e, int i, ll dx){
	if(i<s || i>e)	return ;
	tr[nx]+=dx;
	if(s==e)	return ;
	int m=(s+e)/2;
	if(i<=m)	update(tr, nx<<1, s, m, i, dx);
	else	update(tr, (nx<<1)+1, m+1, e, i, dx);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, K, a, b, c;
	cin>>N>>M>>K;
	int k=(int)ceil(log2(N));
	int size=(1<<(k+1));
	vector<ll> ary(N);
	vector<ll> seg(size);
	for(int i=0;i<N;i++){
		cin>>ary[i];
	}
	init(seg, ary, 1, 0, N-1);
	for(int i=0;i<M+K;i++){
		cin>>a>>b>>c;
		if(a==1){
			int dx=c-ary[b-1];
			ary[b-1]=c;
			update(seg, 1, 0, N-1, b-1, dx);
		}
		else if(a==2){
			cout<<sum(seg, 1, 0, N-1, b-1, c-1)<<"\n";
		}
	}
	return 0;
}
