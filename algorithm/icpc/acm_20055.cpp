#include<iostream>
using namespace std;
int N, M, K, A[200], k, u, d, ans;
int B[200];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	M=N*2;
	for(int i=0;i<M;++i)	cin>>A[i];
	u=0, d=N-1;
	while(k<K){
		++ans;
		u=u ? u-1:M-1;
		d=d ? d-1:M-1;
		int i=d, n;
		B[i]=0;
		for(int j=1;j<N;++j){
			n=i;
			i=i ? i-1:M-1;
			if(B[i] && !B[n] && A[n]){
				if(!(--A[n]))	++k;
				B[i]=0;
				B[n]=1;
			}
		}
		if(A[u]){
			B[u]=1;
			if(!(--A[u]))	++k;
		}
		B[d]=0;
	}
	cout<<ans<<"\n";
	return 0;
}
