#include<iostream>
using namespace std;
int A[250000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, Q, x, y;
	cin>>N>>Q;
	for(int i=0;i<N;++i)	cin>>A[i];
	while(Q--){
		cin>>x>>y;
		int l=0, r=N-1;
		while(l<r){
			int m=(l+r+1)/2;
			if(A[m]<x)	r=m-1;
			else	l=m;
		}
		cout<<(l+1>y?l-y+1:0)+(A[y-1]+1>x?A[y-1]-x+1:0)<<"\n";
	}
	return 0;
}
