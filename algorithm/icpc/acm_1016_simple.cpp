#include<stdio.h>
typedef long long ll;
ll m, M, cnt;
bool chk[1000001];
int main(){
	scanf("%lld %lld", &m, &M);
	for(ll i=2, n=4;n<=M;++i, n=i*i){
		for(ll j=(m-1)/n*n+n;j<=M;j+=n)
			if(!chk[j-m])	chk[j-m]=1, cnt++;
	}
	printf("%lld\n", M-m+1-cnt);
	return 0;
}
