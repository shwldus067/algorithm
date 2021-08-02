#include<iostream>
#include<queue>
using namespace std;
int N, M, bx[2], by[2];
int dx[4]={0, 0, -1, 1}, dy[4]={1, -1, 0, 0};
char B[10][10];
struct bead{
	int rx, ry, bx, by;
};
bool visit[10][10][10][10];
int move(int c, int d){
	int &x=bx[c], &y=by[c];
	x+=dx[d], y+=dy[d];
	while(B[x][y]=='.'){
		x+=dx[d], y+=dy[d];
	}
	if(B[x][y]=='O') return 1;
	x-=dx[d], y-=dy[d];
	if(c)	B[x][y]='B';
	else	B[x][y]='R';
	return 0;
}
int bfs(){
	visit[bx[0]][by[0]][bx[1]][by[1]]=1;
	B[bx[0]][by[0]]=B[bx[1]][by[1]]='.';
	queue<bead> Q;
	Q.push({bx[0], by[0], bx[1], by[1]});
	int size, ans=1;
	while(size=Q.size()){
		while(size--){
			int bh, rh;
			int a, b, c, d;
			a=Q.front().rx, b=Q.front().ry, c=Q.front().bx, d=Q.front().by;
			Q.pop();
			for(int k=0;k<4;++k){
				bx[0]=a, by[0]=b;
				bx[1]=c, by[1]=d;
				bh=rh=0;
				if(k==0){
					if(by[0]<by[1])	bh=move(1, 0), rh=move(0, 0);
					else	rh=move(0, 0), bh=move(1, 0);
				}else if(k==1){
					if(by[0]>by[1])	bh=move(1, 1), rh=move(0, 1);
					else	rh=move(0, 1), bh=move(1, 1);
				}else if(k==2){
					if(bx[0]>bx[1])	bh=move(1, 2), rh=move(0, 2);
					else	rh=move(0, 2), bh=move(1, 2);
				}else{
					if(bx[0]<bx[1])	bh=move(1, 3), rh=move(0, 3);
					else	rh=move(0, 3), bh=move(1, 3);
				}
				if(B[bx[0]][by[0]]=='R')	B[bx[0]][by[0]]='.';
				if(B[bx[1]][by[1]]=='B')	B[bx[1]][by[1]]='.';
				if(visit[bx[0]][by[0]][bx[1]][by[1]])	continue;
				if(bh)	continue;
				if(rh)	return ans;
				visit[bx[0]][by[0]][bx[1]][by[1]]=1;
				Q.push({bx[0], by[0], bx[1], by[1]});
			}
		}
		ans++;
		if(ans>10)	break;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j){
		cin>>B[i][j];
		if(B[i][j]=='R')	bx[0]=i, by[0]=j;
		else if(B[i][j]=='B')	bx[1]=i, by[1]=j;
	}
	cout<<bfs()<<"\n";
	return 0;
}
