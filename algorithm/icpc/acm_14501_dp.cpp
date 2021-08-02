#include<iostream>
using namespace std;
int N, T[15], P[15], ans, dp[15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>T[i]>>P[i];
		dp[i]=P[i];
	}
	for(int i=1;i<N;++i){
		for(int j=0;j<i;++j){
			if(i-j>=T[j]){
				dp[i]=max(P[i]+dp[j], dp[i]);
			}
		}
	}
	for(int i=0;i<N;i++){
		if(i+T[i]<=N){
			if(ans<dp[i]){
				ans=dp[i];
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
