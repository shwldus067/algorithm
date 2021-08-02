#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, res=0;
bool visit[21][21][21][21];
bool board[22][22];
bool c1, c2;
int dl[4]={0, 0, -1, 1};
int dc[4]={-1, 1, 0, 0};
queue<pair<pair<int, int>, pair<int, int> > > Q;
int bfs(){
	int a, b, c, d, s, e, f, g, h;
	while(!Q.empty()){
		s=Q.size();
		for(int i=0;i<s;i++){
			c1=c2=false;
			a=Q.front().first.first;
			b=Q.front().first.second;
			c=Q.front().second.first;
			d=Q.front().second.second;
			Q.pop();
			if(res>10)	return -1;
			if(a<=0 || a>N || b<=0 || b>M)	c1=true;
			if(c<=0 || c>N || d<=0 || d>M)	c2=true;
			if(c1 && c2)	continue;
			else if((c1 && !c2) || (!c1 && c2))	return res;
			if(visit[a][b][c][d])	continue;
			visit[a][b][c][d]=true;
			for(int k=0;k<4;k++){
				e=a+dl[k], f=b+dc[k];
				g=c+dl[k], h=d+dc[k];
				if(board[e][f])	e=a, f=b;
				if(board[g][h])	g=c, h=d;
				Q.push({{e, f}, {g, h}});
			}
		}
		res++;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	char t;
	vector<pair<int, int> > coin;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>t;
			if(t=='o'){
				coin.push_back(make_pair(i, j));
			}
			else if(t=='#'){
				board[i][j]=true;
			}
		}
	}
	Q.push({{coin[0].first, coin[0].second}, {coin[1].first, coin[1].second}});
	cout<<bfs()<<"\n";
	return 0;
}
