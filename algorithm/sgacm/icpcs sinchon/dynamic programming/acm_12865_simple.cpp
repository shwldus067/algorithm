#include<iostream>
using namespace std;
int N, K, w[101], v[101], d[100001], tmp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>w[i]>>v[i];
		for(int j=K-w[i];j>=0;--j){
			if(d[j+w[i]]<d[j]+v[i])
				d[j+w[i]]=d[j]+v[i];
		}
	}
	cout<<d[K]<<"\n";
	return 0;
}
