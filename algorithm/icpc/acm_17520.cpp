#include<iostream>
using namespace std;
const int mod=16769023;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	++N;
	N/=2;
	long long res=1, a=2;
	while(N){
		if(N&1)	res=res*a%mod;
		a=a*a%mod;
		N>>=1;
	}
	cout<<res<<"\n";
	return 0;
}
