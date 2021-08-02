#include<iostream>
using namespace std;
const int inf=16*10000000;
int dp[1<<16][16];
int N;
int W[16][16];
int main(){
	ios::sync_with_stdio(false);
	int i, j, v;
	cin>>N;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cin>>W[i][j];
		}
	}
	fill(&dp[0][0], &dp[(1<<16)-1][16], inf);
	dp[1][0]=0;
	for(v=0;v<(1<<N);v++){
		for(j=0;j<N;j++){
			if(v&(1<<j))	continue;
			int v2=v|(1<<j);
			for(i=0;i<N;i++){
				if(!(v&(1<<i)))	continue;
				if(!W[i][j])	continue;
				dp[v2][j]=min(dp[v][i]+W[i][j], dp[v2][j]);
			}
		}
	}
	int last=(1<<N)-1;
	int Min=inf;
	for(i=0;i<N;i++){
		int t=dp[last][i]+W[i][0];
		if(W[i][0])	Min=Min<t ? Min:t;
	}
	cout<<Min<<"\n";
	return 0;
}
