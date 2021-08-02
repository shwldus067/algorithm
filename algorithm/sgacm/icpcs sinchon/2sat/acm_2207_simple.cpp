#include<iostream>
using namespace std;
int N, M, arr[10001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		int x, y;
		cin>>x>>y;
		if(x<0){
			x=-x;
			if(arr[x]==0)	arr[x]=1;
			else if(arr[x]==2){
				cout<<"OTL\n";
				return 0;
			}
		}
		else{
			if(arr[x]==0)	arr[x]=2;
			else if(arr[x]==1){
				cout<<"OTL\n";
				return 0;
			}
		}
	}
	cout<<"^_^\n";
	return 0;
}
