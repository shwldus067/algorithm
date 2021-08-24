#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, M, A[200], R[200], l=0, r=0, cnt=0;
	bool chk[200]={0, };
	cin>>N>>K;
	M=N+N;
	for(int i=0;i<M;++i)	cin>>A[i];
	int ans=0, s=0, e=N-1;
	while(cnt<K){
		++ans;
		s=s==0?M-1:s-1;e=e==0?M-1:e-1;
		l=0;
		for(int i=0;i<r;++i){
			if(R[i]==e){
				chk[e]=0;
				continue;
			}
			int nxt=R[i]==M-1?0:R[i]+1;
			if(chk[nxt] || A[nxt]<=0){
				R[l++]=R[i];
				continue;
			}
			A[nxt]--;
			if(A[nxt]==0)	cnt++;
			if(nxt==e){
				chk[R[i]]=0;
			}else{
				chk[R[i]]=0;
				chk[nxt]=1;
				R[l++]=nxt;
			}
		}
		if(A[s]>0){
			R[l]=s;
			chk[s]=1;
			++l;
			A[s]--;
			if(A[s]==0)	++cnt;
		}
		r=l;
	}
	cout<<ans<<"\n";
	return 0;
}
