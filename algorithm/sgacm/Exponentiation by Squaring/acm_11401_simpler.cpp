#include<iostream>
using namespace std;
const int mod=1000000007;
long long pow(long long a, int b, int c){
	long long res=1;
	while(b){
		if(b%2){
			res=(long long)(res*a)%(long long)c;
		}
		a=(a*a)%(long long)c;
		b>>=1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	long long r=1, s=1;
	cin>>N>>K;
	if(K>=N/2)	K=N-K;
	for(int i=0;i<K;i++){
		r=(r*(N-i))%mod;
	}
	for(int i=2;i<=K;i++){
		s=(s*i)%mod;
	}
	r=(r*pow(s, mod-2, mod))%mod;
	cout<<r<<"\n";
	return 0;
}
