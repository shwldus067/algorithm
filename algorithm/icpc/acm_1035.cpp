#include<iostream>
#include<queue>
using namespace std;
bool visit[9800000];
int r[5], c[5], n, dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
bool chk(){
	bool ch[5]={0, };
	int nr, nc;
	queue<int> qu;
	qu.push(0);
	while(qu.size()){
		int cur=qu.front();qu.pop();
		for(int d=0;d<4;++d){
			nr=r[cur]+dr[d], nc=c[cur]+dc[d];
			for(int i=0;i<n;++i){
				if(!ch[i] && nr==r[i] && nc==c[i]){
					ch[i]=1;qu.push(i);
				}
			}
		}
	}
	for(int i=0;i<n;++i)if(!ch[i])	return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char arr[5][6];
	int cur=0, sz, ans=0, nxt;
	for(int i=0;i<5;++i)	cin>>arr[i];
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			if(arr[i][j]=='*'){
				r[n]=i, c[n]=j;
				++n;
				cur=(cur*5+i)*5+j;
			}
		}
	}
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	queue<int> Q;
	Q.push(cur);
	visit[cur]=1;
	while(sz=Q.size()){
		while(sz--){
			cur=Q.front();Q.pop();
			for(int i=n-1;i>=0;--i){
				c[i]=cur%5;
				cur/=5;
				r[i]=cur%5;
				cur/=5;
			}
			if(chk()){
				cout<<ans<<"\n";
				return 0;
			}
			for(int i=0;i<n;++i){
				for(int d=0;d<4;++d){
					int nr=r[i]+dr[d], nc=c[i]+dc[d];
					if(nr<0 || nr>4 || nc<0 || nc>4)	continue;
					r[i]=nr, c[i]=nc;
					nxt=0;
					for(int k=0;k<n;++k){
						nxt=(nxt*5+r[k])*5+c[k];
					}
					if(!visit[nxt]){
						Q.push(nxt);
						visit[nxt]=1;
					}
					r[i]-=dr[d], c[i]-=dc[d];
				}
			}
		}
		++ans;
	}
	cout<<ans<<"\n";
	return 0;
}
