#include<iostream>
using namespace std;
int N;
char A[100001], B[100001], C[100001];
void sol(int n, int c){
	if(n==N-1){
		if(C[n]==B[n] && C[n-1]==B[n-1]){
			cout<<c<<"\n";
			exit(0);
		}else if(C[n]!=B[n] && C[n-1]!=B[n-1]){
			cout<<c+1<<"\n";
			exit(0);
		}
		return;
	}
	if(n>1){
		if(C[n-2]!=B[n-2])	return;
	}
	if(n){
		if(C[n-1]==B[n-1])	sol(n+1, c);
		else{
			C[n-1]=C[n-1]=='1'?'0':'1';
			C[n]=C[n]=='1'?'0':'1';
			C[n+1]=C[n+1]=='1'?'0':'1';
			sol(n+1, c+1);
			C[n-1]=C[n-1]=='1'?'0':'1';
			C[n]=C[n]=='1'?'0':'1';
			C[n+1]=C[n+1]=='1'?'0':'1';
		}
	}
	else{
		sol(n+1, c);
		C[0]=C[0]=='1'?'0':'1';
		C[1]=C[1]=='1'?'0':'1';
		sol(n+1, c+1);
		C[0]=C[0]=='1'?'0':'1';
		C[1]=C[1]=='1'?'0':'1';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>A>>B;
	for(int i=0;i<N;++i)	C[i]=A[i];
	sol(0, 0);
	cout<<"-1\n";
	return 0;
}
