#include<iostream>
using namespace std;
int N, M, arr[1000][1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)	cin>>arr[i][j];
	int ans=0;
	for(int i=0;i<N;++i){
		int g=0;
		for(int j=M-1;j>=0;--j){
			if(g==0)	g=arr[i][j];
			else if(arr[i][j]<=g)	g=arr[i][j]-1;
			else	g=arr[i][j];
		}
		ans^=g;
	}
	if(ans)	cout<<"koosaga\n";
	else	cout<<"cubelover\n";
	return 0;
}
