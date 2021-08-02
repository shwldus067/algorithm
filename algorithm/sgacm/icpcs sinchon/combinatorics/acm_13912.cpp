#include<iostream>
using namespace std;
const int mod=1000000007;
int H, c[2047][2047]={1, };
long long d[11]={1, };
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>H;
	for(int i=1;i<=2046;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<=i;++j){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	for(int i=1;i<=H;++i){
		int t=(1<<(i+1))-2;
		d[i]=1ll*c[t][t/2]*d[i-1]%mod*d[i-1]%mod;
	}
	cout<<d[H]<<"\n";
	return 0;
}
