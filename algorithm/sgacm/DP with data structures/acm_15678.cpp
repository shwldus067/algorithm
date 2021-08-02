#include<iostream>
#include<deque>
using namespace std;
int N, D;
long long dp[100000], mx=-1e18;
deque<int> dq;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>D;
	for(int i=0;i<N;i++){
		if(dq.size() && dq.front()<i-D)
			dq.pop_front();
		cin>>dp[i];
		if(dq.size())
			dp[i]+=max(0ll, dp[dq.front()]);
		mx=max(dp[i], mx);
		while(dq.size() && dp[dq.back()]<=dp[i])
			dq.pop_back();
		dq.push_back(i);
	}
	cout<<mx;
	return 0;
}
