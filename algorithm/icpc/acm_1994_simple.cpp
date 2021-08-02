#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int arr[2000];
int d[2000][2000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	if(N==1){
		cout<<"1\n";
		return 0;
	}
	sort(arr, arr+N);
	int ans=0;
	for(int i=N-2;i>=0;--i){
		int k=0;
		for(int j=i+1;j<N;++j){
			k=max(k, j+1);
			while(k<N && arr[k]<arr[j]*2-arr[i])	++k;
			if(k<N && arr[k]==arr[j]*2-arr[i])
				d[i][j]=d[j][k]+1;
			ans=max(ans, d[i][j]);
		}
	}
	cout<<ans+2<<"\n";
	return 0;
}
