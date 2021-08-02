#include<iostream>
using namespace std;
char buf[1<<17];
inline char read(){
	static int idx=1<<17;
	if(idx==1<<17){
		fread(buf, 1, 1<<17, stdin);
		idx=0;
	}
	return buf[idx++];
}
inline int readInt(){
	int sum=0;
	bool f=0;
	char cur=read();
	while(cur!='-' && (cur==10 || cur==32))	cur=read();
	if(cur=='-')	f=1, cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	if(f)	sum=-sum;
	return sum;
}
int arr[100][100][2], d[100][100][201][2];
int main(){
	int T, M, N, L, G;
	T=readInt();
	while(T--){
		M=readInt();N=readInt();L=readInt();G=readInt();
		for(int i=0;i<M;++i)for(int j=0;j<N-1;++j){
			arr[i][j][0]=readInt();
		}
		for(int i=0;i<M-1;++i)for(int j=0;j<N;++j){
			arr[i][j][1]=readInt();
		}
		int m=N+M;
		for(int i=0;i<M;++i)for(int j=0;j<N;++j){
			for(int k=0;k<m;++k)	d[i][j][k][0]=d[i][j][k][1]=1e9;
		}
		d[0][0][0][0]=d[0][0][0][1]=0;
		for(int i=1;i<N;++i)	d[0][i][0][0]=d[0][i-1][0][0]+arr[0][i-1][0];
		for(int i=1;i<M;++i)	d[i][0][0][1]=d[i-1][0][0][1]+arr[i-1][0][1];
		for(int i=1;i<M;++i)for(int j=1;j<N;++j){
			int t=i+j;
			for(int k=1;k<t;++k){
				d[i][j][k][0]=min(d[i][j-1][k][0], d[i][j-1][k-1][1])+arr[i][j-1][0];
				d[i][j][k][1]=min(d[i-1][j][k][1], d[i-1][j][k-1][0])+arr[i-1][j][1];
			}
		}
		int ans=-1;
		--M, --N;
		for(int k=0;k<m;++k){
			if(d[M][N][k][0]<=G || d[M][N][k][1]<=G){
				ans=L*(M+N)+k;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
