#include<iostream>
using namespace std;
int N, M, A[100][100], B[100][100];
int nn, mm;
void sol1(){
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			B[N-1-j][i]=A[j][i];
		}
	}
	nn=N, mm=M;
}
void sol2(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			B[i][M-1-j]=A[i][j];
		}
	}
	nn=N, mm=M;
}
void sol3(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			B[j][N-1-i]=A[i][j];
		}
	}
	nn=M, mm=N;
}
void sol4(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			B[M-1-j][i]=A[i][j];
		}
	}
	nn=M, mm=N;
}
void sol5(){
	int n=N/2, m=M/2;
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)	B[i][m+j]=A[i][j];
	for(int i=0;i<n;++i)for(int j=m;j<M;++j)	B[n+i][j]=A[i][j];
	for(int i=n;i<N;++i)for(int j=m;j<M;++j)	B[i][j-m]=A[i][j];
	for(int i=n;i<N;++i)for(int j=0;j<m;++j)	B[i-n][j]=A[i][j];
	nn=N, mm=M;
}
void sol6(){
	int n=N/2, m=M/2;
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)	B[i+n][j]=A[i][j];
	for(int i=0;i<n;++i)for(int j=m;j<M;++j)	B[i][j-m]=A[i][j];
	for(int i=n;i<N;++i)for(int j=m;j<M;++j)	B[i-n][j]=A[i][j];
	for(int i=n;i<N;++i)for(int j=0;j<m;++j)	B[i][j+m]=A[i][j];
	nn=N, mm=M;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int R, K;
	cin>>N>>M>>R;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)	cin>>A[i][j];
	while(R--){
		cin>>K;
		switch(K){
			case 1:
				sol1();break;
			case 2:
				sol2();break;
			case 3:
				sol3();break;
			case 4:
				sol4();break;
			case 5:
				sol5();break;
			case 6:
				sol6();break;
			default:
				break;
		}
		for(int i=0;i<nn;++i)for(int j=0;j<mm;++j)	A[i][j]=B[i][j];
		N=nn, M=mm;
	}
	for(int i=0;i<nn;++i){
		for(int j=0;j<mm;++j)	cout<<B[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
