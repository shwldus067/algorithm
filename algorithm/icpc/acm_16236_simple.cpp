#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int N, arr[20][20], p, t, k;
pii Q[400];
#define move(i, j) if(i>=0 && j>=0 && i<N && j<N && !v[i][j]){\
if(arr[i][j]>0 && arr[i][j]<m && (i<x || (i==x && j<y))) x=i, y=j;\
else if(arr[i][j]==0 || arr[i][j]==m)	Q[e++]={i, j}, v[i][j]=1;\
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int x, y, m=2;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>arr[i][j];
			if(arr[i][j]==9)	x=i, y=j;
		}
	}
	while(1){
		int s=0, e=0;
		bool v[20][20]={0, };
		Q[e++]={x, y};
		v[x][y]=1, arr[x][y]=0, x=N, y=N;
		for(p=0;s<e && y==N;++p){
			for(int qs=e-s;qs--;){
				int i=Q[s].first, j=Q[s++].second;
				move(i-1, j);
				move(i, j+1);
				move(i+1, j);
				move(i, j-1);
			}
		}
		if(x==N)	return !printf("%d\n", t);
		if(++k==m)	m++, k=0;
		t+=p;
	}
}
