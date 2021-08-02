#include<iostream>
using namespace std;
typedef long long ll;
int N, R, G, B;
int f[11]={1, };
ll dp[11][56][56];
ll func(int l, int r, int g, int b){
	if(r<0 || g<0 || b<0)	return 0;
	if(l==N+1)	return 1;
	if(dp[l][r][g])	return dp[l][r][g];
	dp[l][r][g]+=func(l+1, r-l, g, b);
	dp[l][r][g]+=func(l+1, r, g-l, b);
	dp[l][r][g]+=func(l+1, r, g, b-l);
	int comb, k;
	if(!(l&1)){
		k=l/2;
		comb=f[l]/(f[k]*f[k]);
		dp[l][r][g]+=comb*func(l+1, r-k, g-k, b);
		dp[l][r][g]+=comb*func(l+1, r-k, g, b-k);
		dp[l][r][g]+=comb*func(l+1, r, g-k, b-k);
	}
	if(l%3==0){
		k=l/3;
		comb=f[l]/(f[k]*f[k]*f[k]);
		dp[l][r][g]+=comb*func(l+1, r-k, g-k, b-k);
	}
	return dp[l][r][g];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>R>>G>>B;
	for(int i=1;i<11;i++){
		f[i]=f[i-1]*i;
	}
	R=min(R, 55);
	G=min(G, 55);
	B=min(B, 55);
	cout<<func(1, R, G, B)<<"\n";
	return 0;
}
