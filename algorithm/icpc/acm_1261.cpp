#include<iostream>
#include<queue>
using namespace std;
const int inf=~(1<<31);
int N, M, res[100][100];
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
bool wall[100][100];
queue<pair<int, int> > Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>M>>N;
	char c;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>c;
			if(c=='1')	wall[i][j]=true;
		}
	}
	fill(&res[0][0], &res[N-1][M], inf);
	Q.push({0, 0});
	res[0][0]=0;
	while(!Q.empty()){
		int i=Q.front().first, j=Q.front().second;
		Q.pop();
		bool ch=false;
		for(int k=0;k<4;k++){
			int ni=i+dx[k], nj=j+dy[k], w=0;
			if(ni<0 || ni>=N || nj<0 || nj>=M)
				continue;
			if(wall[ni][nj])	w=1;
			if(res[ni][nj]>res[i][j]+w){
				res[ni][nj]=res[i][j]+w;
				ch=true;
			}
			if(ch)	Q.push({ni, nj});
		}
	}
	cout<<res[N-1][M-1]<<"\n";
	return 0;
}
