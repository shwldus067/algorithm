#include<iostream>
using namespace std;
int N, t[100000];
bool sol(int mid){
	int cnt=0;
	for(int i=0;i<N;++i){
		cnt+=(t[i]-1)/mid-1;
	}
	return cnt<0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>t[0];
	int l=t[0], r=t[0], m;
	for(int i=1;i<N;++i){
		cin>>t[i];
		if(l>t[i])	l=t[i];
		if(r<t[i])	r=t[i];
	}
	while(l<r){
		m=(l+r)/2;
		if(!sol(m))	l=m+1;
		else	r=m;
	}
	cout<<r<<"\n";
	return 0;
}
