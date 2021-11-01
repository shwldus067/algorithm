#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, arr[201][201], pre, cur;
	cin>>N>>M;
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)	cin>>arr[i][j];
	for(int k=1;k<=N;++k){
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(arr[i][k] && arr[k][j]){
					arr[i][j]=1;
				}
			}
		}
		arr[k][k]=1;
	}
	cin>>pre;
	for(int i=1;i<M;++i){
		cin>>cur;
		if(!arr[pre][cur]){
			cout<<"NO\n";
			return 0;
		}
		pre=cur;
	}
	cout<<"YES\n";
	return 0;
}
