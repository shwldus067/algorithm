#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int N, K, size, cnt=0;
int visit[200001];
int route[200001];
stack<int> S;
queue<int> Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	if(N==K){
		cout<<"0\n"<<N;
		return 0;
	}
	Q.push(N);
	visit[N]=1;
	bool f=false;
	while(!Q.empty()){
		size=Q.size();
		cnt++;
		while(size--){
			int cur=Q.front();
			Q.pop();
			if(cur-1==K || cur+1==K || cur*2==K){
				f=true;
				route[K]=cur;
				break;
			}
			if(cur-1>=0 && visit[cur-1]==0){
				visit[cur-1]=cnt;
				route[cur-1]=cur;
				Q.push(cur-1);
			}
			if(cur+1<=200000 && visit[cur+1]==0){
				visit[cur+1]=cnt;
				route[cur+1]=cur;
				Q.push(cur+1);
			}
			if((cur<<1)<=200000 && visit[cur<<1]==0){
				visit[cur<<1]=cnt;
				route[cur<<1]=cur;
				Q.push(cur<<1);
			}
		}
		if(f)	break;
	}
	S.push(K);
	for(int x=K;route[x]!=N;x=route[x]){
		S.push(route[x]);
	}
	S.push(N);
	cout<<cnt<<"\n";
	while(!S.empty()){
		int x=S.top();
		cout<<x<<' ';
		S.pop();
	}
	return 0;
}
