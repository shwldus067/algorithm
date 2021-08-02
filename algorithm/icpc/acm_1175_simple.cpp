#include<iostream>
#include<queue>
using namespace std;
int N, M, ans;
char arr[50][50];
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
bool visit[50][50][4][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int sr, sc, r1=-1, c1;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		for(int j=0;j<M;j++){
			if(arr[i][j]=='C' && r1==-1){
				r1=i, c1=j;
			}
			else if(arr[i][j]=='S'){
				sr=i, sc=j;
			}
		}
	}
	queue<int> Q;
	for(int i=0;i<4;i++){
		visit[sr][sc][i][0]=true;
		Q.push(sr*10000+sc*100+i*10);
	}
	int res=1, size;
	int r, c, d, n, nr, nc, cur, nn;
	while(size=Q.size()){
		while(size--){
			cur=Q.front();
			Q.pop();
			r=cur/10000, c=cur%10000/100, d=cur%100/10, n=cur%10;
			for(int i=0;i<4;i++){
				if(d==i)	continue;
				nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
				if(arr[nr][nc]=='#')	continue;
				if(visit[nr][nc][i][n])	continue;
				visit[nr][nc][i][n]=true;
				if(arr[nr][nc]=='C'){
					nn=n;
					if(r1==nr && c1==nc)	nn|=1;
					else	nn|=2;
					if(nn==3){
						cout<<res<<"\n";
						return 0;
					}
					Q.push(nr*10000+nc*100+i*10+nn);
				}
				else	Q.push(nr*10000+nc*100+i*10+n);
			}
		}
		res++;
	}
	cout<<"-1\n";
	return 0;
}
