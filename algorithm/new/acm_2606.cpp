#include<iostream>
using namespace std;

int main(){
	int N, net, cnt=0, n, m;
	cin>>N>>net;
	bool virus[N+1][N+1];
	fill(&virus[0][0], &virus[N][N+1], false);
	for(int i=0;i<net;i++){
		cin>>n>>m;
		virus[n][m]=true;
		virus[m][n]=true;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				virus[j][k]=virus[j][k] || (virus[j][i]&&virus[i][k]);
			}
		}
	}
	for(int i=2;i<=N;i++){
		if(virus[1][i])	cnt++;
	}
	cout<<cnt;
}
