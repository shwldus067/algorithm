#include<iostream>
#include<queue>
using namespace std;
int S;
queue<pair<int, int> > Q;
bool visit[2001][2001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>S;
	int cnt=2, size;
	Q.push({2, 1});
	visit[2][1]=true;
	while(!Q.empty()){
		size=Q.size();
		while(size--){
			int cur=Q.front().first;
			int clip=Q.front().second;
			Q.pop();
			if(cur==S){
				cout<<cnt<<"\n";
				return 0;
			}
			if(cur!=clip && !visit[cur][cur]){
				visit[cur][cur]=true;
				Q.push({cur, cur});
			}
			if(cur+clip<=2000 && !visit[cur+clip][clip]){
				visit[cur+clip][clip]=true;
				Q.push({cur+clip, clip});
			}
			if(cur-1>2 && !visit[cur-1][clip]){
				visit[cur-1][clip]=true;
				Q.push({cur-1, clip});
			}
		}
		cnt++;
	}
	return 0;
}
