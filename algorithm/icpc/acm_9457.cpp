#include<iostream>
using namespace std;
const int mod=10007;
int T, n, R[50001]={0, 1, 4, }, C[50001]={0, 1, };
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int i=3;i<=50000;++i){
		R[i]=(4*R[i-1]-R[i-2]+mod)%mod;
		C[i]=(2*R[i]-R[i-1]-1+mod)%mod*i%mod;
	}
	while(T--){
		cin>>n;
		cout<<R[n]<<" "<<C[n]<<"\n";
	}
	return 0;
}
