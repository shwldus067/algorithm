#include<iostream>
using namespace std;
int N, arr[1005], d[1005][1005][205];
int sol(int f, int n, int k){
	if(n==0)	return 0;
	if(d[f][n][k+100]!=-1)	return d[f][n][k+100];
	if(k<=0){
		d[f][n][k+100]=max(sol((f+1)%N, n-1, k+arr[f])+arr[f], sol(f, n-1, k+arr[(f+n-1)%N])+arr[(f+n-1)%N]);
	}
	else{
		d[f][n][k+100]=min(sol((f+1)%N, n-1, k-arr[f]), sol(f, n-1, k-arr[(f+n-1)%N]));
	}
	return d[f][n][k+100];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	int ans=0, t;
	fill(&d[0][0][0], &d[1004][1004][205], -1);
	for(int i=0;i<N;++i){
		t=sol((i+1)%N, N-1, arr[i])+arr[i];
		if(ans<t)	ans=t;
	}
	cout<<ans<<"\n";
	return 0;
}
