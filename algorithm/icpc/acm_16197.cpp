#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<pair<int, int> > coin;
bool board[22][22];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, 1, -1};
int play(int n){
	if(n>10)	return -1;
	int f_l=coin[0].first, f_c=coin[0].second;
	int s_l=coin[1].first, s_c=coin[1].second;
	if(f_l==s_l && f_c==s_c)	return -1;
	if(f_l<=0 || f_l>N || f_c<=0 || f_c>M){
		if(s_l>0 && s_l<=N && s_c>0 && s_c<=M)
			return n;
		else
			return -1;
	}
	if(s_l<=0 || s_l>N || s_c<=0 || s_c>M){
		if(f_l>0 && f_l<=N && f_c>0 && f_c<=M)
			return n;
	}
	int cur=11, t;
	for(int i=0;i<4;i++){
		coin[0]=make_pair(f_l, f_c);
		coin[1]=make_pair(s_l, s_c);
		if(board[f_l+dx[i]][f_c+dy[i]])
			coin[0]=make_pair(f_l+dx[i], f_c+dy[i]);
		if(board[s_l+dx[i]][s_c+dy[i]])
			coin[1]=make_pair(s_l+dx[i], s_c+dy[i]);
		t=play(n+1);
		if(t!=-1)	cur=min(cur, t);
	}
	if(cur==11)	return -1;
	else	return cur;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c;
	cin>>N>>M;
	fill(&board[0][0], &board[21][22], true);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>c;
			if(c=='o'){
				coin.push_back(make_pair(i, j));
			}
			else if(c=='#'){
				board[i][j]=false;
			}
		}
	}
	cout<<play(0)<<"\n";
	return 0;
}
