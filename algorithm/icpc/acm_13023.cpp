#include<iostream>
#include<vector>
using namespace std;
int N, M;
bool visit[2000];
vector<int> r[2000];
bool sol(int i, int cnt){
	if(cnt==4)	return true;
	visit[i]=true;
	for(int v=0;v<r[i].size();v++){
		int next=r[i][v];
		if(visit[next])	continue;
		if(sol(next, cnt+1))	return true;
	}
	visit[i]=false;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		r[a].push_back(b);
		r[b].push_back(a);
	}
	for(int i=0;i<N;i++){
		fill(visit, visit+N, false);
		if(sol(i, 0)){
			cout<<"1\n";
			return 0;
		}
	}
	cout<<"0\n";
	return 0;
}
