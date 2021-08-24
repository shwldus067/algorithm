#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, a, b, c, p, m, x[100]={0, }, y[100];
	cin>>n>>a>>b>>m;
	for(int i=0;i<m;++i){
		cin>>p>>c;
		x[c]=p;
	}
	for(int i=1;i<=n;++i)	y[i]=-1;
	for(int i=a, j=0;i;i=x[i], ++j){
		y[i]=j;
	}
	for(int i=b, j=0;i;i=x[i], ++j){
		if(y[i]!=-1){
			cout<<y[i]+j<<"\n";
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}
