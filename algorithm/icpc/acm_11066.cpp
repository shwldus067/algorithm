#include<iostream>
using namespace std;
const int inf=(1<<30);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, K;
	cin>>T;
	while(T--){
		cin>>K;
		int chap[K], sum[K+1]={0, }, dp[K+1][K+1];
		for(int i=0;i<K;i++){
			cin>>chap[i];
			sum[i+1]=sum[i]+chap[i];
		}
		fill(&dp[0][0], &dp[K][K+1], 0);
		for(int d=1;d<K;d++){
			for(int i=1;i+d<=K;i++){
				int j=i+d;
				dp[i][j]=inf;
				for(int k=i;k<j;k++){
					dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
				}
			}
		}
		cout<<dp[1][K]<<"\n";
	}
	return 0;
}
