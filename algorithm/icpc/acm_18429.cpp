#include<iostream>
using namespace std;
int K, N, A[8], B[8], cnt=0;
bool chk[8];
void sol(int n){
	if(n==N){
		int cur=0;
		for(int i=0;i<N;++i){
			if(cur+A[B[i]]-K<0)	break;
			if(i==N-1)	cnt++;
			cur+=A[B[i]]-K;
		}
		return;
	}
	for(int i=0;i<N;++i){
		if(chk[i])	continue;
		chk[i]=1;
		B[n]=i;
		sol(n+1);
		chk[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;++i)	cin>>A[i];
	sol(0);
	cout<<cnt<<"\n";
	return 0;
}
