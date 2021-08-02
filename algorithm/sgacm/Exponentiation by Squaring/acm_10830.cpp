#include<iostream>
#include<vector>
using namespace std;
const int mod=1000;
typedef vector<vector<int> > matrix;
matrix operator*(const matrix &a, const matrix &b){
	int N=a.size();
	matrix c(N, vector<int>(N, 0));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=mod;
			}
		}
	}
	return c;
}
matrix pow(matrix &a, long long b){
	int n=a.size();
	matrix res(n, vector<int>(n));
	for(int i=0;i<n;i++)	res[i][i]=1;
	while(b){
		if(b&1){
			res=res*a;
		}
		a=a*a;
		b>>=1;
	}
	return res;
}
int main(){
	int N;
	long long b;
	cin>>N>>b;
	matrix a(N, vector<int>(N));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>a[i][j];
		}
	}
	a=pow(a, b);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
