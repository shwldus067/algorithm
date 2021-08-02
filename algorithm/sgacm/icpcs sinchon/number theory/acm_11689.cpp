#include<iostream>
using namespace std;
typedef long long ll;
ll N;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	ll res=N;
	for(ll i=2;i*i<=N;++i){
		if(N%i)	continue;
		while(N%i==0)	N/=i;
		res=res/i*(i-1);
	}
	if(N!=1)	res=res/N*(N-1);
	cout<<res<<"\n";
	return 0;
}
