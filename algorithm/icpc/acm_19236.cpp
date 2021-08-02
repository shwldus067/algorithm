#include<iostream>
using namespace std;
int arr[4][4];
int dr[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8]={0, -1, -1, -1, 0, 1, 1, 1};
struct fish{
	int r, c, d;
}F[17];
int sol(int x, int y, int sd){
	int ret=0, tmp[4][4];
	fish tf[17];
	for(int i=0;i<4;++i)for(int j=0;j<4;++j)	tmp[i][j]=arr[i][j];
	for(int i=1;i<17;++i)	tf[i]=F[i];
	for(int f=1;f<17;++f){
		if(F[f].r==-1)	continue;
		int r=F[f].r, c=F[f].c, d=F[f].d;
		for(int k=0;k<8;++k){
			int nd=(d+k)%8;
			int nr=r+dr[nd], nc=c+dc[nd];
			if(nr<0 || nr>3 || nc<0 || nc>3)	continue;
			if(nr==x && nc==y)	continue;
			if(arr[nr][nc]){
				arr[r][c]=arr[nr][nc];
				arr[nr][nc]=f;
				F[f]={nr, nc, nd};
				F[arr[r][c]].r=r;
				F[arr[r][c]].c=c;
			}
			else{
				arr[r][c]=0;
				arr[nr][nc]=f;
				F[f]={nr, nc, nd};
			}
			break;
		}
	}
	int nx=x+dr[sd], ny=y+dc[sd];
	for(;nx>=0 && nx<4 && ny>=0 && ny<4;nx+=dr[sd], ny+=dc[sd]){
		if(arr[nx][ny]){
			int f=arr[nx][ny];
			arr[nx][ny]=0;
			F[f].r=-1;
			ret=max(ret, sol(nx, ny, F[f].d)+f);
			arr[nx][ny]=f;
			F[f].r=nx;
		}
	}
	for(int i=0;i<4;++i)for(int j=0;j<4;++j)	arr[i][j]=tmp[i][j];
	for(int i=1;i<17;++i)	F[i]=tf[i];
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			int a, b;
			cin>>a>>b;
			arr[i][j]=a;
			F[a]={i, j, b-1};
		}
	}
	int ans=arr[0][0];
	arr[0][0]=0;
	F[ans].r=-1;
	ans+=sol(0, 0, F[ans].d);
	cout<<ans<<"\n";
	return 0;
}
