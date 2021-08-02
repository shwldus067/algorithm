#include<iostream>
using namespace std;
int T, N;
int arr[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		int sum=0, t=0;
		for(int i=0;i<N;++i){
			cin>>arr[t];
			sum+=arr[t++];
			while(t>2){
				int x=arr[t-1];
				int a=arr[t-2], y=arr[t-3];
				if(a>=x && a>=y)	t-=3, arr[t++]=x+y-a;
				else	break;
			}
		}
		int l=0, r=t-1, d=0, m=1;
		while(l<=r){
			if(arr[l]>arr[r]){
				d+=m*arr[l];++l;
			}
			else{
				d+=m*arr[r];--r;
			}
			m*=-1;
		}
		cout<<(sum-d)/2+d<<"\n";
	}
	return 0;
}
