#include<iostream>
#include<algorithm>
using namespace std;
int N, L, c[32]={1, }, d[32][32]={1, };
long long I;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L>>I;
	int p=0, t=0;
	for(int i=1;i<N;++i){
		p=1;d[i][0]=1;
		for(int j=1;j<=min(i, L);++j){
			t=c[j], c[j]=c[j]+p, p=t;
			d[i][j]=d[i][j-1]+c[j];
		}
	}
	int cnt=L;
	for(int i=N-1;i>=0;--i){
		if(i<cnt)	cnt=i;
		if(I==1)	c[N-i-1]=0;
		else if(d[i][cnt]<I)	c[N-i-1]=1, I-=d[i][cnt], cnt--;
		else	c[N-i-1]=0;
	}
	for(int k=0;k<N;++k)	cout<<c[k];
	return 0;
}
