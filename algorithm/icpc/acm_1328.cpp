#include<iostream>
using namespace std;
typedef long long ll;
int N, L, R;
ll dp[101][101][101];
const int mod=1000000007;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L>>R;
	dp[1][1][1]=1;
	ll ans;
    for(int n=2; n<=N; n++) {
        for(int l=1; l<=L; l++) {
            for(int r=1; r<=R ; r++) {
            	dp[n][l][r]=dp[n-1][l][r]*(n-2)+dp[n-1][l-1][r]+dp[n-1][l][r-1];
                dp[n][l][r]%=mod;
            }
        }
    }
	cout<<dp[N][L][R]<<"\n";
	return 0;
}
