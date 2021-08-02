#include<iostream>
using namespace std;
const int inf=(1<<30);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, N;
	cin>>T;
	while(T--){
		cin>>N;
		int chap[N], sum[N+1]={0, }, num[N+1][N+1], dp[N+1][N+1];
		fill(&dp[0][0], &dp[N][N+1], 0);
		for(int i=0;i<N;i++){
			cin>>chap[i];
			sum[i+1]=sum[i]+chap[i];
		}
		for(int i=0;i<N;i++){
			num[i][i+1]=i+1;
		}
		for(int d=2;d<=N;d++){
			for(int i=0;i+d<=N;i++){
				int j=i+d;
				dp[i][j]=inf;
				for(int k=num[i][j-1];k<=num[i+1][j];k++){
					int v=dp[i][k]+dp[k][j]+sum[j]-sum[i];
					if(dp[i][j]>v){
						dp[i][j]=v;
						num[i][j]=k;
					}
				}
			}
		}
		cout<<dp[0][N]<<"\n";
	}
	return 0;
}
//Kruth's optimization
