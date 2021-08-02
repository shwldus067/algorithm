#include<iostream>
using namespace std;
int dp[2][800][800];
int R, C, ans;
char arr[800][800];
void fill(int r, int c, int d){
	int t=0, dr, dc;
	if(d)	dr=-1, dc=-1;
	else	dr=-1, dc=1;
	while(r>=0 && c>=0){
		if(arr[r][c]=='1')	++t;
		else	t=0;
		dp[d][r][c]=t;
		r+=dr, c+=dc;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	for(int i=0;i<R;++i)	cin>>arr[i];
	for(int i=0;i<R;++i){
		fill(i, 0, 0);fill(i, 0, 1);
		fill(i, C-1, 0);fill(i, C-1, 1);
	}
	for(int i=1;i<C-1;++i){
		fill(R-1, i, 0);fill(R-1, i, 1);
	}
	int m;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			if(arr[i][j]=='0')	continue;
			m=min(dp[0][i][j], dp[1][i][j])-1;
			while(m+1>ans){
				if(dp[1][i+m][j-m]>m && dp[0][i+m][j+m]>m){
					ans=max(ans, m+1);
					break;
				}
				--m;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
