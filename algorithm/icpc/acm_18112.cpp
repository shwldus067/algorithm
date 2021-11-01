#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char A[15], B[15];
	int N=0, M=0, n, m, l;
	bool chk[2048]={0, };
	cin>>A>>B;
	n=strlen(A)-1;
	m=strlen(B)-1;
	for(int i=n;i>=0;--i){
		if(A[i]=='1')	N|=(1<<n-i);
	}
	for(int i=m;i>=0;--i){
		if(B[i]=='1')	M|=(1<<m-i);
	}
	int ans=0;
	queue<int> Q;
	Q.push(N);
	chk[N]=1;
	while(int size=Q.size()){
		while(size--){
			int cur=Q.front();Q.pop();
			if(cur==M){
				cout<<ans<<"\n";
				return 0;
			}
			for(int i=1;i<cur;i*=2){
				if(i*2<=cur){
					int nxt=cur^i;
					if(chk[nxt])	continue;
					chk[nxt]=1;
					Q.push(nxt);
				}
			}
			if(!chk[cur+1])	Q.push(cur+1), chk[cur+1]=1;
			if(cur!=0 && !chk[cur-1])	Q.push(cur-1), chk[cur-1]=1;
		}
		++ans;
	}
	return 0;
}
