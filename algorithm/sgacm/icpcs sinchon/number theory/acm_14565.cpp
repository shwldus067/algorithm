#include<iostream>
using namespace std;
typedef long long ll;
ll N, A;
ll gcd(ll a, ll b){
	ll c;
	while(b){
		c=a;
		a=b;
		b=c%b;
	}
	return a;
}
ll totient(ll N){
	ll res=N;
	for(ll i=2;i*i<=N;++i){
		if(N%i)	continue;
		while(N%i==0)	N/=i;
		res=res/i*(i-1);
	}
	if(N!=1)	res=res/N*(N-1);
	return res;
}
ll mul(ll a, ll b){
	if(b==0)	return 0;
	ll t=mul(a, b/2);
	if(b%2)	return (t+t+a)%N;
	return (t+t)%N;
}
ll pow(ll x){
	if(x==0)	return 1;
	ll t=pow(x/2);
	if(x%2)	return mul(t, mul(t, A));
	return mul(t, t);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>A;
	cout<<(N-A)%N<<" ";
	if(gcd(A, N)!=1){
		cout<<"-1\n";
		return 0;
	}
	ll phi=totient(N);
	cout<<pow(phi-1)<<"\n";
	return 0;
}
