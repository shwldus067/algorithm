#include<iostream>
using namespace std;
char arr[751][752];
short dp[2][752][752];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	short R, C;
	cin>>R>>C;
	for(int i=1;i<=R;++i)	cin>>arr[i]+1;
	for(short i=R;i>0;--i){
		for(short j=1;j<=C;++j){
			if(arr[i][j]=='1'){
				dp[0][i][j]=dp[0][i+1][j-1]+1;
				dp[1][i][j]=dp[1][i+1][j+1]+1;
			}
		}
	}
	int ans=0;
	for(short i=1;i<=R;++i){
		for(short j=1;j<=C;++j){
			short m=min(dp[0][i][j], dp[1][i][j])-1;
			while(m+1>ans){
				if(min(dp[1][i+m][j-m], dp[0][i+m][j+m])>m){
					ans=m+1;break;
				}
				--m;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
