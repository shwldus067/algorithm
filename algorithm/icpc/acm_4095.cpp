#include<iostream>
using namespace std;
int arr[1001][1001], dp[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, ans;
	while(1){
		cin>>N>>M;
		if(N==0 && M==0)	break;
		for(int i=1;i<=N;++i)for(int j=1;j<=M;++j)	cin>>arr[i][j], dp[i][j]=0;
		ans=0;
		for(int i=1;i<=N;++i)for(int j=1;j<=M;++j){
			if(arr[i][j]){
				dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
				ans=max(ans, dp[i][j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
