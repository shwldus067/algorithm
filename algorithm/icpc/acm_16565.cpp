#include<cstdio>
const int mod=10007;
int N, c[53][53]={1, };
int main(){
	for(int i=1;i<53;++i){
		c[i][0]=1;
		for(int j=1;j<i;++j){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
		c[i][i]=1;
	}
	scanf("%d", &N);
	int ans=0;
	for(int i=1;i<=N/4;++i){
		if(i&1){
			ans=(ans+c[13][i]*c[52-i*4][N-i*4]%mod)%mod;
		}
		else{
			ans=(ans-c[13][i]*c[52-i*4][N-i*4]%mod)%mod;
		}
	}
	if(ans<0)	ans+=mod;
	printf("%d\n", ans);
	return 0;
}
