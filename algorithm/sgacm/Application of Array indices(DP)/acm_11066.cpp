#include<iostream>
using namespace std;
const int inf=(1<<31)-1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin>>T;
	while(T--){
		cin>>n;
		int s[n+1]={0, }, dp[n][n], t;
		for(int i=0;i<n;i++){
			cin>>t;
			s[i+1]=s[i]+t;
		}
		for(int d=0;d<n;d++){
			for(int l=0;l+d<n;l++){
				int r=l+d;
				if(d==0)	dp[l][r]=0;
				else{
					dp[l][r]=inf;
					for(int k=l;k<r;k++){
						dp[l][r]=min(dp[l][r], dp[l][k]+dp[k+1][r]);
					}
					dp[l][r]+=s[r+1]-s[l];
				}
			}
		}
		cout<<dp[0][n-1]<<"\n";
	}
	
}
