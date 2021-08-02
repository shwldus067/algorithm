#include<iostream>
#include<cstring>
using namespace std;
bool pl[2000][2000];
int dp[2000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char str[2010];
	cin>>str;
	int n=strlen(str);
	fill(dp, dp+n, n);
	for(int d=0;d<n;++d){
		for(int l=0, r;(r=l+d)<n;++l){
			if(d==0)	pl[l][r]=1;
			else if(d==1){
				if(str[l]==str[r])	pl[l][r]=1;
			}else{
				if(str[l]==str[r] && pl[l+1][r-1]){
					pl[l][r]=1;
				}
			}
		}
	}
	for(int r=0;r<n;++r){
		for(int l=r;l>=0;--l){
			if(l==0 && pl[0][r])	dp[r]=1;
			else if(pl[l][r]){
				dp[r]=min(dp[r], dp[l-1]+1);
			}
		}
	}
	cout<<dp[n-1]<<"\n";
	return 0;
}
