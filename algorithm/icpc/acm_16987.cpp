#include<iostream>
using namespace std;
int N, S[8], W[8], ans;
void sol(int n, int cnt){
	if(n==N){
		if(ans<cnt){
			ans=cnt;
		}
		return;
	}
	if(S[n]<=0){
		sol(n+1, cnt);
		return;
	}
	int br=0, chk=1;
	for(int i=0;i<N;++i){
		if(i==n)	continue;
		if(S[i]<=0)	continue;
		S[i]-=W[n];
		S[n]-=W[i];
		br=0;
		if(S[i]<=0)	br++;
		if(S[n]<=0)	br++;
		sol(n+1, cnt+br);
		chk=0;
		S[i]+=W[n];
		S[n]+=W[i];
	}
	if(chk){
		sol(n+1, cnt);
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>S[i]>>W[i];
	sol(0, 0);
	cout<<ans<<"\n";
	return 0;
}
