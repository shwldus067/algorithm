#include<iostream>
using namespace std;
int N;
char str[1024*3][1024*6];
void sol(int n){
	if(n==3){
		str[0][N-1]='*';
		str[1][N-2]=str[1][N]='*';
		for(int i=N-3;i<=N+1;i++)	str[2][i]='*';
		return;
	}
	sol(n/2);
	int h=n/2;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			str[h+i][N-n+j]=str[h+i][N+j]=str[i][N-h+j];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	fill(&str[0][0], &str[N-1][N*2], ' ');
	sol(N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N*2;j++)	cout<<str[i][j];
			cout<<"\n";
	}
	return 0;
}
