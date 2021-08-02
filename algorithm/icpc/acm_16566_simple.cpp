#include<iostream>
using namespace std;
const int Max=1<<22;
int N, M, K, seg[Max<<1];
int query(int x){
	x+=Max+1;
	while(1){
		if(seg[x]){
			if(x>=Max)	break;
			x*=2;
			if(!seg[x])	x++;
		}
		else	x=x%2 ? x+1:x/2;
	}
	int ret=x-Max;
	for(;x;x/=2)	seg[x]--;
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	while(M--){
		int t;
		cin>>t;
		seg[Max+t]=1;
	}
	for(int i=Max;--i;)
		seg[i]=seg[i*2]+seg[i*2+1];
	while(K--){
		int t;
		cin>>t;
		cout<<query(t)<<"\n";
	}
	return 0;
}
