#include<iostream>
using namespace std;
typedef unsigned us;
int N;
us A[20000], C[20000], B[20000];
int sol(us m){
	int ret=0;
	for(int i=0;i<N;++i){
		if(A[i]<=m){
			ret+=(min(m, C[i])-A[i])/B[i]+1;
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i]>>C[i]>>B[i];
	}
	us l=0, r=~(1<<31), ans=-1;
	while(l<=r){
		us m=(l+r)/2;
		if(sol(m)%2)	r=m-1, ans=m;
		else	l=m+1;
	}
	if(ans==-1){
		cout<<"NOTHING\n";
	}
	else{
		cout<<ans<<" "<<sol(ans)-sol(ans-1)<<"\n";
	}
	return 0;
}
