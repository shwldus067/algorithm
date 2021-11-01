#include<iostream>
using namespace std;
int N, par[2000];
int find(int u){
	int &ret=par[u];
	while(ret!=par[ret])	ret=par[ret];
	return ret;
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x<y)	par[y]=x;
	else	par[x]=y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int M;
	cin>>N>>M;
	for(int i=0;i<N;++i)	par[i]=i, par[i+1000]=i+1000;
	for(int i=0;i<M;++i){
		int x, y;
		char L;
		cin>>x>>y>>L;
		x--;y--;
		if(L=='L'){
			merge(x, y+1000);
			merge(x+1000, y);
		}else{
			merge(x, y);
			merge(x+1000, y+1000);
		}
		if(find(x)==find(x+1000) || find(y)==find(y+1000)){
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<M<<"\n";
	return 0;
}
