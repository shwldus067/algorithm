#include<iostream>
using namespace std;
const int mod=1000000007;
void mul(long long mat1[][2], long long mat2[][2]){
	long long res[2][2]={0, 0, 0, 0};
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				res[i][j]+=mat1[i][k]*mat2[k][j];
				res[i][j]%=mod;
			}
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			mat1[i][j]=res[i][j];
		}
	}
}
void pow(long long mat[][2], long long b){
	long long res[2][2]={1, 0, 0, 1};
	long long tmp[2][2]={1, 1, 1, 0}, tmp1[2][2];
	while(b){
		if(b%2){
			mul(res, tmp);
		}
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				tmp1[i][j]=tmp[i][j];
			}
		}
		mul(tmp, tmp1);
		b>>=1;
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			mat[i][j]=res[i][j];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	long long mat[2][2]={1, 1, 1, 0};
	pow(mat, n);
	cout<<mat[1][0]<<"\n";
	return 0;
}
