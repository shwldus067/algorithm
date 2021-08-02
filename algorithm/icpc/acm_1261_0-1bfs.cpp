#include<iostream>
#include<deque>
using namespace std;
int N, M, res[100][100];
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
bool wall[100][100], visit[100][100];
deque<pair<int, int> > DQ;
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
	DQ.push_front({0, 0});
	visit[0][0]=true;
	while(!DQ.empty()){
		int i=DQ.front().first, j=DQ.front().second;
		DQ.pop_front();
		for(int k=0;k<4;k++){
			int ni=i+dx[k], nj=j+dy[k];
			if(ni<0 || ni>=N || nj<0 || nj>=M || visit[ni][nj])
				continue;
			visit[ni][nj]=true;
			if(wall[ni][nj]){
				DQ.push_back({ni, nj});
				res[ni][nj]=res[i][j]+1;
			}
			else{
				DQ.push_front({ni, nj});
				res[ni][nj]=res[i][j];
			}
		}
	}
	cout<<res[N-1][M-1]<<"\n";
	return 0;
}
