#include<iostream>
#include<queue>
using namespace std;
int visit[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, cur;
	cin>>N>>K;
	if(N==K){
		cout<<"0\n";
		return 0;
	}
	fill(visit, visit+200001, -1);
	queue<int> Q;
	visit[N]=0;
	Q.push(N);
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		if(cur==K){
			cout<<visit[cur]<<"\n";
			return 0;
		}
		if(cur-1>=0){
			if(visit[cur-1]==-1){
				visit[cur-1]=visit[cur]+1;
				Q.push(cur-1);
			}
			else if(visit[cur-1]>(visit[cur]+1)){
				visit[cur-1]=visit[cur]+1;
				Q.push(cur-1);
			}
		}
		if(cur+1<=200000){
			if(visit[cur+1]==-1){
				visit[cur+1]=visit[cur]+1;
				Q.push(cur+1);
			}
			else if(visit[cur+1]>(visit[cur]+1)){
				visit[cur+1]=visit[cur]+1;
				Q.push(cur+1);
			}
		}
		if((cur<<1)<=200000){
			if(visit[cur<<1]==-1){
				visit[cur<<1]=visit[cur];
				Q.push(cur<<1);
			}
			else if(visit[cur<<1]>visit[cur]){
				visit[cur<<1]=visit[cur];
				Q.push(cur<<1);
			}
		}
	}
	return 0;
}
