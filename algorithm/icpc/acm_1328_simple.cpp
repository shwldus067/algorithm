#include<iostream>
using namespace std;
const int mod=1000000007;
int N, L, R, dp[101][101]={1, }, com[101][101]={1, };
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L>>R;
	for(int i=1;i<N;i++){
		com[i][0]=1;
		for(int j=1;j<=i;j++){
			com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
		}
		for(int j=1;j<=i;j++){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*(i-1ll))%mod;
		}
	}
	int ans=0;
	for(int i=1;i<=N;i++){
		ans=(ans+dp[i-1][L-1]*1ll*dp[N-i][R-1]%mod*com[N-1][i-1])%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
