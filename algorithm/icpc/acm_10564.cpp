#include<iostream>
using namespace std;
int score[10];
int T, N, M, t, p;
bool dp[5001][5001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>M;
		fill(&dp[0][0], &dp[5000][5001], false);
		for(int i=0;i<M;i++){
			cin>>score[i];
			dp[score[i]][score[i]]=true;
		}
		for(int i=1;i<N;i++){
			for(int k=1;k<N;k++){
				if(!dp[i][k])	continue;
				for(int j=0;j<M;j++){
					t=i+score[j]+k;
					if(t>N)	continue;
					p=score[j]+k;
					dp[t][p]=true;
				}
			}
		}
		for(p=N;p>0;p--){
			if(dp[N][p]){
				cout<<p<<"\n";
				break;
			}
		}
		if(p==0)	cout<<-1<<"\n";
	}
	return 0;
}
