#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, arr[10000];
	bool chk[10001];
	cin>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	chk[arr[N-1]]=1;
	for(int i=N-1;i>0;--i){
		chk[arr[i-1]]=1;
		if(arr[i-1]>arr[i]){
			for(int j=0;j<i-1;++j)	cout<<arr[j]<<" ";
			for(int j=arr[i-1]-1;j>0;--j){
				if(chk[j]){
					cout<<j<<" ";
					chk[j]=0;
					break;
				}
			}
			for(int j=N;j;--j){
				if(chk[j])	cout<<j<<" ";
			}
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}
