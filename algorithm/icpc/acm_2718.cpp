#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N=0, num[1000];
	cin>>T;
	for(int i=0;i<T;++i)	cin>>num[i], N=max(N, num[i]);
	int dp[N+1];
	dp[0]=1;dp[1]=1;dp[2]=5;
	for(int i=3;i<=N;++i){
		dp[i]=dp[i-1]+dp[i-2]*4;
		for(int j=3;j<=i;++j){
			if(j&1)	dp[i]+=dp[i-j]*2;
			else	dp[i]+=dp[i-j]*3;
		}
	}
	for(int i=0;i<T;++i)	cout<<dp[num[i]]<<"\n";
	return 0;
}
