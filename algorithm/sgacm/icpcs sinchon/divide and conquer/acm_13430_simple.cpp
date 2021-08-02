#include<iostream>
using namespace std;
const long long mod=1000000007;
typedef long long ll;
ll k, n;
ll pow(ll a){
	ll ret=1, b=mod-2;
	while(b){
		if(b&1)	ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>k>>n;
	ll ans=1;
	for(ll i=0;i<=k;++i){
		ans=ans*(n+i)%mod*pow(i+1)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
