#include<iostream>
#include<queue>
using namespace std;
int N, M, A, B, X[100], Y[100];
int pre[100];
bool chk[100];
bool pos(int cur, int nxt){
	if(Y[cur]<Y[nxt])	swap(cur, nxt);
	for(int x=X[cur];x<=N;x+=Y[cur]){
		if(x>=X[nxt] && (x-X[nxt])%Y[nxt]==0)	return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;++i){
		cin>>X[i]>>Y[i];
	}
	cin>>A>>B;
	queue<int> Q;
	for(int i=0;i<M;++i){
		if(B>=X[i] && (B-X[i])%Y[i]==0){Q.push(i);chk[i]=1;}
		pre[i]=-1;
	}
	int sz, ans=1;
	while(sz=Q.size()){
		while(sz--){
			int cur=Q.front();Q.pop();
			if(A>=X[cur] && (A-X[cur])%Y[cur]==0){
				cout<<ans<<"\n";
				for(int x=cur, i=ans-1;x!=-1;x=pre[x], --i)
					cout<<x+1<<"\n";
				return 0;
			}
			for(int i=0;i<M;++i){
				if(chk[i])	continue;
				if(!pos(cur, i))	continue;
				chk[i]=1;
				pre[i]=cur;
				Q.push(i);
			}
		}
		++ans;
	}
	cout<<"-1\n";
	return 0;
}
