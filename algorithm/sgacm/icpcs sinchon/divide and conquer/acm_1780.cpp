#include<iostream>
using namespace std;
int N, a[2200][2200], ans[3];
void sol(int sr, int sc, int l){
	if(l==1){
		ans[a[sr][sc]+1]++;
		return;
	}
	bool same=true;
	int num=a[sr][sc];
	for(int i=sr;i<sr+l;++i){
		for(int j=sc;j<sc+l;++j){
			if(num!=a[i][j]){
				same=false;
				break;
			}
		}
	}
	if(same){
		ans[a[sr][sc]+1]++;
		return;
	}
	int x=l/3;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			sol(sr+x*i, sc+x*j, x);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>a[i][j];
		}
	}
	sol(0, 0, N);
	cout<<ans[0]<<"\n"<<ans[1]<<"\n"<<ans[2]<<"\n";
	return 0;
}
