#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int N, M, arr[100000];
vector<int> seg;
int init(int x, int s, int e){
	if(s==e)	return seg[x]=s;
	int m=(s+e)/2;
	int l=init(x*2, s, m);
	int r=init(x*2+1, m+1, e);
	return seg[x]=(arr[l]<=arr[r] ? l:r);
}
int update(int x, int s, int e, int d){
	if(s==e)	return seg[x]=d;
	int m=(s+e)/2;
	int l=seg[x*2], r=seg[x*2+1];
	if(d<=m)	l=update(x*2, s, m, d);
	else if(m<d)	r=update(x*2+1, m+1, e, d);
	return seg[x]=(arr[l]<=arr[r] ? l:r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int k=(int)ceil(log2(N));
	M=(1<<(k+1));
	seg=vector<int>(M, 0);
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	init(1, 0, N-1);
	cin>>M;
	while(M--){
		cin>>k;
		if(k==2){
			cout<<seg[1]+1<<"\n";
		}
		else{
			int i, v;
			cin>>i>>v;
			arr[i-1]=v;
			update(1, 0, N-1, i-1);
		}
	}
	return 0;
}
