#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, arr[8], ans=0, tmp;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	sort(arr, arr+N);
	do{
		tmp=0;
		for(int i=1;i<N;++i){
			tmp+=abs(arr[i-1]-arr[i]);
		}
		if(tmp>ans)	ans=tmp;
	}while(next_permutation(arr, arr+N));
	cout<<ans<<"\n";
	return 0;
}
