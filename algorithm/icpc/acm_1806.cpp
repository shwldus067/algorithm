#include<iostream>
using namespace std;
int N, S;
int A[100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>S;
	for(int i=0;i<N;i++)	cin>>A[i];
	int sum=0, s, e=0, res=(1<<31)-1;
	for(s=0;s<N;s++){
		while(sum<S && e<N){
			sum+=A[e++];
		}
		if(sum>=S)	res=res<e-s ? res:e-s;
		sum-=A[s];
	}
	if(res==((1<<31)-1))	cout<<0<<"\n";
	else	cout<<res<<"\n";
	return 0;
}
