#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll fact(ll n, ll r){
	ll ret=1;
	while(r--)	ret=ret*(n--)%mod;
	return ret;
}
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, M, ans;
	cin>>N>>M;
	if(N-M<M)	M=N-M;
	ans=fact(N, M)*pow(fact(M, M), mod-2)%mod;
	cout<<ans<<"\n";
	return 0;
}
