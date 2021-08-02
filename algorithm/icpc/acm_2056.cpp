#include<iostream>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, T[10000], n, k, dp[10000], ans=0;
	vector<int> nx[10000];
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>T[i]>>n;
		if(!n)	dp[i]=T[i];
		else	dp[i]=0;
		while(n--){
			cin>>k;
			nx[k-1].push_back(i);
		}
	}
	for(int i=0;i<N;++i){
		for(int nxt:nx[i]){
			dp[nxt]=max(dp[nxt], dp[i]+T[nxt]);
		}
		ans=max(ans, dp[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
