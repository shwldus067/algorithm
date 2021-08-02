#include<iostream>
using namespace std;
typedef long long ll;
int N, R, G, B;
ll dp[11][101][101][101];
int f[11]={1, };
ll func(int l, int r, int g, int b){
	if(r<0 || g<0 || b<0)	return 0;
	if(l==0)	return 1;
	if(dp[l][r][g][b])	return dp[l][r][g][b];
	dp[l][r][g][b]+=func(l-1, r-l, g, b);
	dp[l][r][g][b]+=func(l-1, r, g-l, b);
	dp[l][r][g][b]+=func(l-1, r, g, b-l);
	int comb, k;
	if(!(l&1)){
		k=l/2;
		comb=f[l]/(f[k]*f[k]);
		dp[l][r][g][b]+=comb*func(l-1, r-k, g-k, b);
		dp[l][r][g][b]+=comb*func(l-1, r-k, g, b-k);
		dp[l][r][g][b]+=comb*func(l-1, r, g-k, b-k);
	}
	if(l%3==0){
		k=l/3;
		comb=f[l]/(f[k]*f[k]*f[k]);
		dp[l][r][g][b]+=comb*func(l-1, r-k, g-k, b-k);
	}
	return dp[l][r][g][b];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>R>>G>>B;
	for(int i=1;i<11;i++){
		f[i]=f[i-1]*i;
	}
	cout<<func(N, R, G, B)<<"\n";
	return 0;
}
