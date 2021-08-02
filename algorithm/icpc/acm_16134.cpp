#include<stdio.h>
typedef long long ll;
const ll mod=1e9+7;
ll pow(ll a, ll b){
	int ret=1;
	while(b){
		if(b&1)	ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int main(){
	ll N, R, A=1, B=1;
	scanf("%d %d", &N, &R);
	if(N-R<R)	R=N-R;
	for(ll i=0;i<R;++i){
		A=A*(N-i)%mod;
		B=B*(i+1)%mod;
	}
	printf("%d\n", A*pow(B, mod-2)%mod);
	return 0;
}
