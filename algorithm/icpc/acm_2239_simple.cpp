#include<cstdio>
char board[9][10], cnt, bid[9][9];
bool bchk[9][10], rchk[9][10], cchk[9][10];
bool sol(){
	if(cnt==81)	return true;
	//row check
	for(int i=0;i<9;++i)for(int k=1;k<10;++k){
		if(rchk[i][k])	continue;
		int n, t=0;
		for(int j=0;j<9;++j){
			if(!board[i][j] && !cchk[j][k] && !bchk[bid[i][j]][k])	n=j, ++t;
		}
		if(!t)	return false;
		if(t==1){
			board[i][n]=k;
			rchk[i][k]=cchk[n][k]=bchk[bid[i][n]][k]=1;
			++cnt;
			if(sol())	return true;
			board[i][n]=0;
			rchk[i][k]=cchk[n][k]=bchk[bid[i][n]][k]=0;
			--cnt;
			return false;
		}
	}
	//col check
	for(int i=0;i<9;++i)for(int k=1;k<10;++k){
		if(cchk[i][k])	continue;
		int n, t=0;
		for(int j=0;j<9;++j){
			if(!board[j][i] && !rchk[j][k] && !bchk[bid[j][i]][k])	n=j, ++t;
		}
		if(!t)	return false;
		if(t==1){
			board[n][i]=k;
			rchk[n][k]=cchk[i][k]=bchk[bid[n][i]][k]=1;
			++cnt;
			if(sol())	return true;
			board[n][i]=0;
			rchk[n][k]=cchk[i][k]=bchk[bid[n][i]][k]=0;
			--cnt;
			return false;
		}
	}
	//box check
	for(int i=0;i<9;++i)for(int k=1;k<10;++k){
		if(bchk[i][k])	continue;
		int nr, nc, t=0, rr=i/3*3, cc=i%3*3;
		for(int r=0;r<3;++r)for(int c=0;c<3;++c){
			if(!board[rr+r][cc+c] && !rchk[rr+r][k] && !cchk[cc+c][k])	nr=rr+r, nc=cc+c, ++t;
		}
		if(!t)	return false;
		if(t==1){
			board[nr][nc]=k;
			rchk[nr][k]=cchk[nc][k]=bchk[i][k]=1;
			++cnt;
			if(sol())	return true;
			board[nr][nc]=0;
			rchk[nr][k]=cchk[nc][k]=bchk[i][k]=1;
			--cnt;
			return false;
		}
	}
	//cell check
	for(int i=0;i<9;++i)for(int j=0;j<9;++j){
		if(board[i][j])	continue;
		int n, t=0;
		for(int k=1;k<10;++k){
			if(!rchk[i][k] && !cchk[j][k] && !bchk[bid[i][j]][k])	n=k, ++t;
		}
		if(!t)	return false;
		if(t==1){
			board[i][j]=n;
			rchk[i][n]=cchk[j][n]=bchk[bid[i][j]][n]=1;
			++cnt;
			if(sol())	return true;
			board[i][j]=0;
			rchk[i][n]=cchk[j][n]=bchk[bid[i][j]][n]=0;
			--cnt;
			return false;
		}
	}
	//smallest first
	for(int i=0;i<9;++i)for(int j=0;j<9;++j){
		if(board[i][j])	continue;
		for(int k=1;k<10;++k){
			if(!rchk[i][k] && !cchk[j][k] && !bchk[bid[i][j]][k]){
				board[i][j]=k;
				rchk[i][k]=cchk[j][k]=bchk[bid[i][j]][k]=1;
				++cnt;
				if(sol())	return true;
				board[i][j]=0;
				rchk[i][k]=cchk[j][k]=bchk[bid[i][j]][k]=0;
				--cnt;
			}
		}
		return false;
	}
	return false;
}
int main(){
	for(int i=0;i<9;++i)	scanf("%s", &board[i]);
	for(int i=0;i<9;++i)for(int j=0;j<9;++j){
		board[i][j]-='0';
		bid[i][j]=i/3*3+j/3;
		if(board[i][j]){
			++cnt;
			rchk[i][board[i][j]]=cchk[j][board[i][j]]=bchk[bid[i][j]][board[i][j]]=1;
		}
	}
	sol();
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			printf("%c", board[i][j]+'0');
		}
		printf("\n");
	}
	return 0;
}
