#include<cstdio>
#include<vector>
using namespace std;
typedef vector<vector<long long> > matrix;
const int mod=1000000007;
matrix operator*(const matrix &a, const matrix &b){
	int n=a.size();
	matrix c(n, vector<long long>(n, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=mod;
			}
		}
	}
	return c;
}
int main(){
	int N, M, D, a, b;
	scanf("%d %d", &N, &M);
	matrix c(N, vector<long long>(N, 0));
	for(int i=0;i<M;i++){
		scanf("%d %d", &a, &b);
		c[a-1][b-1]=1;
		c[b-1][a-1]=1;
	}
	scanf("%d", &D);
	matrix res(N, vector<long long>(N, 0));
	for(int i=0;i<N;i++)	res[i][i]=1;
	while(D){
		if(D&1){
			res=res*c;
		}
		c=c*c;
		D>>=1;
	}
	printf("%d\n", res[0][0]);
	return 0;
}
