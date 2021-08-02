#include<stdio.h>
char turn[6][8]={
	{4, 5, 16, 17, 20, 21, 12, 13},
	{18, 19, 22, 23, 14, 15, 6, 7},
	{2, 3, 16, 18, 9, 8, 15, 13},
	{17, 19, 11, 10, 14, 12, 0, 1},
	{0, 2, 4, 6, 8, 10, 23, 21},
	{5, 7, 9, 11, 22, 20, 1, 3}
};
char cube[24];
bool chk(int x){
	for(int i=1;i<4;++i){
		if(cube[x+i]!=cube[x])	return false;
	}
	return true;
}
bool rchk(int x){
	for(int i=0;i<8;i+=2){
		if(cube[turn[x][i]]!=cube[turn[x][i+1]])	return false;
	}
	return true;
}
bool rot1(int a, int b){
	for(int i=0;i<8;i+=2){
		if(cube[turn[a][i]]!=cube[turn[b][i]])	return false;
	}
	return true;
}
bool rot2(int a, int b){
	for(int i=0, j=4;i<8;i+=2, j=(j==6 ? 0:j+2)){
		if(cube[turn[a][i]]!=cube[turn[b][j]])	return false;
	}
	return true;
}
int main(){
	scanf("%c", &cube[0]);
	for(int i=1;i<24;++i)
		scanf(" %c", &cube[i]);
	int ans=0;
	if(chk(0) && chk(8)){
		if(rchk(0) && rchk(1)){
			if(rot1(0, 1) || rot2(0, 1))	ans=1;
		}
	}else if(chk(4) && chk(20)){
		if(rchk(2) && rchk(3)){
			if(rot1(2, 3) || rot2(2, 3))	ans=1;
		}
	}else if(chk(12) && chk(16)){
		if(rchk(4) && rchk(5)){
			if(rot1(4, 5) || rot2(4, 5))	ans=1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
