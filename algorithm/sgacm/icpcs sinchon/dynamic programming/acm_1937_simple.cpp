#include<iostream>
using namespace std;
int n, arr[500][500], d[500][500];
int dr[]={-1, 1, 0, 0}, dc[]={0, 0, -1, 1};
int fun(int r, int c){
	int &k=d[r][c];
	if(k)	return k;
	int nr, nc;
	for(int i=0;i<4;i++){
		nr=r+dr[i], nc=c+dc[i];
		if(nr<0 || nr>=n || nc<0 || nc>=n)	continue;
		if(arr[r][c]<arr[nr][nc])	k=max(k, fun(nr, nc));
	}
	return ++k;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			cin>>arr[i][j];
		}
	int res=1;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			res=max(res, fun(i, j));
		}
	}
	cout<<res<<"\n";
	return 0;
}
