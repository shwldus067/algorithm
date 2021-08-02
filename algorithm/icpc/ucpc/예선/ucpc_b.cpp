#include<iostream>
using namespace std;
long long T, a, b, mod;
long long ans[7];
long long pow(long long k){
	long long res=1, tmp=10;
	while(k){
		if(k&1)	res=(res*tmp)%mod;
		tmp=(tmp*tmp)%mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	cin>>T;
	while(T--){
		cin>>a>>b;
		int t=a, k=0;
		while(t){
			++k;
			t/=10;
		}
		mod=k+b+1;
		a%=mod;
		a=(a*pow(b))%mod;
		a=(a-pow(mod-2)+3+mod)%mod;
		if(a==0){
			cout<<1<<"\n";
		}
		else{
			cout<<"-2"<<"\n";
		}
	}/*
	int x=2, t=10, p=2, cnt=0;
	while(x<=10000){
		cout<<x<<'-';
		cnt++;
		if(x+2>=t-1){
			t*=10;
			cout<<"\n"<<cnt*p<<"\n";
			cnt=0;
			p++;
		}
		x+=p;
	}*/
	return 0;
}
