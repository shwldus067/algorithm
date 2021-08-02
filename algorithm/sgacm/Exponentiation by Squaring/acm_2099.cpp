#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<bool> > matrix;
matrix operator*(const matrix &a, const matrix &b){
	int n=a.size();
	matrix c(n, vector<bool>(n, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(a[i][k] && b[k][j]){
					c[i][j]=true;
					break;
				}
			}
		}
	}
	return c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K, M, a, b;
	cin>>N>>K>>M;
	matrix c(N, vector<bool>(N, 0));
	for(int i=0;i<N;i++){
		cin>>a>>b;
		c[i][a-1]=1;
		c[i][b-1]=1;
	}
	matrix res(N, vector<bool>(N, 0));
	for(int i=0;i<N;i++)	res[i][i]=1;
	while(K){
		if(K&1){
			res=res*c;
		}
		c=c*c;
		K>>=1;
	}
	for(int i=0;i<M;i++){
		cin>>a>>b;
		if(!res[a-1][b-1]){
			cout<<"life\n";
		}
		else{
			cout<<"death\n";
		}
	}
	return 0;
}
