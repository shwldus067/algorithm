#include<iostream>
using namespace std;
const int inf=(1<<31)-1;
int main(){
	int N;
	cin>>N;
	int P[N], dp[N+1];
	for(int i=0;i<N;i++)	cin>>P[i];
	dp[0]=0;
	for(int i=1;i<=N;i++){
		dp[i]=inf;
		for(int j=1;j<=i;j++){
			dp[i]=min(dp[i], dp[i-j]+P[j-1]);
		}
	}
	cout<<dp[N]<<"\n";
}
