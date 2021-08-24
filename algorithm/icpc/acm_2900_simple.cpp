#include<iostream>
using namespace std;
typedef long long ll;
int N, X[1000001];
ll A[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int K, Q, l, r, t;
	cin>>N>>K;
	for(int i=0;i<K;++i){
		cin>>t;
		X[t]++;
	}
	for(int i=1;i<N;++i){
		if(X[i]){
			for(int j=0;j<N;j+=i){
				A[j]+=X[i];
			}
		}
	}
	for(int i=1;i<N;++i)	A[i]+=A[i-1];
	cin>>Q;
	while(Q--){
		cin>>l>>r;
		if(l)	cout<<A[r]-A[l-1]<<"\n";
		else	cout<<A[r]<<"\n";
	}
	return 0;
}
