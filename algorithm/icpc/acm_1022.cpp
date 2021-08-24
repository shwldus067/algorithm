#include<iostream>
using namespace std;
#define MAX 10001*10001
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int r1, c1, r2, c2, arr[50][50], M=0;
	cin>>r1>>c1>>r2>>c2;
	int cnt=1, r=0, c=0, d=0, k=1;
	int dr[4]={0, -1, 0, 1}, dc[4]={1, 0, -1, 0};
	if(r1<=0 && 0<=r2 && c1<=0 && 0<=c2){
		arr[-r1][-c1]=cnt;
		M=1;
	}
	while(cnt<=MAX){
		for(int i=0;i<k;++i){
			r+=dr[d];c+=dc[d];++cnt;
			if(r1<=r && r<=r2 && c1<=c && c<=c2){
				arr[r-r1][c-c1]=cnt;
				M=M>cnt?M:cnt;
			}
		}
		d=d==3?0:d+1;
		for(int i=0;i<k;++i){
			r+=dr[d];c+=dc[d];++cnt;
			if(r1<=r && r<=r2 && c1<=c && c<=c2){
				arr[r-r1][c-c1]=cnt;
				M=M>cnt?M:cnt;
			}
		}
		d=d==3?0:d+1;
		++k;
	}
	int rr=r2-r1+1, cc=c2-c1+1;
	int ml=0, nl, tt;
	for(int l=1;l<=M;l*=10)	++ml;
	for(int i=0;i<rr;++i){
		for(int j=0;j<cc;++j){
			nl=0;
			tt=arr[i][j];
			for(int l=1;l<=tt;l*=10)	++nl;
			for(int l=ml-nl;l;--l)	cout<<" ";
			cout<<tt<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
