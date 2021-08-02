#include<iostream>
using namespace std;
int N, M;
bool visit[1001];
int b[1001];
bool work[1001][1001];
bool dfs(int v){
	for(int i=1;i<=M;i++){
		if(work[v][i] && !visit[i] && !b[i]){
			visit[i]=true;
			b[i]=v;
			return true;
		}
	}
	for(int i=1;i<=M;i++){
		if(work[v][i] && !visit[i]){
			visit[i]=true;
			if(dfs(b[i])){
				b[i]=v;
				return true;
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		int p, q;
		cin>>p;
		while(p--){
			cin>>q;
			work[i][q]=true;
		}
	}
	int ret=0;
	for(int i=1;i<=N;i++){
		fill(visit, visit+M+1, false);
		if(dfs(i))	ret++;
	}
	cout<<ret<<"\n";
	return 0;
}
