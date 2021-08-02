#include<iostream>
using namespace std;
int N, M;
int arr[1025][1025];
int seg[2049][2049];
void inity(int xn, int xl, int xr, int yn, int yl, int yr){
	if(yl==yr){
		if(xl==xr)	seg[xn][yn]=arr[xl][yl];
		else	seg[xn][yn]=seg[2*xn][yn]+seg[2*xn+1][yn];
		return;
	}
	int mid=(yl+yr)/2;
	inity(xn, xl, xr, yn*2, yl, mid);
	inity(xn, xl, xr, yn*2+1, mid+1, yr);
	seg[xn][yn]=seg[xn][yn*2]+seg[xn][yn*2+1];
}
void initx(int xn, int xl, int xr){
	if(xl==xr){
		inity(xn, xl, xr, 1, 0, N-1);
		return;
	}
	int mid=(xl+xr)/2;
	initx(xn*2, xl, mid);
	initx(xn*2+1, mid+1, xr);
	inity(xn, xl, xr, 1, 0, N-1);
}
void init(){
	initx(1, 0, N-1);
}
int queryy(int xn, int yn, int yl, int yr, int l, int r){
	if(r<yl || yr<l)	return 0;
	if(l<=yl && yr<=r)	return seg[xn][yn];
	int mid=(yl+yr)/2;
	return queryy(xn, yn*2, yl, mid, l, r)+queryy(xn, yn*2+1, mid+1, yr, l, r);
}
int queryx(int xn, int xl, int xr, int l, int r, int yl, int yr){
	if(r<xl || xr<l)	return 0;
	if(l<=xl && xr<=r)	return queryy(xn, 1, 0, N-1, yl, yr);
	int mid=(xl+xr)/2;
	return queryx(xn*2, xl, mid, l, r, yl, yr)+queryx(xn*2+1, mid+1, xr, l, r, yl, yr);
}
int query(int xl, int xr, int yl, int yr){
	return queryx(1, 0, N-1, xl, xr, yl, yr);
}
void updatey(int xn, int xl, int xr, int yn, int yl, int yr, int x, int y, int d){
	if(y<yl || yr<y)	return;
	if(yl==yr){
		if(xl==xr)	seg[xn][yn]=d;
		else	seg[xn][yn]=seg[xn*2][yn]+seg[xn*2+1][yn];
		return;
	}
	int mid=(yl+yr)/2;
	updatey(xn, xl, xr, yn*2, yl, mid, x, y, d);
	updatey(xn, xl, xr, yn*2+1, mid+1, yr, x, y, d);
	seg[xn][yn]=seg[xn][yn*2]+seg[xn][yn*2+1];
}
void updatex(int xn, int xl, int xr, int x, int y, int d){
	if(x<xl || xr<x)	return;
	if(xl==xr){
		updatey(xn, xl, xr, 1, 0, N-1, x, y, d);
		return;
	}
	int mid=(xl+xr)/2;
	updatex(xn*2, xl, mid, x, y, d);
	updatex(xn*2+1, mid+1, xr, x, y, d);
	updatey(xn, xl, xr, 1, 0, N-1, x, y, d);
}
void update(int x, int y, int d){
	updatex(1, 0, N-1, x, y, d);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>arr[i][j];
		}
	}
	init();
	int w, x, y, a, b;
	while(M--){
		cin>>w;
		if(w){
			cin>>x>>y>>a>>b;
			cout<<query(x-1, a-1, y-1, b-1)<<"\n";
		}
		else{
			cin>>x>>y>>a;
			update(x-1, y-1, a);
		}
	}
	return 0;
}
