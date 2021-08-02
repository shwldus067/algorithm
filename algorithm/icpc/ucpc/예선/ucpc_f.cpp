#include<iostream>
using namespace std;
int N, H, W, M, K;
int map[500][500], r[10];
struct unit_{
	int m, t, y, x;
	unit(int m, int t, int y, int x):m(m), t(t), y(y), x(x){}
};
unit_ unit[62501];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>H>>W;
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<N;++i)	cin>>r[i];
	cin>>M;
	int m, t, y, x;
	for(int i=1;i<=M;++i){
		cin>>m>>t>>y>>x;
		unit[i]=unit_(m, t, y, x);
	}
	cin>>K;
	int u, a, b;
	for(int i=0;i<K;++i){
		cin>>u>>a>>b;
		
	}
}
