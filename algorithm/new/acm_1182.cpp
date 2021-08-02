#include<iostream>
using namespace std;
int N, S, cnt;
int arr[20];
int f(int x, int sum, int cnt){
	if(x==N){
		if(sum==S && cnt!=0)	return 1;
		return 0;
	}
	return f(x+1, sum+arr[x], cnt+1)+f(x+1, sum, cnt);
}
int main(){
	cin>>N>>S;
	for(int i=0;i<N;i++)	cin>>arr[i];
	cout<<f(0, 0, 0)<<"\n";
	return 0;
}
