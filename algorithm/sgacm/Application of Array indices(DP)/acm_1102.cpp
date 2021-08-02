#include<iostream>
using namespace std;
int N, P;
int cost[16][16];
int dp[1<<16];
int f(int s, int c){
	if(c>=P)	return 0;
	int m=1000, t, tp;
	int &val=dp[s];
	if(val!=1000)	return val;
	for(int i=0;i<N;i++){
		if(s&(1<<i)){
			for(int j=0;j<N;j++){
				if(!(s&(1<<j))){
					tp=f(s|(1<<j), c+1)+cost[i][j];
					val=val<tp ? val:tp;
				}
			}
		}
	}
	return val;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>cost[i][j];
		}
	}
	char c;
	int state=0, cnt=0;
	for(int i=0;i<N;i++){
		cin>>c;
		if(c=='Y'){
			state|=(1<<i);
			cnt++;
		}
	}
	cin>>P;
	fill(dp, dp+(1<<16), 1000);
	int ans=f(state, cnt);
	if(ans>=1000)	ans=-1;
	cout<<ans<<"\n";
	return 0;
}
