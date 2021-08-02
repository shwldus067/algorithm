#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef vector<int>	vi;
int init(vi& t, vi& a, int nx, int s, int e){
	if(s==e)	return t[nx]=a[s];
	int mid=(s+e)/2;
	return t[nx]=init(t, a, nx<<1, s, mid)*init(t, a, (nx<<1)+1, mid+1, e);
}
int update(vi& t, int nx, int s, int e, int i, int dx){
	if(i<s || i>e)	return t[nx];
	if(s==i && i==e)	return t[nx]=dx;
	int mid=(s+e)/2;
	return t[nx]=update(t, nx<<1, s, mid, i, dx)*update(t, (nx<<1)+1, mid+1, e, i, dx);
}
int mul(vi&t, int nx, int s, int e, int l, int r){
	if(e<l || r<s)	return 1;
	if(l<=s && e<=r)	return t[nx];
	int mid=(s+e)/2;
	return mul(t, nx<<1, s, mid, l, r)*mul(t, (nx<<1)+1, mid+1, e, l, r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K, tmp, n, size, a, b;
	char T;
	while(cin>>N>>K){
		vi A(N);
		n=(int)ceil(log2(N));
		size=(1<<(n+1));
		vi seg(size);
		for(int i=0;i<N;i++){
			cin>>tmp;
			if(tmp==0)	A[i]=0;
			else	A[i]=tmp>0 ? 1:-1;
		}
		init(seg, A, 1, 0, N-1);
		while(K--){
			cin>>T>>a>>b;
			if(T=='C'){
				if(b==0)	A[a-1]=0;
				else	A[a-1]=b>0 ? 1:-1;
				update(seg, 1, 0, N-1, a-1, A[a-1]);
			}
			else{
				tmp=mul(seg, 1, 0, N-1, a-1, b-1);
				if(tmp==0)	cout<<0;
				else if(tmp<0)	cout<<'-';
				else	cout<<'+';
			}
		}
		cout<<"\n";
	}
	return 0;
}
