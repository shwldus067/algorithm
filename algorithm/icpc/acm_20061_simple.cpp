#include<stdio.h>
int N, ans, dy[4]={0, 0, 1, 0}, dx[4]={0, 0, 0, 1};
int board[2][10][4];
void move(int t, int x, int y, int c){
	while(x<9){
		if(t==1 && board[c][x+1][y])	break;
		else if(t==3){
			if(x>7)	break;
			if(board[c][x+2][y])	break;
		}
		else if(t==2 && (board[c][x+1][y] || board[c][x+1][y+1]))	break;
		++x;
	}
	board[c][x][y]=board[c][x+dx[t]][y+dy[t]]=1;
}
void down(int c, int r){
	for(int i=r;i>2;--i){
		for(int j=0;j<4;++j)
			board[c][i][j]=board[c][i-1][j];
	}
}
void score(int c){
	for(int i=9;i>5;--i){
		int f=1;
		for(int j=0;j<4;++j)
			if(!board[c][i][j])	f=0;
		if(f){
			down(c, i);
			ans++;++i;
		}
	}
	for(int i=0;i<2;++i){
		int f=0;
		for(int j=0;j<4;++j)
			if(board[c][5][j])	f=1;
		if(f){
			down(c, 9);
		}
	}
}
int main(){
	scanf("%d", &N);
	while(N--){
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		move(t, x, y, 0);
		score(0);
		if(t==2)	t=3;
		else if(t==3)	t=2, ++y;
		move(t, 3-y, x, 1);
		score(1);
	}
	int sum=0;
	for(int i=6;i<10;++i)for(int j=0;j<4;++j)	sum+=board[0][i][j]+board[1][i][j];
	printf("%d\n%d\n", ans, sum);
	return 0;
}
