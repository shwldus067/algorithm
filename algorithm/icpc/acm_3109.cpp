#include<iostream>
using namespace std;
int R, C, dr[3]={-1, 0, 1}, cnt=0;
bool block[10000][500];
bool dfs(int r, int c){
	block[r][c]=true;
	if(c==C-1)	return true;
	for(int i=0;i<3;i++){
		if(r+dr[i]>=0 && r+dr[i]<R && !block[r+dr[i]][c+1]){
			if(dfs(r+dr[i], c+1))	return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	char t;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>t;
			if(t=='x')	block[i][j]=true;
		}
	}
	for(int i=0;i<R;i++){
		if(dfs(i, 0))	cnt++;
	}
	cout<<cnt<<"\n";
	return 0;
}
