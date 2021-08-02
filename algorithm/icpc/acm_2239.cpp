#include<iostream>
using namespace std;
char board[9][10], rzero[81], czero[81], zcnt, bid[9][9];
bool bchk[9][10], rchk[9][10], cchk[9][10];
bool sol(int idx){
	if(idx==zcnt)	return true;
	int r=rzero[idx], c=czero[idx];
	for(int i=1;i<10;++i){
		if(!rchk[r][i] && !cchk[c][i] && !bchk[bid[r][c]][i]){
			rchk[r][i]=cchk[c][i]=bchk[bid[r][c]][i]=1;
			board[r][c]=i;
			if(sol(idx+1))	return true;
			rchk[r][i]=cchk[c][i]=bchk[bid[r][c]][i]=0;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<9;++i)	cin>>board[i];
	for(int i=0;i<9;++i)for(int j=0;j<9;++j){
		board[i][j]-='0';
		bid[i][j]=i/3*3+j/3;
		if(!board[i][j]){
			rzero[zcnt]=i, czero[zcnt++]=j;
		}else{
			rchk[i][board[i][j]]=1;
			cchk[j][board[i][j]]=1;
			bchk[bid[i][j]][board[i][j]]=1;
		}
	}
	sol(0);
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			board[i][j]+='0';
			cout<<board[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
