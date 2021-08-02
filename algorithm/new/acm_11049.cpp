#include<iostream>
using namespace std;
const int MAX=(1<<31)-1;
int main(){
	int N, r, c, res;
	cin>>N;
	int d[N+1];
	int M[N+1][N+1];
	cin>>d[0]>>d[1];
	for(int n=2;n<=N;n++){
		cin>>r>>d[n];
	}
	for(int i=1;i<=N;i++)	M[i][i]=0;
	for(int l=1;l<N;l++){
		for(int i=1;i<=N-l;i++){
			int j=l+i;
			M[i][j]=MAX;
			for(int k=i;k<j;k++){
				M[i][j]=min(M[i][j], M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j]);
			}
		}
	}
	M[1][1]=d[0]*d[1];
	cout<<M[1][N];
	return 0;
}
