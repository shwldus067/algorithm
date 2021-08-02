#include<iostream>
using namespace std;
bool w[800000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int W, N, arr[5000];
	cin>>W>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	w[arr[0]+arr[1]]=1;
	for(int i=2;i<N-1;++i){
		for(int j=i+1;j<N;++j){
			int s=W-(arr[i]+arr[j]);
			if(s<0)	continue;
			if(w[s]){
				cout<<"YES\n";
				return 0;
			}
		}
		for(int j=0;j<i;++j)if(arr[i]+arr[j]<W)
			w[arr[i]+arr[j]]=1;
	}
	cout<<"NO\n";
	return 0;
}
