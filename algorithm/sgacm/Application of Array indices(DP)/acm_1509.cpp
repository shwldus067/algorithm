#include<iostream>
#include<string>
using namespace std;
string str;
bool pl[2500][2500];
int dp[2500];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>str;
	int n=str.length();
	fill(&pl[0][0], &pl[n-1][n], false);
	fill(dp, dp+n, (1<<31)-1);
	int d, l, r;
	for(d=0;d<n;d++){
		for(l=0;(r=l+d)<n;l++){
			if(d==0)	pl[l][r]=true;
			else if(d==1){
				if(str[l]==str[r])	pl[l][r]=true;
			}
			else{
				if(str[l]==str[r] && pl[l+1][r-1])
					pl[l][r]=true;
			}
		}
	}
	for(r=0;r<n;r++){
		for(l=r;l>=0;l--){
			if(l==0 && pl[0][r])
				dp[r]=1;
			else if(pl[l][r])
				dp[r]=min(dp[r], dp[l-1]+1);
		}
	}
	cout<<dp[n-1]<<"\n";
	return 0;
}
