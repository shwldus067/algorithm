#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[2000];
short d[2000][2000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	if(N==1){
		cout<<"1\n";
		return 0;
	}
	sort(arr, arr+N);
	for(int i=0;i<N-1;++i){
		d[i][N-1]=2;
	}
	short ans=2;
	for(int j=N-2;j>=0;--j){
		int i=j-1, k=j+1;
		while(i>=0 && k<N){
			if(arr[i]+arr[k]<2*arr[j]){
				++k;
			}
			else if(arr[i]+arr[k]>2*arr[j]){
				d[i][j]=2;
				--i;
			}
			else{
				d[i][j]=d[j][k]+1;
				ans=max(d[i][j], ans);
				--i;
			}
		}
		while(i>=0){
			d[i][j]=2;
			--i;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
