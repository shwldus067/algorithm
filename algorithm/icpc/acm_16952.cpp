#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=10000;
struct str{
	int r, c, num, h, ch;
	str(){}
	str(int r, int c, int num, int h, int ch):r(r), c(c), num(num), h(h), ch(ch){}
};
int N, dist, ans;
int kr[8]={2, 1, -1, -2, -2, -1, 1, 2};
int kc[8]={1, 2, 2, 1, -1, -2, -2, -1};
int br[4]={1, 1, -1, -1};
int bc[4]={1, -1, -1, 1};
int rr[4]={1, -1, 0, 0};
int rc[4]={0, 0, 1, -1};
int arr[10][10];
bool visit[10][10][101][3][300];
queue<str> Q;
vector<int> v;
bool chk(int nr, int nc){
	return 0<=nr && nr<N && 0<=nc && nc<N;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	dist=N*N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1)
				for(int k=0;k<3;k++){
					visit[i][j][1][k][0]=true;
					Q.push(str(i, j, 1, k, 0));
				}
		}
	str cur;
	int r, c, h, num, ch;
	bool find=false;
	for(int cnt=0;;cnt++){
		int size=Q.size();
		while(size--){
			cur=Q.front();
			Q.pop();
			r=cur.r, c=cur.c, num=cur.num, h=cur.h, ch=cur.ch;
			if(arr[r][c]==num+1)	num++;
			if(num==dist){
				find=true;
				v.push_back(ch);
				continue;
			}
			if(find)	continue;
			//bishop
			if(h==0){
				for(int i=0;i<4;i++){
					int nr=r+br[i], nc=c+bc[i];
					while(chk(nr, nc)){
						if(!visit[nr][nc][num][h][ch]){
							visit[nr][nc][num][h][ch]=true;
							Q.push(str(nr, nc, num, h, ch));
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
						if(!visit[nr][nc][num][h][ch]){
							visit[nr][nc][num][h][ch]=true;
							Q.push(str(nr, nc, num, h, ch));
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
						if(!visit[nr][nc][num][h][ch]){
							visit[nr][nc][num][h][ch]=true;
							Q.push(str(nr, nc, num, h, ch));
						}
					}
				}
			}
			for(int k=0;k<3;k++){
				if(k==h)	continue;
				if(!visit[r][c][num][k][ch+1]){
					visit[r][c][num][k][ch+1]=true;
					Q.push(str(r, c, num, k, ch+1));
				}
			}
		}
		if(find){
			cout<<cnt<<" ";
			sort(v.begin(), v.end());
			cout<<v[0]<<"\n";
			return 0;
		}
	}
}
