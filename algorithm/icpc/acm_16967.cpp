#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int H, W, X, Y, h, w, t;
	int B[600][600], A[300][300];
	cin>>H>>W>>X>>Y;
	h=H+X;w=W+Y;
	for(int i=0;i<h;++i)for(int j=0;j<w;++j)	cin>>B[i][j];
	for(int i=0;i<h;++i)for(int j=0;j<w;++j){
		if(B[i][j]==0)	continue;
		else{
			if(i<X || j<Y){
				A[i][j]=B[i][j];
			}else{
				A[i][j]=B[i][j]-A[i-X][j-Y];
			}
		}
	}
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j)	cout<<A[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
