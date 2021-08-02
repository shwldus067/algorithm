#include<iostream>
using namespace std;
const int mod=1000000007;
long long factorial[4000001];
long long pow(long long a, int b, int c){
	long long res=1;
	while(b){
		if(b%2){
			res=(long long)(res*a)%(long long)c;
		}
		a=(a*a)%(long long)c;
		b>>=1;
	}
	return res;
}
void fact(int n){
	factorial[0]=1;
	for(int i=1;i<=n;i++){
		factorial[i]=(factorial[i-1]*i)%mod;
	}
}
int main(){
	int N, K;
	int res;
	cin>>N>>K;
	fact(N);
	res=(factorial[K]*factorial[N-K])%mod;
	res=(factorial[N]*pow(res, mod-2, mod))%mod;
	cout<<res<<"\n";
	return 0;
}
