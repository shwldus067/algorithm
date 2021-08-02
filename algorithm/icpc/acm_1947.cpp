#include<iostream>
using namespace std;
#define mod 1000000000
int d[1000000]={0, 1};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=2;i<n;++i){
		d[i]=1ll*i*(d[i-1]+d[i-2])%mod;
	}
	cout<<d[n-1]<<"\n";
	return 0;
}
