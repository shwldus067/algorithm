#include<iostream>
using namespace std;
#define inf 2e14
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, L[200];
	ll d[200001]={0, }, S[200];
	cin>>N>>M;
	for(int i=0;i<M;++i)	cin>>L[i]>>S[i];
	for(int i=1;i<=N;++i){
		d[i]=inf;
		for(int j=0;j<M;++j){
			if(i<L[j])	d[i]=min(d[i], S[j]);
			else	d[i]=min(d[i], d[i-L[j]]+S[j]);
		}
		cout<<d[i]<<"\n";
	}
	return 0;
}
/*
	sort(arr, arr+M);
	int m=0, k=1;
	for(int i=0;i<M;++i){
		if(arr[i].second<=m)	continue;
		m=arr[i].second;
		for(;k<=m;++k)	d[k]=arr[i].first;
	}
	for(;k<=N;++k){
		d[k]=(ll)d[k-m]+(ll)d[m];
		int t=0;
		for(int i=0;i<M;++i){
			if(arr[i].second<=t)	continue;
			t=arr[i].second;
			d[k]=min(d[k], (ll)d[k-t]+(ll)d[t]);
		}
	}
	for(int i=1;i<=N;++i)	cout<<d[i]<<"\n";
	return 0;
}
	
	int m=arr[0].first;
	for(int i=arr[0].second;i;--i)	cout<<m<<"\n";
	for(int i=0;i)
	while() 	//현재 합보다 길이가 더 짧으면 pass 
	
	2개 5
	3개 3
	3 3 3 
	6개 14=5 0 2 3 2 2		2 3 2 2 3 2   3 2 2 3 2 2
	7개 17=5 0 2 3 2 2 3 2 
	
	1 2 3  4   5   6   7    8
	5 5 7 5+5 5+7 7+7 10+7 12+7
}

2-5 4-7
5 0 2 0 5 0 2
5 5 7 7 12 
0 5 0 2 0 5
1 3 2 1 1 3 2 1
3 2 2 0 3
*/
