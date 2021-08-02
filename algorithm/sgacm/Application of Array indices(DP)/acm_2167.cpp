#include<iostream>
using namespace std;
int N, M, K, i, j, x, y;
int A[301][301], sum[301][301];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	for(int n=1;n<=N;n++){
		for(int m=1;m<=M;m++){
			cin>>A[n][m];
		}
	}
	cin>>K;
	for(int r=1;r<=N;r++){
		for(int c=1;c<=M;c++){
			sum[r][c]=sum[r-1][c]+sum[r][c-1]-sum[r-1][c-1]+A[r][c];
		}
	}
	for(int k=0;k<K;k++){
		cin>>i>>j>>x>>y;
		cout<<sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1]<<"\n";
	}
	return 0;
}
