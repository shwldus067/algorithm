#include<iostream>
using namespace std;
long long gcd(long long a, long long b){
	return b ? gcd(b, a%b):a;
}
int main(){
	int N, M;
	long long t=1, k;
	cin>>N>>M;
	long long p[N+1][N+1];
	p[1][0]=0, p[1][1]=1;
	for(int i=2;i<=N;i++){
		t*=i;
		p[i][0]=0;
		for(int j=1;j<i-1;j++){
			p[i][j]=p[i-1][j-1]+(i-1)*p[i-1][j];
		}
		p[i][i-1]=t-1;
		p[i][i]=t;
	}
	k=gcd(t, p[N][M]);
	cout<<p[N][M]/k<<"/"<<t/k<<"\n";
	return 0;
}
