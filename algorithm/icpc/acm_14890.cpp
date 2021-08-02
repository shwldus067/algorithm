#include<iostream>
using namespace std;
int N, L, A[100][100], r[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>A[i][j];
	int ans=0;
	for(int i=0;i<N;++i){
		int a=A[i][0], f=1;
		for(int j=0;j<N;++j)	r[j]=0;
		for(int k=1;k<N;++k){
			if(a==A[i][k])	continue;
			if(a==A[i][k]+1){
				int ramp=0, b=A[i][k];
				for(int l=0;l<L;++l){
					if(k+l>=N || b!=A[i][k+l] || r[k+l]){
						ramp=1;break;
					}
				}
				if(ramp){
					f=0;break;
				}
				for(int l=0;l<L;++l)	r[k+l]=1;
			}else if(a+1==A[i][k]){
				int ramp=0;
				for(int l=1;l<=L;++l){
					if(k-l<0 || a!=A[i][k-l] || r[k-l]){
						ramp=1;break;
					}
				}
				if(ramp){
					f=0;break;
				}
				for(int l=1;l<=L;++l)	r[k-l]=1;
			}else{
				f=0;
				break;
			}
			a=A[i][k];
		}
		if(f)	ans++;
	}
	for(int i=0;i<N;++i){
		int a=A[0][i], f=1;
		for(int j=0;j<N;++j)	r[j]=0;
		for(int k=1;k<N;++k){
			if(a==A[k][i])	continue;
			if(a==A[k][i]+1){
				int ramp=0, b=A[k][i];
				for(int l=0;l<L;++l){
					if(k+l>=N || b!=A[k+l][i] || r[k+l]){
						ramp=1;break;
					}
				}
				if(ramp){
					f=0;break;
				}
				for(int l=0;l<L;++l)	r[k+l]=1;
			}else if(a+1==A[k][i]){
				int ramp=0;
				for(int l=1;l<=L;++l){
					if(k-l<0 || a!=A[k-l][i] || r[k-l]){
						ramp=1;break;
					}
				}
				if(ramp){
					f=0;break;
				}
				for(int l=1;l<=L;++l)	r[k-l]=1;
			}else{
				f=0;
				break;
			}
			a=A[k][i];
		}
		if(f)	ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
