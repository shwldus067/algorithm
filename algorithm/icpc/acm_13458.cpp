#include<iostream>
using namespace std;
int A[1000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, B, C;
	long long ans=0;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>A[i];
	cin>>B>>C;
	ans=N;
	for(int i=0;i<N;++i){
		if(A[i]>B) ans+=(A[i]-B-1)/C+1;
	}
	cout<<ans<<"\n";
	return 0;
}
