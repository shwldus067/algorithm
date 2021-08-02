#include<iostream>
using namespace std;
int  main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	int A[N], B[N], C[N], ans=0;
	for(int i=0;i<N;i++)	cin>>A[i];
	for(int i=0;i<N;i++){
		B[i]=1;
		for(int j=0;j<i;j++){
			if(A[j]<A[i] && B[i]<B[j]+1){
				B[i]=B[j]+1;
			}
		}
	}
	for(int i=N-1;i>=0;i--){
		C[i]=1;
		for(int j=N-1;j>i;j--){
			if(A[j]<A[i] && C[i]<C[j]+1){
				C[i]=C[j]+1;
			}
		}
		B[i]+=C[i]-1;
		if(ans<B[i]){
			ans=B[i];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
