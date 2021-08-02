#include<iostream>
using namespace std;
int N;
char a[64][65];
void sol(int r, int c, int n){
	char t;
	bool f=1;
	if(n==1){
		cout<<a[r][c];
		return;
	}
	t=a[r][c];
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(t!=a[r+i][c+j]){
				f=0;
				break;
			}
		}
		if(f==0)	break;
	}
	if(f){
		cout<<t;
		return;
	}
	cout<<'(';
	int m=n/2;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			sol(r+i*m, c+j*m, m);
		}
	}
	cout<<')';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	sol(0, 0, N);
	return 0;
}
