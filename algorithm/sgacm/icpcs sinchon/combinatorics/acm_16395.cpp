#include<iostream>
using namespace std;
int c[30][30]={1, };
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin>>n>>k;
	for(int i=1;i<n;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<n;++j){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	cout<<c[n-1][k-1]<<"\n";
	return 0;
}
