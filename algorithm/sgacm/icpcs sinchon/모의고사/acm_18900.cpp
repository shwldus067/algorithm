#include<iostream>
using namespace std;
int N, arr[1000001], d[1000001][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		int t;
		cin>>t;
		arr[t]=i;
	}
	if(N==1 || N==2){
		cout<<"1\n";
		return 0;
	}
	d[N][0]=d[N][1]=1;
	for(int i=N-1;i>0;--i){
		if(arr[i]<arr[i+1]){
			d[i][0]=min(d[i+1][0], d[i+1][1])+1;
			d[i][1]=d[i+1][1];
		}
		else{
			d[i][0]=d[i+1][0];
			d[i][1]=min(d[i+1][0], d[i+1][1])+1;
		}
	}
	int ans=d[1][0]<d[1][1] ? d[1][0]:d[1][1];
	cout<<ans<<"\n";
	return 0;
}
