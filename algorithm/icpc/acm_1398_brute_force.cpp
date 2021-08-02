#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
int T;
ll P, res;
int length(ll p){
	int len=0;
	while(p){
		p/=10;
		len++;
	}
	return len;
}
void func(ll p, ll cnt){
	if(cnt>res)	return;
	if(p<0)	return;
	if(p==0){
		res=min(res, cnt);
		return;
	}
	int len=length(p);
	ll f=pow(10, len-1);
	func(p-(p/f)*f, cnt+(p/f));
	if(!(len&1)){
		ll s=f/10;
		func(p-25*s, cnt+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>P;
		res=1;
		res<<=50;
		func(P, 0);
		cout<<res<<"\n";
	}
	return 0;
}
