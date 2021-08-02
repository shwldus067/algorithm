#include<iostream>
using namespace std;
const int mod=1000000003;
int d[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin>>N>>K;
	for(int i=0;i<=K;++i)	d[i]=1;
	for(int i=N-2*K+1;i>0;--i){
		for(int j=1;j<=K;++j){
			d[j]=(d[j]+d[j-1])%mod;
		}
	}
	if(K>=2)	cout<<(d[K]-d[K-2]+mod)%mod<<"\n";
	else	cout<<d[K]<<"\n";
	return 0;
}
