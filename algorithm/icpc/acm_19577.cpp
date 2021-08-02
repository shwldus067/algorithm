#include<iostream>
using namespace std;
typedef long long ll;
#define min(a, b) a<b ? a:b
bool p[100001];
int prime[10000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, cnt=0, ans=2e9;
	cin>>n;
	for(ll i=2;i<=1e5;++i){
		if(p[i])	continue;
		prime[cnt++]=(int)i;
		for(ll j=i*i;j<=1e5;j+=i){
			p[j]=1;
		}
	}
	for(int i=1;i*i<=n;++i){
		if(n%i)	continue;
		int j=n/i, a=i;
		for(int k=0, t=prime[0];t && t<=i;++k, t=prime[k]){
			if(i%t)	continue;
			a=a*(t-1)/t;
		}
		if(a==j)	ans=min(ans, i);
		a=j;
		for(int k=0, t=prime[0];t && t<=j;++k, t=prime[k]){
			if(j%t)	continue;
			a=a*(t-1)/t;
		}
		if(a==i)	ans=min(ans, j);
	}
	if(ans==2e9)	cout<<"-1\n";
	else cout<<ans<<"\n";
	return 0;
}
