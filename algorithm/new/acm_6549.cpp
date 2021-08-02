#include<iostream>
using namespace std;

int main(){
	int n, h[100000], cnt;
	long long int res;
	cin>>n;
	while(n!=0){
		for(int i=0;i<n;i++)	cin>>h[i];
		res=0;
		for(int i=0;i<n;i++){
			cnt=1;
			for(int j=i-1;j>=0 && h[i]<=h[j];j--){
				cnt++;
			}
			for(int j=i+1;j<n && h[i]<=h[j];j++){
				cnt++;
			}
			res=res>cnt*h[i] ? res:cnt*h[i];
		}
		cout<<res<<"\n";
		cin>>n;
	}
	return 0;
}
