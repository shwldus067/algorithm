#include<iostream>
using namespace std;
int N, M, size=1;
int seg[2049][2049];
void _update(int x, int y, int d){
	y+=size;
	seg[x][y]=d;
	while(y>>=1){
		seg[x][y]=seg[x][y*2]+seg[x][y*2+1];
	}
}
int _query(int x, int y1, int y2){
	y1+=size, y2+=size;
	int ret=0;
	while(y1<y2){
		if(y1&1)	ret+=seg[x][y1++];
		if(!(y2&1))	ret+=seg[x][y2--];
		y1>>=1, y2>>=1;
	}
	if(y1==y2)	ret+=seg[x][y1];
	return ret;
}
void update(int x, int y, int d){
	x+=size;
	_update(x, y, d);
	while(x>>=1){
		_update(x, y, _query(x*2, y, y)+_query(x*2+1, y, y));
	}
}
int query(int x1, int x2, int y1, int y2){
	x1+=size, x2+=size;
	int ret=0;
	while(x1<x2){
		if(x1&1)	ret+=_query(x1++, y1, y2);
		if(!(x2&1))	ret+=_query(x2--, y1, y2);
		x1>>=1, x2>>=1;
	}
	if(x1==x2)	ret+=_query(x1, y1, y2);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(size<N)	size*=2;
	int t;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>t;
			update(i, j, t);
		}
	}
	int w, x, y, a, b;
	while(M--){
		cin>>w;
		if(w){
			cin>>x>>y>>a>>b;
			cout<<query(x, a, y, b)<<"\n";
		}
		else{
			cin>>x>>y>>a;
			update(x, y, a);
		}
	}
}
