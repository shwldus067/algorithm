#include<iostream>
using namespace std;
int T, N, M, mins, i, t, ans, l, j, k;
int score[10];
int dp[2][5001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>M;
		fill(&dp[0][0], &dp[1][5001], -1);
		mins=20;
		for(i=0;i<M;i++){
			cin>>score[i];
			mins=min(mins, score[i]);
		}
		dp[0][0]=0;
		t=0;
		ans=-1;
		l=0;
		i=1;
		while(l<=N){
			fill(&dp[!t][0], &dp[!t][5001], -1);
			for(j=l;j<=N;j++){
				if(dp[t][j]<0)	continue;
				for(k=0;k<M;k++){
					if(j+score[k]*i<=N){
						dp[!t][j+score[k]*i]=max(dp[!t][j+score[k]*i], dp[t][j]+score[k]);
					}
				}
			}
			ans=max(ans, dp[!t][N]);
			l+=i*mins;
			i++;
			t=!t;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

