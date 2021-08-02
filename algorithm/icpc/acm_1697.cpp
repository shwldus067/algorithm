#include<iostream>
#include<queue>
using namespace std;
bool visit[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, cur, cnt=0, s;
	cin>>N>>K;
	if(N==K){
		cout<<"0\n";
		return 0;
	}
	queue<int> Q;
	visit[N]=true;
	Q.push(N);
	while(!Q.empty()){
		s=Q.size();
		cnt++;
		while(s--){
			cur=Q.front();
			Q.pop();
			if(cur-1==K || cur+1==K || cur*2==K){
				cout<<cnt<<"\n";
				return 0;
			}
			if(cur-1>=0 && !visit[cur-1]){
				visit[cur-1]=true;
				Q.push(cur-1);
			}
			if(cur+1<=100000 && !visit[cur+1]){
				visit[cur+1]=true;
				Q.push(cur+1);
			}
			if(cur*2<=100000 && !visit[cur*2]){
				visit[cur*2]=true;
				Q.push(cur*2);
			}
		}
	}
	return 0;
}
