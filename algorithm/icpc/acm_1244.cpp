#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, A[101], M, s, n;
	cin>>N;
	for(int i=1;i<=N;++i)	cin>>A[i];
	cin>>M;
	while(M--){
		cin>>s>>n;
		if(s==1){
			for(int i=n;i<=N;i+=n){
				if(A[i]==0)	A[i]=1;
				else	A[i]=0;
			}
		}else{
			int k=0;
			for(int i=1;n-i>0 && n+i<=N;++i){
				if(A[n-i]!=A[n+i]){
					k=i;
					break;
				}
			}
			if(k==0)	k=min(N-n+1, n);
			--k;
			for(int i=n-k;i<=n+k;++i){
				if(A[i]==0)	A[i]=1;
				else	A[i]=0;
			}
		}
	}
	for(int i=1;i<=N;++i){
		cout<<A[i]<<" ";
		if(i%20==0)	cout<<"\n";
	}
	return 0;
}
