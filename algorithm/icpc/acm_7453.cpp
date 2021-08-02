#include<iostream>
#include<algorithm>
using namespace std;
int N;
long long cnt=0;
int arr[4][4000], sum1[16000000], sum2[16000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[0][i]>>arr[1][i]>>arr[2][i]>>arr[3][i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sum1[i*N+j]=arr[0][i]+arr[1][j];
			sum2[i*N+j]=arr[2][i]+arr[3][j];
		}
	}
	int n=N*N;
	int *a, *b;
	sort(sum2, sum2+n);
	for(int i=0;i<n;i++){
		a=lower_bound(sum2, sum2+n, -sum1[i]);
		b=lower_bound(sum2, sum2+n, -sum1[i]+1);
		cnt+=(b-a);
	}
	cout<<cnt<<"\n";
	return 0;
}
