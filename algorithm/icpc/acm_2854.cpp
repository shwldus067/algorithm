#include<iostream>
using namespace std;
#define mod 1000000007
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned int N, num[100000], numor[100001], dp[100000][3]={0, };
	cin>>N;
	for(int i=0;i<N;++i)	cin>>num[i];	//i
	for(int i=1;i<N;++i)	cin>>numor[i];	//i-1 or i
	dp[0][0]=num[0];
	dp[0][2]=numor[1];
	for(int i=1;i<N;++i){
		if(num[i]){
			dp[i][0]=1ul*num[i]*((dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod)%mod;
		}
		if(numor[i]){
			dp[i][1]=1ul*numor[i]*((dp[i-1][0]+dp[i-1][1])%mod)%mod;
			dp[i][1]=(dp[i][1]+1ul*(numor[i]-1)*dp[i-1][2]%mod)%mod;
		}
		if(numor[i+1]){
			dp[i][2]=1ul*numor[i+1]*((dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod)%mod;
		}
	}
	cout<<(dp[N-1][0]+dp[N-1][1])%mod<<"\n";
	return 0;
}
