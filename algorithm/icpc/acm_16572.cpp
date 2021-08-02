#include<iostream>
using namespace std;
int N, A, B, C;
int arr[2001][2001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A>>B>>C;
		arr[A][B]=max(arr[A][B], C);
	}
	int ans=0;
	for(int i=1;i<=2000;++i){
		for(int j=1;j<=2000;++j){
			int tmp=max(arr[i][j], max(arr[i-1][j]-1, arr[i][j-1]-1));
			arr[i][j]=tmp;
			if(tmp!=0)	ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
