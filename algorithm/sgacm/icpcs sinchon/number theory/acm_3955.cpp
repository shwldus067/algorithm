#include<iostream>
using namespace std;
typedef long long ll;
ll T, K, C;
ll euclid(ll a, ll b){
	ll r, t, x=0, y=1;
	while(a!=1){
		if(b==0)	return -1;
		r=a%b;
		t=x-y*(a/b);
		a=b;
		b=r;
		x=y;
		y=t;
	}
	if(x<0)	x=x+K;
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>K>>C;
		if(K==1){
			cout<<"2\n";
			continue;
		}
		if(C==1){
			if(K==1e9)	cout<<"IMPOSSIBLE\n";
			else	cout<<K+1<<"\n";
			continue;
		}
		ll ans=euclid(K, C);
		if(ans==-1 || ans>1e9){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
