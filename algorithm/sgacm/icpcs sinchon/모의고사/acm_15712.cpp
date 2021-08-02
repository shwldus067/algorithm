#include<iostream>
using namespace std;
typedef long long ll;
ll a, r, n, mod;
ll pow(ll a, ll b){
	ll res=1;
	while(b){
		if(b&1)	res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll fun(ll x){
	if(x==0)	return 1;
	if(x==1)	return (r+1)%mod;
	if(x&1)	return fun(x/2)*(1+pow(r, x/2+1))%mod;
	return (fun(x/2-1)*(1+pow(r, x/2))%mod+pow(r, x))%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>r>>n>>mod;
	cout<<a*fun(n-1)%mod<<"\n";
	return 0;
}
