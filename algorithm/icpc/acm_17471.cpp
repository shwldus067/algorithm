#include<iostream>
#include<queue>
using namespace std;
int N, p[10], ans=10000, sum;
bool adj[10][10], visit[1025][10];
bool chk(int n){
	bool ch[11]={0, };
	queue<int> Q;
	int a=-1, b=-1;
	for(int i=0;i<N;++i){
		if(n&(1<<i)){
			a=i;
		}
		else{
			b=i;
		}
		if(a!=-1 && b!=-1)	break;
	}
	Q.push(a);
	ch[a]=ch[b]=1;
	while(Q.size()){
		int t=Q.front(); Q.pop();
		for(int i=0;i<N;++i){
			if(adj[t][i] && !ch[i] && n&(1<<i)){
				ch[i]=1;
				Q.push(i);
			}
		}
	}
	Q.push(b);
	while(Q.size()){
		int t=Q.front(); Q.pop();
		for(int i=0;i<N;++i){
			if(adj[t][i] && !ch[i] && !(n&(1<<i))){
				ch[i]=1;
				Q.push(i);
			}
		}
	}
	for(int i=0;i<N;++i){
		if(!ch[i])	return false;
	}
	return true;
}
void per(int n, int x, int s){
	if(x==N){
		if(s && s<sum && chk(n)){
			int res=s+s-sum;
			if(res<0)	res=-res;
			if(ans>res)	ans=res;
		}
		return;
	}
	if(visit[n][x])	return;
	visit[n][x]=1;
	per(n|(1<<x), x+1, s+p[x]);
	per(n, x+1, s);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>p[i];
		sum+=p[i];
	}
	for(int i=0;i<N;++i){
		int t, x;
		cin>>t;
		while(t--){
			cin>>x;
			adj[i][x-1]=1;
		}
	}
	per(0, 0, 0);
	if(ans==10000)	cout<<"-1\n";
	else cout<<ans<<"\n";
	return 0;
}
