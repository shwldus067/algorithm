#include<iostream>
using namespace std;
int f[1000000];
char a[1000001], b[2000001];
int gcd(int a, int b){
	int t;
	while(b){
		t=a%b;a=b;b=t;
	}
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K=0;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>a[i];
	for(int i=0;i<N;++i)	cin>>b[i];
	for(int i=0;i<N;++i)	b[i+N]=b[i];
	M=N+N-1;
	for(int i=1, j=0;i<N;++i){
		while(j && a[i]!=a[j])	j=f[j-1];
		if(a[i]==a[j])	f[i]=++j;
	}
	for(int i=0, j=0;i<M;++i){
		while(j && b[i]!=a[j])	j=f[j-1];
		if(b[i]==a[j])	++j;
		if(j==N){
			++K;
		}
	}
	int G=gcd(N, K);
	cout<<K/G<<'/'<<N/G<<"\n";
	return 0;
}
