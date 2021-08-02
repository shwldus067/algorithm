#include<iostream> 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N;
	long long dp[21]={0, }, com[21][21]={1, };
	for(int i=1;i<21;i++){
		com[i][0]=1;
		for(int j=1;j<i;j++){
			com[i][j]=com[i-1][j-1]+com[i-1][j];
		}
		com[i][i]=1;
	}
	dp[0]=dp[1]=1;
	for(int i=2;i<21;i++){
		dp[i]+=dp[0]*dp[i-1]*com[i-1][0];
		dp[i]+=dp[1]*dp[i-2]*com[i-1][1];
		for(int j=2;j<i-2;j++){
			dp[i]+=dp[i-j-1]/2*dp[j]/2*com[i-1][j];
		}
	}
	cin>>T;
	while(T--){
		cin>>N;
		cout<<dp[N]<<"\n";
	}
	return 0;
}
