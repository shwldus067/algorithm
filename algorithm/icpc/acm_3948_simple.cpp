#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, i, j, l;
	long long dp[2][21]={0, }, com[21][21]={1, };
	dp[0][0]=dp[1][0]=dp[0][1]=1;
	for(i=1;i<=20;i++){
		com[i][0]=1;
		for(j=1;j<=i;j++){
			com[i][j]=com[i-1][j-1]+com[i-1][j];
		}
	}
	for(i=2;i<=20;i++){
		for(j=0;j<i;j++){
			l=!(j%2);
			dp[l][i]+=dp[l][j]*dp[0][i-1-j]*com[i-1][j];
		}
	}
	cin>>T;
	while(T--){
		cin>>N;
		cout<<dp[0][N]+dp[1][N]<<"\n";
	}
	return 0;
}
