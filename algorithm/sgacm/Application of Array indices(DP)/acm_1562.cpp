#include<iostream>
using namespace std;
typedef long long ll;
ll mod=1000000000;
ll dp[101][11][1<<10], n, r, res;
ll f(ll b, ll x, ll flag){	//flag는 포함해야 하는 자리 값 bitmask
	if(x<0 || x>9)	return 0;
	if(b==1)	return !(flag & ~(1<<x));
	ll &v=dp[b][x][flag];
	if(v!=-1)	return v;
	flag&=~(1<<x);
	return v=(f(b-1, x+1, flag)+f(b-1, x-1, flag))%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	fill(&dp[0][0][0], &dp[100][10][1<<10], -1);
	r=0;
	for(ll i=1;i<10;i++){
		r+=f(n, i, (1<<10)-1);
		r%=mod;
	}
	cout<<r<<"\n";
	return 0;
}
