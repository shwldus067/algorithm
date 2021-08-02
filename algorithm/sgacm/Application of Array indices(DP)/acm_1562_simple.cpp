#include<iostream>
using namespace std;
const int mod=1000000000;
int N, dp[10][10][10][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<10;i++)	dp[i][i][i][1]=1;
	int t=0, p=1;
	for(int n=1;n<N;n++){
		for(int i=0;i<10;i++){
			for(int j=i;j<10;j++){
				for(int k=i;k<=j;k++){
					if(i<k && k<j){
						dp[i][j][k+1][t]=(dp[i][j][k+1][t]+dp[i][j][k][p])%mod;
						dp[i][j][k-1][t]=(dp[i][j][k-1][t]+dp[i][j][k][p])%mod;
						dp[i][j][k][p]=0;
						continue;
					}
					if(i==k){
						if(i!=0){
							dp[i-1][j][k-1][t]=(dp[i-1][j][k-1][t]+dp[i][j][k][p])%mod;
						}
						if(k<j){
							dp[i][j][k+1][t]=(dp[i][j][k+1][t]+dp[i][j][k][p])%mod;
						}
					}
					if(k==j){
						if(j!=9){
							dp[i][j+1][k+1][t]=(dp[i][j+1][k+1][t]+dp[i][j][k][p])%mod;
						}
						if(i<k){
							dp[i][j][k-1][t]=(dp[i][j][k-1][t]+dp[i][j][k][p])%mod;
						}
					}
					dp[i][j][k][p]=0;
				}
			}
		}
		t^=1, p^=1;
	}
	int res=0;
	for(int i=0;i<10;i++){
		res=(res+=dp[0][9][i][p])%mod;
	}
	cout<<res<<"\n";
	return 0;
}
