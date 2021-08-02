#include<iostream>
#include<algorithm>
using namespace std;
int K, M, N, ain[1000], bin[1000];
int A[1000000], B[1000000], acnt=1, bcnt=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>K>>M>>N;
	for(int i=0;i<M;++i)	cin>>ain[i];
	for(int i=0;i<N;++i)	cin>>bin[i];
	int sum=0, l=0, h=0;
	while(l<M){
		sum+=ain[h++];
		if(sum<=K)	A[acnt++]=sum;
		else{
			l++, h=l, sum=0;
		}
		if(h==M)	h=0;
		if(!l && !h || h+1==l){
			l++, h=l, sum=0;
		}
	}
	sum=l=h=0;
	while(l<N){
		sum+=bin[h++];
		if(sum<=K)	B[bcnt++]=sum;
		else{
			l++, h=l, sum=0;
		}
		if(h==N)	h=0;
		if(!l && !h || h+1==l){
			l++, h=l, sum=0;
		}
	}
	sort(A, A+acnt);
	sort(B, B+bcnt);
	int ans=0;
	for(int i=0;i<acnt;++i){
		ans+=upper_bound(B, B+bcnt, K-A[i])-lower_bound(B, B+bcnt, K-A[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
