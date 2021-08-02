#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int P[N], dp[N+1];
	for(int i=0;i<N;i++)	cin>>P[i];
	dp[0]=0;
	for(int i=1;i<=N;i++){
		dp[i]=0;
		for(int j=1;j<=i;j++){
			dp[i]=max(dp[i], dp[i-j]+P[j-1]);
		}
	}
	cout<<dp[N]<<"\n";
}
