#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, A[20][20], sum=0, ans;
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		cin>>A[i][j];
		sum+=A[i][j];
	}
	ans=sum;
	for(int d1=1;d1<N-1;++d1){
		for(int d2=1;d2+d1<N;++d2){
			for(int x=0;x+d1+d2<N;++x){
				for(int y=d1;y+d2<N;++y){
					int tmp=0, M=0, m=sum, tp=0;
					for(int i=0;i<x;++i)for(int j=0;j<=y;++j)	tmp+=A[i][j];
					for(int i=0;i<d1;++i)for(int j=0;j<y-i;++j) tmp+=A[x+i][j];
					if(m>tmp)	m=tmp;
					if(M<tmp)	M=tmp;
					tp+=tmp;
					tmp=0;
					for(int i=0;i<x;++i)for(int j=y+1;j<N;++j)	tmp+=A[i][j];
					for(int i=0;i<=d2;++i)for(int j=y+i+1;j<N;++j) tmp+=A[x+i][j];
					if(m>tmp)	m=tmp;
					if(M<tmp)	M=tmp;
					tp+=tmp;
					tmp=0;
					for(int i=0;i<=d2;++i)for(int j=0;j<y-d1+i;++j) tmp+=A[x+d1+i][j];
					for(int i=x+d1+d2+1;i<N;++i)for(int j=0;j<y-d1+d2;++j)	tmp+=A[i][j];
					if(m>tmp)	m=tmp;
					if(M<tmp)	M=tmp;
					tp+=tmp;
					tmp=0;
					for(int i=1;i<=d1;++i)for(int j=y+d2-i+1;j<N;++j) tmp+=A[x+d2+i][j];
					for(int i=x+d1+d2+1;i<N;++i)for(int j=y-d1+d2;j<N;++j)	tmp+=A[i][j];
					if(m>tmp)	m=tmp;
					if(M<tmp)	M=tmp;
					tp+=tmp;
					tmp=sum-tp;
					if(m>tmp)	m=tmp;
					if(M<tmp)	M=tmp;
					if(ans>M-m)	ans=M-m;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
