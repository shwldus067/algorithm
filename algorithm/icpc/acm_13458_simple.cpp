#include<iostream>
using namespace std;
int A[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, B, C, m=1e7, M=0;
	long long ans;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>B;
		A[B]++;
		if(m>B)	m=B;
		if(M<B)	M=B;
	}
	cin>>B>>C;
	++M;
	ans=N;
	for(int i=m;i<M;++i){
		if(!A[i])	continue;
		m=i-B;
		if(m>0)	ans+=1ll*(1+(m-1)/C)*A[i];
	}
	cout<<ans<<"\n";
	return 0;
}
