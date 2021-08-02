#include<iostream>
using namespace std;
int K, M, N;
int ad[1000], bd[1000], acnt[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>K>>M>>N;
	cin>>ad[0];
	for(int i=1;i<M;++i){
		cin>>ad[i];
		ad[i]+=ad[i-1];
	}
	cin>>bd[0];
	for(int i=1;i<N;++i){
		cin>>bd[i];
		bd[i]+=bd[i-1];
	}
	acnt[0]++;
	for(int i=0;i<M;++i){
		for(int j=i;j<M;++j){
			int t=(i ? ad[j]-ad[i-1]:ad[j]);
			acnt[t]++;
		}
	}
	for(int i=0;i<M;++i){
		for(int j=M-1;j>i+1;--j){
			int t=ad[M-1]-ad[j-1]+ad[i];
			acnt[t]++;
		}
	}
	int ans=acnt[K];
	for(int i=0;i<N;++i){
		for(int j=i;j<N;++j){
			int t=(i ? bd[j]-bd[i-1]:bd[j]);
			if(t>K)	continue;
			ans+=acnt[K-t];
		}
	}
	for(int i=0;i<N;++i){
		for(int j=N-1;j>i+1;--j){
			int t=bd[N-1]-bd[j-1]+bd[i];
			if(t>K)	continue;
			ans+=acnt[K-t];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
