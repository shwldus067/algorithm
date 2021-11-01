#include<iostream>
using namespace std;
int d[1500001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, T, P, ans=0;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>T>>P;
		if(i+T<=N){
			d[i+T]=max(d[i+T], d[i]+P);
		}
		d[i+1]=max(d[i+1], d[i]);
	}
	cout<<d[N]<<"\n";
	return 0;
}
