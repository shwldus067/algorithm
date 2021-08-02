#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
int N, K, arr[1001];
unordered_map<ull, int> hs;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		int M;
		cin>>M;
		for(int j=1;j<=M;++j)	cin>>arr[j];
		if(M<K)	continue;
		ull code=0, sub=1;
		for(int j=1;j<=K;++j){
			code=arr[j]+code*33;
			sub*=33;
		}
		if(i==1 || (hs.find(code)!=hs.end() && hs[code]==i-1))
			hs[code]=i;
		for(int j=K+1;j<=M;++j){
			code=code*33+arr[j]-sub*arr[j-K];
			if(i==1 || (hs.find(code)!=hs.end() && hs[code]==i-1))
				hs[code]=i;
		}
		code=0;
		reverse(arr+1, arr+M+1);
		for(int j=1;j<=K;++j)	code=arr[j]+code*33;
		if(i==1 || (hs.find(code)!=hs.end() && hs[code]==i-1))
			hs[code]=i;
		for(int j=K+1;j<=M;++j){
			code=code*33+arr[j]-sub*arr[j-K];
			if(i==1 || (hs.find(code)!=hs.end() && hs[code]==i-1))
				hs[code]=i;
		}
	}
	for(auto iter=hs.begin();iter!=hs.end();++iter){
		if(iter->second==N){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
