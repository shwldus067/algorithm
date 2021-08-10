#include<iostream>
using namespace std;
int N, S[8], W[8], ans;
void sol(int n, int cnt){
	int br=0, chk=1;
	for(int i=0;i<N;++i){
		if(i==n)	continue;
		if(S[i]<=0)	continue;
		S[i]-=W[n];
		S[n]-=W[i];
		br=cnt;
		if(S[i]<=0)	br++;
		if(S[n]<=0)	br++;
		ans=max(ans, br);
		for(int j=n+1;j<N;++j){
			if(S[j]>0){
				sol(j, br);
				break;
			}
		}
		S[i]+=W[n];
		S[n]+=W[i];
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
