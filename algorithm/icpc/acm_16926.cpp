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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, R, arr[300][300], ans[300][300];
	int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
	N=readInt();M=readInt();R=readInt();
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)	arr[i][j]=readInt();
	int m=min(N, M)/2;
	for(int i=0;i<m;++i){
		int n=(N+M-i*4-2)*2;
		int r=R%n;
		int x=i, y=i;
		int nx, ny, d, dd=0;
		int a, b=M-2*i-1;
		if(r<(N-i*2)){
			ny=y;nx=x+r;d=3;a=r;
		}else if(r<(N+M-2-i*4)){
			nx=N-i-1;ny=y+r-N+i*2+1;d=2;a=ny-y;
		}else if(r<(n-M+1+i*2)){
			ny=M-i-1;nx=N-i-1-(r-(N+M-i*4-2));d=1;a=N-i-nx-1;
		}else{
			nx=x;ny=y+n-r;d=0;a=M-i-ny-1;
		}
		for(int k=0;k<n;++k){
			ans[nx][ny]=arr[x][y];
			if(a){
				nx+=dx[d];ny+=dy[d];
				a--;
			}else{
				d=d==3?0:d+1;
				nx+=dx[d];ny+=dy[d];
				a=d%2?N-2*i-2:M-2*i-2;
			}
			if(b){
				x+=dx[dd];y+=dy[dd];
				b--;
			}else{
				dd++;
				x+=dx[dd];y+=dy[dd];
				b=dd%2?N-2*i-2:M-2*i-2;
			}
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j)	cout<<ans[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
