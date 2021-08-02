#include<iostream>
#include<cstring>
using namespace std;
int N, ans;
struct str{
	int a[20][20];
	void rot(){
		int b[20][20];
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				b[i][j]=a[N-j-1][i];
			}
		}
		memcpy(a, b, sizeof(a));
	}
	void up(){
		int b[20][20];
		for(int i=0;i<N;++i){
			int t=-1, p=0;
			for(int j=0;j<N;++j){
				if(a[i][j]==0);
				else if(p && a[i][j]==b[i][t])
					b[i][t]+=b[i][t], p=0;
				else	b[i][++t]=a[i][j], p=1;
			}
			for(++t;t<N;++t)	b[i][t]=0;
		}
		memcpy(a, b, sizeof(a));
	}
	void max_value(){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(ans<a[i][j])	ans=a[i][j];
			}
		}
	}
};
void dfs(int cnt, str& cur){
	if(cnt>4){
		cur.max_value();
		return;
	}
	for(int i=0;i<4;++i){
		str nxt=cur;
		nxt.up();
		dfs(cnt+1, nxt);
		cur.rot();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	str start;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>start.a[i][j];
		}
	}
	dfs(0, start);
	cout<<ans<<"\n";
	return 0;
}
