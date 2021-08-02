#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[10000], sum=0;
bool f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)	cin>>arr[i], sum+=arr[i];
	if(sum!=(n*(n-1)/2)){
		cout<<"-1\n";
		return 0;
	}
	sort(arr, arr+n);
	for(int i=0;i<n;i++){
		if(arr[i]>n-i-1 || arr[i]<0){
			f=true;
			break;
		}
		for(int j=1;j<n-arr[i]-i;j++){
			arr[n-j]--;
		}
		sort(arr+i+1, arr+n);
	}
	if(!f)	cout<<"1\n";
	else	cout<<"-1\n";
	return 0;
}
