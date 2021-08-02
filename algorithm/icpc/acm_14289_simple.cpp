#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
int N;
ll c[50][50], res[50][50];
void mul(ll a[][50], ll b[][50]){
	ll tmp[50][50];
	for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		ll x=0;
		for(int k=0;k<N;k++)	x=(x+a[i][k]*b[k][j])%mod;
		tmp[i][j]=x;
	}
	memcpy(a, tmp, sizeof(tmp));
}
int main(){
	int M, D, a, b;
	scanf("%d %d", &N, &M);
	for(int i=0;i<M;i++){
		scanf("%d %d", &a, &b);
		a--;b--;
		c[a][b]=1;
		c[b][a]=1;
	}
	scanf("%d", &D);
	for(int i=0;i<N;i++)	res[i][i]=1;
	while(D){
		if(D&1)	mul(res, c);
		mul(c, c);
		D>>=1;
	}
	printf("%lld\n", res[0][0]);
	return 0;
}
