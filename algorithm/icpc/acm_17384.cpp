#include<iostream>
#include<cmath>
using namespace std;
int N;
void sol(int s, int e, int n){
	if(s==e){
		if(n)	cout<<"#";
		else	cout<<".";
		return ;
	}
	int l=e-s+1, m=(s+e)>>1;
	if(n<=l/2){
		sol(s, m, n);
		sol(m+1, e, 0);
	}
	else{
		int x=1;
		while(x*2<=n-x*2 && x*2<=e-m)	x<<=1;
		if(n-x>m-s+1)	x=n-(m-s+1);
		sol(s, m, n-x);
		sol(m+1, e, x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int s=1;
	for(;s<N;s<<=1);
	sol(1, s, N);
	return 0;
}
