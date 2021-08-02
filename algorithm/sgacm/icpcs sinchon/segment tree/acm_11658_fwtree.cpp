#include<iostream>
#include<cstring>
using namespace std;
int arr[1025][1025], tree[1025][1025];
int N, M;
void init(){
	for(int x=1;x<=N;++x){
		for(int y=1;y<=N;++y){
			int i=y+(y&-y);
			if(i<=N)	tree[x][i]+=tree[x][y];
		}
	}
	for(int y=1;y<=N;++y){
		for(int x=1;x<=N;++x){
			int i=x+(x&-x);
			if(i<=N)	tree[i][y]+=tree[x][y];
		}
	}
}
void update(int x, int y, int d){
	for(;x<=N;x+=x&-x){
		for(int i=y;i<=N;i+=i&-i){
			tree[x][i]+=d;
		}
	}
}
int query(int x, int y){
	int ret=0;
	for(;x>0;x-=x&-x){
		for(int i=y;i>0;i-=i&-i){
			ret+=tree[x][i];
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>arr[i][j];
		}
	}
	memcpy(tree, arr, (N+1)*sizeof(arr[0]));
	init();
	int w, x, y, a, b;
	while(M--){
		cin>>w;
		if(w){
			cin>>x>>y>>a>>b;
			cout<<query(a, b)-query(a, y-1)-query(x-1, b)+query(x-1, y-1)<<"\n";
		}
		else{
			cin>>x>>y>>a;
			update(x, y, a-arr[x][y]);
			arr[x][y]=a;
		}
	}
	return 0;
}
