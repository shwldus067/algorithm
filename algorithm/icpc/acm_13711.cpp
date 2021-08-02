#include<iostream>
#include<algorithm>
#define inf 1000000
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, tp, A[100001], B[100001], C[100001], dp[100001]={0, };
	cin>>N;
	for(int i=1;i<=N;++i)	cin>>A[i];
	for(int i=1;i<=N;++i){
		cin>>tp;
		B[tp]=i;
	}
	for(int i=1;i<=N;++i)	C[i]=B[A[i]];
	dp[0]=-1;dp[1]=C[1];
	int cnt=1;
	for(int i=1;i<=N;++i){
		tp=C[i];
		if(dp[cnt]<tp){
			dp[++cnt]=tp;
		}else{
			int *iter=lower_bound(dp, dp+cnt+1, tp);
			*iter=tp;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
