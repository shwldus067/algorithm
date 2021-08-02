#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, D, A[10000], B[10000], C[10000];
	cin>>N>>K>>D;
	for(int i=0;i<K;++i)	cin>>A[i]>>B[i]>>C[i];
	int l=1, r=N;
	while(l<r){
		int n=(l+r)/2;
		long long ret=0;
		for(int i=0;i<K;++i){
			if(A[i]<=n && n<=B[i])	ret+=(n-A[i])/C[i]+1;
			else if(B[i]<n)	ret+=(B[i]-A[i])/C[i]+1;
		}
		if(ret<1ll*D)	l=n+1;
		else	r=n;
	}
	cout<<r<<"\n";
	return 0;
}
