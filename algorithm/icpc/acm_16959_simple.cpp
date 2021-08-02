#include<iostream>
#include<queue>
using namespace std;
struct str{
	int r, c, num, h;
	str(){}
	str(int r, int c, int num, int h):r(r), c(c), num(num), h(h){}
};
int N, dist, ans;
int kr[8]={2, 1, -1, -2, -2, -1, 1, 2};
int kc[8]={1, 2, 2, 1, -1, -2, -2, -1};
int br[4]={1, 1, -1, -1};
int bc[4]={1, -1, -1, 1};
int rr[4]={1, -1, 0, 0};
int rc[4]={0, 0, 1, -1};
int arr[10][10];
bool visit[10][10][101][3];
queue<str> Q;
bool chk(int nr, int nc){
	return 0<=nr && nr<N && 0<=nc && nc<N;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1)
				for(int k=0;k<3;k++){
					visit[i][j][1][k]=true;
					Q.push(str(i, j, 1, k));
				}
		}
	dist=N*N;
	str cur;
	int r, c, h, num;
	for(int cnt=0;;cnt++){
		int size=Q.size();
		while(size--){
			cur=Q.front();
			Q.pop();
			r=cur.r, c=cur.c, num=cur.num, h=cur.h;
			if(arr[r][c]==num+1)	num++;
			if(num==dist){
				cout<<cnt<<"\n";
				return 0;
			}
			//bishop
			if(h==0){
				for(int i=0;i<4;i++){
					int nr=r+br[i], nc=c+bc[i];
					while(chk(nr, nc)){
						if(!visit[nr][nc][num][h]){
							visit[nr][nc][num][h]=true;
							Q.push(str(nr, nc, num, h));
						}
						nr+=br[i], nc+=bc[i];
					}
				}
			}
			//rook
			else if(h==1){
				for(int i=0;i<4;i++){
					int nr=r+rr[i], nc=c+rc[i];
					while(chk(nr, nc)){
						if(!visit[nr][nc][num][h]){
							visit[nr][nc][num][h]=true;
							Q.push(str(nr, nc, num, h));
						}
						nr+=rr[i], nc+=rc[i];
					}
				}
			}
			//knight
			else{
				for(int i=0;i<8;i++){
					int nr=r+kr[i], nc=c+kc[i];
					if(chk(nr, nc)){
						if(!visit[nr][nc][num][h]){
							visit[nr][nc][num][h]=true;
							Q.push(str(nr, nc, num, h));
						}
					}
				}
			}
			for(int k=0;k<3;k++){
				if(k==h)	continue;
				if(!visit[r][c][num][k]){
					visit[r][c][num][k]=true;
					Q.push(str(r, c, num, k));
				}
			}
		}
	}
}
