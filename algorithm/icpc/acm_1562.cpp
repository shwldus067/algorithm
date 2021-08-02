#include<cstdio>
#include<cstring>
#define mod 1000000000
int main(){
	int N, d[2][10][4]={0, }, t=1, p=0;
	scanf("%d", &N);
	for(int i=0;i<10;++i){
		if(i==0)	d[0][i][1]=1;
		else if(i==9)	d[0][i][2]=1;
		else	d[0][i][0]=1;
	}
	for(int i=1;i<N;++i){
		for(int j=0;j<10;++j){
			for(int k=0;k<4;++k){
				if(j==0)	d[t][j][k|1]=(d[t][j][k|1]+d[p][j+1][k])%mod;
				else if(j==9)	d[t][j][k|2]=(d[t][j][k|2]+d[p][j-1][k])%mod;
				else	d[t][j][k]=(d[t][j][k]+d[p][j-1][k]+d[p][j+1][k])%mod;
			}
		}
		memset(&d[p][0][0], 0, 40*sizeof(int));
		t^=1, p^=1;
	}
	int ans=0;
	for(int i=1;i<10;++i)	ans=(ans+d[p][i][3])%mod;
	printf("%d", ans);
	return 0;
}
