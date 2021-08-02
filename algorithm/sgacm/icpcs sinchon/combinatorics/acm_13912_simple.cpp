#include<iostream>
using namespace std;
const int mod=1000000007;
int H;
long long exp(long long n, int r){
	long long res=1, tmp=n;
	while(r){
		if(r&1){
			res=(res*tmp)%mod;
		}
		tmp=(tmp*tmp)%mod;
		r/=2;
	}
	return res;
}
long long fact(long long n){
	long long res=1;
	for(long long i=2;i<=n;++i){
		res=(res*i)%mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>H;
	long long ans=1, tmp;
	for(int i=1;i<=H;++i){
		ans=(ans*ans)%mod;
		tmp=(1<<(i+1))-2;
		ans=(ans*fact(tmp))%mod;
		ans=(ans*(tmp=exp(fact(tmp/2), mod-2)))%mod;
		ans=(ans*tmp)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
