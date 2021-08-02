#include<iostream>
using namespace std;
typedef long long ll;
int N, K, M, A[4000001]={1,};
const ll mod=1e9+7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(ll i=1;i<4000001;++i)	A[i]=i*A[i-1]%mod;
	cin>>M;
	while(M--){
		cin>>N>>K;
		ll ret=1, b=1e9+5, x=A[N], y=(ll)A[K]*A[N-K]%mod;
		while(b){
			if(b&1)	ret=ret*y%mod;
			y=y*y%mod;
			b>>=1;
		}
		cout<<x*ret%mod<<"\n";
	}
	return 0;
}
