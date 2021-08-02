#include<iostream>
using namespace std;
int S, N, K, R1, R2, C1, C2;
int pow[11];
int sol(int s, int r, int c){
	if(s==0)	return 0;
	int tmp=(N-K)/2, p=pow[s-1];
	if(tmp*p<=r && r<(tmp+K)*p && tmp*p<=c && c<(tmp+K)*p)
		return 1;
	r%=p, c%=p;
	return sol(s-1, r, c);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>S>>N>>K>>R1>>R2>>C1>>C2;
	pow[0]=1;
	for(int i=1;i<=S;++i)	pow[i]=pow[i-1]*N;
	for(int i=R1;i<=R2;++i){
		for(int j=C1;j<=C2;++j){
			cout<<sol(S, i, j);
		}
		cout<<"\n";
	}
	return 0;
}
