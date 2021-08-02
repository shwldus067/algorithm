#include<stdio.h>
typedef long long ll;
const ll mod=1000000007;
ll pow(ll a, ll b){
	ll ret=1;
	while(b){
		if(b&1)	ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int main(){
	ll N, M;
	scanf("%lld %lld", &N, &M);
	if(N-M<M)	M=N-M;
	ll a=1, b=1;
	while(M--){
		a=a*(N--)%mod;
		b=b*(M+1)%mod;
	}
	printf("%lld\n", a*pow(b, mod-2)%mod);
	return 0;
}
