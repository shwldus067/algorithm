#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int arr[N], d[N];
	for(int i=0;i<N;++i)	cin>>arr[i];
	int res=0;
	for(int i=0;i<N;++i){
		int max_l=0;
		for(int j=0;j<i;++j){
			if(arr[j]<arr[i]){
				max_l=max(max_l, d[j]);
			}
		}
		d[i]=max_l+1;
		res=max(d[i], res);
	}
	cout<<res<<"\n";
	return 0;
}
