#include<iostream>
#include<cmath>
using namespace std;
int N, M, S[20][20], ans=2e9;
int chk[20];
void sol(int idx, int cnt, int a, int b){
	if(cnt==M){
		for(int i=idx;i<N;++i){
			for(int j=0;j<idx;++j){
				if(!chk[j])	b+=S[i][j]+S[j][i];
			}
			for(int j=idx;j<N;++j){
				if(!chk[j]) b+=S[i][j];
			}
		}
		if(abs(a-b)<7){
			idx=0;
		}
		a-=b;
		if(a<0)	a=-a;
		if(ans>a)
			ans=a;
		return;
	}
	int p=0, q=0;
	if(N-idx==M-cnt){
		for(int i=idx;i<N;++i)	chk[i]=1;
		for(int i=idx;i<N;++i){
			for(int j=0;j<idx;++j){
				if(chk[j])	p+=S[i][j]+S[j][i];
			}
			for(int j=idx;j<N;++j){
				if(chk[j]) p+=S[i][j];
			}
		}
		sol(N, M, a+p, b);
		for(int i=idx;i<N;++i)	chk[i]=0;
		return;
	}
	for(int j=0;j<idx;++j){
		if(chk[j])	p+=S[idx][j]+S[j][idx];
		else	q+=S[idx][j]+S[j][idx];
	}
	chk[idx]=1;
	sol(idx+1, cnt+1, a+p, b);
	chk[idx]=0;
	sol(idx+1, cnt, a, b+q);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>S[i][j];
	M=N/2;
	chk[0]=1;
	sol(1, 1, 0, 0);
	cout<<ans<<"\n";
	return 0;
}
