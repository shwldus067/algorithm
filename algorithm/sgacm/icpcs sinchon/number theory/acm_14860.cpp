#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
typedef long long ll;
ll N, M;
vector<bool> prime(1.5e7, 0);
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
	scanf("%lld %lld", &N, &M);
	ll ans=1;
	for(ll i=2;i<=N;++i){
		if(prime[i])	continue;
		ll m=0;
		for(ll p=i;p<=M;p*=i){
			m+=(M/p)*(N/p);
		}
		ans=ans*pow(i, m)%mod;
		for(ll j=i*i;j<=N;j+=i){
			prime[j]=true;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
