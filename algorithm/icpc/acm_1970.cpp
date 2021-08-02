#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin>>N;
	int A[N], dp[N][N];
	for(int i=0;i<N;i++)	cin>>A[i];
	fill(&dp[0][0], &dp[N-1][N], 0);
	for(int d=1;d<N;d++){
		for(int i=0;i+d<N;i++){
			int j=i+d;
			if(A[i]==A[j]){
				if(i+1==j)	dp[i][j]=1;
				else if(dp[i][j]<dp[i+1][j-1]+1){
					dp[i][j]=dp[i+1][j-1]+1;
				}
			}
			for(int k=i;k<j;k++){
				if(dp[i][j]<dp[i][k]+dp[k+1][j]){
					dp[i][j]=dp[i][k]+dp[k+1][j];
				}
			}
		}
	}
	cout<<dp[0][N-1]<<"\n";
	return 0;
}
