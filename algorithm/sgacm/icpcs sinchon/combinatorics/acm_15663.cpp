#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N, M;
int inp[8], arr[8], cnt[8], c=-1;
void sol(int n, string s){
	if(n==M){
		cout<<s<<"\n";
		return;
	}
	for(int i=0;i<c;++i){
		if(cnt[i]==0)	continue;
		--cnt[i];
		sol(n+1, s+to_string(arr[i])+" ");
		++cnt[i];
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>inp[i];
	}
	sort(inp, inp+N);
	int p=0;
	for(int i=0;i<N;++i){
		if(p==inp[i])	cnt[c]++;
		else	p=inp[i], arr[++c]=p, cnt[c]=1;
	}
	c++;
	sol(0, "");
	return 0;
}
