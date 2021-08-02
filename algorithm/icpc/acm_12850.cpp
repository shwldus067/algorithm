#include<iostream>
using namespace std;
const int mod=1000000007;
int D;
long long adj[8][8]={{0, 1, 1, 0, 0, 0, 0, 0},
					{1, 0, 1, 1, 0, 0, 0 ,0},
					{1, 1, 0, 1, 1, 0, 0, 0},
					{0, 1, 1, 0, 1, 1, 0, 0},
					{0, 0, 1, 1, 0, 1, 0, 1},
					{0, 0, 0, 1, 1, 0, 1, 0},
					{0, 0, 0, 0, 0, 1, 0, 1},
					{0, 0, 0, 0, 1, 0, 1, 0}};
long long tmp[8][8], res[8][8];
void mul(long long a[8][8], long long b[8][8]){
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			tmp[i][j]=0;
			for(int k=0;k<8;++k){
				tmp[i][j]+=a[i][k]*b[k][j];
				tmp[i][j]%=mod;
			}
		}
	}
	copy(&tmp[0][0], &tmp[7][8], &a[0][0]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>D;
	for(int i=0;i<8;++i)	res[i][i]=1;
	while(D){
		if(D&1)	mul(res, adj);
		mul(adj, adj);
		D>>=1;
	}
	cout<<res[0][0]<<"\n";
	return 0;
}
