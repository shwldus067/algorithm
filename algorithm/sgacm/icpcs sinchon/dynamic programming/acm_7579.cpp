#include<iostream>
using namespace std;
int N, M, m[100], c[100], d[10001], sum, res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)	cin>>m[i];
	for(int i=0;i<N;++i){
		cin>>c[i];
		sum+=c[i];
	}
	res=sum;
	for(int i=0;i<N;++i){
		for(int j=sum;j>=c[i];--j){
			d[j]=max(d[j], d[j-c[i]]+m[i]);
			if(d[j]>=M){
				res=min(res, j);
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}
