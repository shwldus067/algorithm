#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int kids[N], lcs[N+1][N+1];
	for(int i=0;i<N;i++){
		cin>>kids[i];
	}
	for(int i=0;i<=N;i++){
		lcs[0][i]=0;
		lcs[i][0]=0;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(kids[i-1]==j){
				lcs[i][j]=lcs[i-1][j-1]+1;
			}
			else{
				lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	cout<<N-lcs[N][N]<<"\n";
}
