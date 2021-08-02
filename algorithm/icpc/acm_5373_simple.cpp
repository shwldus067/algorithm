#include<stdio.h>
int cube[60];
int chg[6][12]={
	{51, 31, 41, 21, 50, 30, 40, 20, 52, 32, 42, 22},
	{56, 26, 46, 36, 57, 27, 47, 37, 58, 28, 48, 38},
	{0, 40, 18, 58, 3, 43, 15, 55, 6, 46, 12, 52},
	{8, 50, 10, 48, 5, 53, 13, 45, 2, 56, 16, 42},
	{6, 30, 16, 28, 7, 33, 17, 25, 8, 36, 18, 22},
	{2, 20, 12, 38, 1, 23, 11, 35, 0, 26, 10, 32}
};
char color[6]={'w', 'y', 'g', 'b', 'r', 'o'};
char input[3000];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		for(int i=0;i<60;++i)
			cube[i]=i/10;
		int N;
		scanf("%d\n", &N);
		scanf("%[^\n]s", input);
		N*=3;
		for(int n=0;n<N;++n){
			char a=input[n++], b=input[n++];
			int c;
			if(a=='U')	c=0;
			else if(a=='D')	c=1;
			else if(a=='L')	c=2;
			else if(a=='R')	c=3;
			else if(a=='F')	c=4;
			else	c=5;
			if(b=='+'){
				int t=cube[c*10+1];
				cube[c*10+1]=cube[c*10+3];
				cube[c*10+3]=cube[c*10+7];
				cube[c*10+7]=cube[c*10+5];
				cube[c*10+5]=t;
				t=cube[c*10];
				cube[c*10]=cube[c*10+6];
				cube[c*10+6]=cube[c*10+8];
				cube[c*10+8]=cube[c*10+2];
				cube[c*10+2]=t;
				for(int i=0;i<12;i+=4){
					t=cube[chg[c][i]];
					cube[chg[c][i]]=cube[chg[c][i+3]];
					cube[chg[c][i+3]]=cube[chg[c][i+2]];
					cube[chg[c][i+2]]=cube[chg[c][i+1]];
					cube[chg[c][i+1]]=t;
				}
			}
			else{
				int t=cube[c*10+1];
				cube[c*10+1]=cube[c*10+5];
				cube[c*10+5]=cube[c*10+7];
				cube[c*10+7]=cube[c*10+3];
				cube[c*10+3]=t;
				t=cube[c*10];
				cube[c*10]=cube[c*10+2];
				cube[c*10+2]=cube[c*10+8];
				cube[c*10+8]=cube[c*10+6];
				cube[c*10+6]=t;
				for(int i=0;i<12;i+=4){
					t=cube[chg[c][i]];
					cube[chg[c][i]]=cube[chg[c][i+1]];
					cube[chg[c][i+1]]=cube[chg[c][i+2]];
					cube[chg[c][i+2]]=cube[chg[c][i+3]];
					cube[chg[c][i+3]]=t;
				}
			}
		}
		printf("%c%c%c\n", color[cube[0]], color[cube[1]], color[cube[2]]);
		printf("%c%c%c\n", color[cube[3]], color[cube[4]], color[cube[5]]);
		printf("%c%c%c\n", color[cube[6]], color[cube[7]], color[cube[8]]);
	}
}
