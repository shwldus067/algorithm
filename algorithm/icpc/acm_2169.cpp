#include<iostream>
using namespace std;
int N, M, arr[1001][1001], dp[1001][1001], l[1002], r[1002];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>arr[i][j];
		}
	}
	dp[1][1]=arr[1][1];
	for(int i=2;i<=M;i++)	dp[1][i]=dp[1][i-1]+arr[1][i];
	for(int i=2;i<=N;i++){
		l[0]=dp[i-1][1];
		for(int j=1;j<=M;j++){
			l[j]=max(dp[i-1][j], l[j-1])+arr[i][j];
		}
		r[M+1]=dp[i-1][M];
		for(int j=M;j>0;j--){
			r[j]=max(dp[i-1][j], r[j+1])+arr[i][j];
			dp[i][j]=max(r[j], l[j]);
		}
	}
	cout<<dp[N][M]<<"\n";
	return 0;
}
