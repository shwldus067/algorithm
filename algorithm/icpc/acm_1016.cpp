#include<stdio.h>
typedef long long ll;
bool chk[1000001], p[1000001];
int main(){
	ll cnt=0, m, M, f=1;
	scanf("%lld %lld", &m, &M);
	++M;
	for(ll i=2, n=4;n<M;++i, n=i*i){
		if(p[i])	continue;
		if(f){
			if(n*n>M)	f=0;
			for(ll j=n;j*j<M;j+=i)	p[j]=1;
		}
		for(ll j=(m-1)/n*n+n;j<M;j+=n)
			if(!chk[j-m])	chk[j-m]=1, cnt++;
	}
	printf("%lld\n", M-m-cnt);
	return 0;
}
