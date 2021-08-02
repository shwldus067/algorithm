#include<iostream>
using namespace std;
bool chk[1000001];
int arr[3001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, t;
	long long ans=0, sum;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];chk[arr[i]]=1;
	}
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			t=arr[j]-arr[i]+arr[j];
			sum=0;
			if(t<=arr[N-1] && chk[t]){
				sum=arr[i]+arr[j];
				t-=arr[j];
				for(int k=t+arr[j];k<=arr[N-1];k+=t){
					if(chk[k])	sum+=k;
					else	break;
				}
				if(ans<sum)	ans=sum;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
