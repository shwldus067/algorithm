#include<iostream>
using namespace std;
int N, K, M, A[4000001]={1,}, B[4000001]={1,};
const int mod=1e9+7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<4000001;++i)	A[i]=(long long)A[i-1]*i%mod;
	int x=A[4000000], b=1e9+5, ret=1;
	while(b){
		if(b&1)	ret=(long long)ret*x%mod;
		x=(long long)x*x%mod;
		b>>=1;
	}
	B[4000000]=ret;
	for(int i=4000000;i;--i)
		B[i-1]=(long long)B[i]*i%mod;
	cin>>M;
	while(M--){
		cin>>N>>K;
		cout<<(long long)A[N]*B[K]%mod*B[N-K]%mod<<"\n";
	}
	return 0;
}
