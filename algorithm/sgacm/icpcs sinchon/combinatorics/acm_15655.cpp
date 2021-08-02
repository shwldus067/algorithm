#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int arr[8];
int ans[8];
void sol(int n, int k){
	if(n==M){
		for(int i=0;i<M;++i){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=k+1;i<N;++i){
		ans[n]=arr[i];
		sol(n+1, i);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	sort(arr, arr+N);
	sol(0, -1);
	return 0;
}
