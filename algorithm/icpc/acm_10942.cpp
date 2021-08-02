#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, S, E;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++)	cin>>A[i];
	bool dp[N][N];
	fill(&dp[0][0], &dp[N-1][N], false);
	for(int i=0;i<N;i++)	dp[i][i]=true;
	for(int d=1;d<N;d++){
		for(int i=0;i+d<N;i++){
			if(A[i]==A[i+d]){
				if(i+1>i+d-1){
					dp[i][i+d]=true;
				}
				else{
					dp[i][i+d]=(dp[i+1][i+d-1]&true);
				}
			}
		}
	}
	
	cin>>M;
	while(M--){
		cin>>S>>E;
		if(dp[S-1][E-1])	cout<<1<<"\n";
		else	cout<<0<<"\n";
	}
	return 0;
}
