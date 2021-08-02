#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, arr[8];
	cin>>N>>M;
	for(int i=0;i<N;++i)	cin>>arr[i];
	sort(arr, arr+N);
	bool flag=(N!=M);
	do{
		for(int i=0;i<M;++i){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		if(flag)	reverse(arr+M, arr+N);
	}while(next_permutation(arr, arr+N));
	return 0;
}
