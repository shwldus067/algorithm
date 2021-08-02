#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=2000000000;
int dp[301][301][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, t;
	cin>>n>>m;
	vector<int> pos;
	for(int i=0;i<n;i++){
		cin>>t;
		pos.push_back(t);
	}
	pos.push_back(0);
	sort(pos.begin(), pos.end());
	int s=lower_bound(pos.begin(), pos.end(), 0)-pos.begin();
	int res=0;
	for(int k=1;k<=n;k++){
		fill(&dp[0][0][0], &dp[300][300][2], 0);
		for(int i=s;i>=s-k && i>=0;i--){
			for(int j=s;j<=i+k && j<=n;j++){
				if(i==s && j==s)	continue;
				int rem=k-(j-i)+1;
				dp[i][j][0]=dp[i][j][1]=inf;
				if(i<s){
					dp[i][j][0]=min(dp[i+1][j][0]+rem*(pos[i+1]-pos[i]),
									dp[i+1][j][1]+rem*(pos[j]-pos[i]));
				}
				if(j>s){
					dp[i][j][1]=min(dp[i][j-1][0]+rem*(pos[j]-pos[i]),
									dp[i][j-1][1]+rem*(pos[j]-pos[j-1]));
				}
			}
		}
		int dec=inf;
		for(int i=max(s-k, 0);i<=s && i<=n-k;i++){
			dec=min(dec, dp[i][i+k][0]);
			dec=min(dec, dp[i][i+k][1]);
		}
		int tmp=k*m-dec;
		res=res>tmp ? res:tmp;
	}
	cout<<res<<"\n";
	return 0;
}
