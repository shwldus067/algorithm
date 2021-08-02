#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int A[N], B[N], ans=0, last;
	
	for(int i=0;i<N;i++){
		cin>>A[i];
		B[i]=1;
		for(int j=0;j<i;j++){
			if(A[j]<A[i] && B[i]<B[j]+1){
				B[i]=B[j]+1;
			}
		}
		if(ans<B[i]){
			ans=B[i];
			last=i;
		}
	}
	cout<<ans<<"\n";
	int print[ans], cur=ans;
	for(int i=last,j=0;i>=0 && j<ans;i--){
		if(B[i]==cur){
			print[ans-1-j]=A[i];
			j++;
			cur--;
		}
	}
	for(int i=0;i<ans;i++)	cout<<print[i]<<" ";
	cout<<"\n";
	return 0;
}
