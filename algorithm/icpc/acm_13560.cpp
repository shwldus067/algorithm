#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[10000], sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)	cin>>arr[i];
	sort(arr, arr+n);
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum<i*(i+1)/2){
			cout<<"-1\n";
			return 0;
		}
	}
	if(sum!=(n*(n-1)/2)){
		cout<<"-1\n";
		return 0;
	}
	else	cout<<"1\n";
	return 0;
}
