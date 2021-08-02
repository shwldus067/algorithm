#include<iostream>
using namespace std;
int T, N;
long long dp[20][20][2];
long long cnt;
long long dfs(int l, int s, int flag){
	int n=l+s;
	if(n==0)	return 1;
	long long &ret=dp[l][s][flag];
	if(ret!=-1)	return ret;
	ret=0;
	if(!flag){
		for(int i=0;i<s;i++){
			ret+=dfs(n-i-1, i, 1);
		}
	}
	else{
		for(int i=0;i<l;i++){
			ret+=dfs(i, n-i-1, 0);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	fill(&dp[0][0][0], &dp[19][19][2], -1);
	while(T--){
		cin>>N;
		if(N==1){
			cout<<"1\n";
			continue;
		}
		cnt=0;
		for(int i=0;i<N;i++){
			cnt+=dfs(i, N-1-i, 0);
			cnt+=dfs(i, N-1-i, 1);
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
