#include<iostream>
#include<queue>
using namespace std;
int N, A[1000];
queue<pair<int, int> > Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int ans=0, tmp=0;
	for(int i=0;i<N;++i)	cin>>A[i];
	for(int i=0;i<N;++i)	cin>>tmp, A[i]-=tmp;
	while(1){
		int f=1;
		for(int i=0;i<N;++i){
			if(A[i]){
				f=0;break;
			}
		}
		if(f)	break;
		for(int i=0;i<N;++i){
			if(A[i]){
				int k=i, t=0;
				if(A[i]>0)	f=1, t=A[i];
				else	f=0, t=-A[i];
				for(int j=i+1;j<N;++j){
					if(f && A[j]>0)	k=j, t=min(t, A[j]);
					else if(!f && A[j]<0)	k=j, t=min(t, -A[j]);
					else	break;
				}
				if(f){
					for(int l=i;l<=k;++l)	A[l]-=t;
				}
				else{
					for(int l=i;l<=k;++l)	A[l]+=t;
				}
				ans+=t;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
