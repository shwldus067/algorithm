#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N, M, Z[1000000], l, r;
char S[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>S;
	N=strlen(S);
	reverse(S, S+N);
	cin>>M;
	Z[l]=N;
	for(int i=1;i<N;++i){
		if(i>r){
			l=r=i;
			while(S[r]==S[r-l])	++r;
			Z[i]=r-l;
			r--;
		}
		else{
			if(Z[i-l]<=r-i)	Z[i]=Z[i-l];
			else{
				l=i;
				while(S[r]==S[r-l])	++r;
				Z[i]=r-l;
				r--;
			}
		}
	}
	while(M--){
		int x;
		cin>>x;
		cout<<Z[N-x]<<"\n";
	}
	return 0;
}
