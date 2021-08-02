#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, L, R, A[2][100001], B[100001], S, t=0;
	cin>>N>>M>>K;
	++N;
	for(int i=1;i<N;++i)	A[0][i]=B[i]=i;
	while(M--){
		cin>>L>>R;
		S=(R-L+1)/2;
		for(int i=0;i<S;++i)	swap(A[0][L+i], A[0][R-i]);
	}
	while(K){
		if(K&1)	for(int i=1;i<N;++i)	B[i]=A[t][B[i]];
		for(int i=1;i<N;++i)	A[t^1][i]=A[t][A[t][i]];
		K>>=1;t^=1;
	}
	for(int i=1;i<N;++i)	cout<<B[i]<<"\n";
	return 0;
}
