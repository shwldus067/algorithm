#include<iostream>
using namespace std;
int n, arr[1000][2], ans=987654321, idx;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)	cin>>arr[i][0]>>arr[i][1];
	for(int i=0;i<n;++i){
		int m=0;
		for(int j=0;j<n;++j){
			m=max(m, (arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0])
					+(arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1]));
		}
		if(ans>m){
			ans=m;
			idx=i;
		}
	}
	cout<<arr[idx][0]<<' '<<arr[idx][1]<<"\n";
	return 0;
}
