#include<stdio.h>
inline char min(char a, char b){return a<b?a:b;}
inline int max(int a, int b){return a>b?a:b;}
char dp[1<<14][14];
int main(){
	int N, ans=0;
	char price[15][16];
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%s", &price[i]);
	--N;
	for(int i=1;i<(1<<N);++i)for(int j=0;j<N;++j)	dp[i][j]=10;
	for(int i=0;i<N;++i)	dp[1<<i][i]=price[0][i+1]-'0';
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)
		price[i][j]=price[i+1][j+1]-'0';
	for(int i=1;i<(1<<N);++i){
		for(int j=0;j<N;++j){
			if(dp[i][j]==10)	continue;
			int cnt=N+1;
			for(int k=0;k<N;++k){
				if(i&(1<<k))	continue;
				--cnt;
				if(price[j][k]>=dp[i][j])
					dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k], price[j][k]);
			}
			ans=max(ans, cnt);
		}
	}
	printf("%d\n", ans);
	return 0;
}
