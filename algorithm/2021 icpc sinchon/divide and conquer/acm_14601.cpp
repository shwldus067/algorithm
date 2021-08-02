#include<iostream>
using namespace std;
int K, arr[128][128], idx=0, x, y;
void func(int r, int c, int d, int kk){
	if(kk==1){
		int t, rr, cc;
		if(d==0)	rr=r, cc=c, t=arr[rr][cc];
		else if(d==1)	rr=r, cc=c+1, t=arr[rr][cc];
		else if(d==2)	rr=r+1, cc=c, t=arr[rr][cc];
		else	rr=r+1, cc=c+1, t=arr[rr][cc];
		++idx;
		arr[r][c]=arr[r][c+1]=arr[r+1][c]=arr[r+1][c+1]=idx;
		arr[rr][cc]=t;
		return;
	}
	int nn=kk>>1;
	func(r+nn, c+nn, d, nn);
	if(d!=0)	func(r, c, 3, nn);
	if(d!=1)	func(r, c+kk, 2, nn);
	if(d!=2)	func(r+kk, c, 1, nn);
	if(d!=3)	func(r+kk, c+kk, 0, nn);
}
void sol(int r1, int c1, int r2, int c2, int k){
	if(k==2){
		++idx;
		arr[r1][c1]=arr[r1][c2]=arr[r2][c1]=arr[r2][c2]=idx;
		arr[x][y]=-1;
		return;
	}
	int n=k>>1;
	if(x<r1+n){
		if(y<c1+n)	sol(r1, c1, r1+n-1, c1+n-1, n), func(r1, c1, 0, n);
		else	sol(r1, c1+n, r1+n-1, c2, n), func(r1, c1, 1, n);
	}else{
		if(y<c1+n)	sol(r1+n, c1, r2, c1+n-1, n), func(r1, c1, 2, n);
		else	sol(r1+n, c1+n, r2, c2, n), func(r1, c1, 3, n);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>K>>y>>x;
	K=1<<K;
	--y, x=K-x;
	sol(0, 0, K-1, K-1, K);
	for(int i=0;i<K;++i){
		for(int j=0;j<K;++j)	cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
