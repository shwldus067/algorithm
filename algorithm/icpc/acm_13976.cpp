#include<stdio.h>
typedef long long ll;
const ll mod=1e9+7;
int main(){
	ll N;
	scanf("%lld", &N);
	if(N&1ll){
		printf("0\n");return 0;
	}
	N>>=1;
	int a=1, b=0, c=0, d=1, e=4, f=1e9+6, g=1, h=0, p, q, r, s;
	while(N){
		if(N&1){
			p=(1ll*a*e+1ll*b*g)%mod;q=(1ll*a*f+1ll*b*h)%mod;
			r=(1ll*c*e+1ll*d*g)%mod;s=(1ll*c*f+1ll*d*h)%mod;
			a=p;b=q;c=r;d=s;
		}
		p=(1ll*e*e+1ll*f*g)%mod;q=(1ll*e*f+1ll*f*h)%mod;
		r=(1ll*g*e+1ll*h*g)%mod;s=(1ll*g*f+1ll*h*h)%mod;
		e=p;f=q;g=r;h=s;
		N>>=1;
	}
	printf("%d\n", (a+b)%mod);
	return 0;
}
