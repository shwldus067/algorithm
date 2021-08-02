#include<stdio.h>
int N, ans;
int g[6][4], b[4][6];
void delgreen(int r, int k){
	for(int i=r-k;~i;--i){
		for(int j=0;j<4;++j){
			g[i+k][j]=g[i][j];
		}
	}
	for(int i=0;i<2;++i){
		for(int j=0;j<4;++j){
			g[i][j]=0;
		}
	}
}
void delblue(int c, int k){
	for(int i=c-k;~i;--i){
		for(int j=0;j<4;++j){
			b[j][i+k]=b[j][i];
		}
	}
	for(int i=0;i<2;++i){
		for(int j=0;j<4;++j){
			b[j][i]=0;
		}
	}
}
void scoregreen(){
	int s=0, c=0;
	for(int i=2;i<6;++i){
		int f=1;
		for(int j=0;j<4;++j){
			if(!g[i][j]){
				f=0;break;
			}
		}
		if(f){
			s=i, c++;
		}
	}
	if(s) delgreen(s, c), ans+=c;
}
void scoreblue(){
	int s=0, c=0;
	for(int i=2;i<6;++i){
		int f=1;
		for(int j=0;j<4;++j){
			if(!b[j][i]){
				f=0;break;
			}
		}
		if(f){
			s=i, c++;
		}
	}
	if(s) delblue(s, c), ans+=c;
}
void movegreen(int x1, int y1, int x2, int y2){
	while(x2<6 && !g[x1][y1] && !g[x2][y2])	x1++, x2++;
	x1--, x2--;
	g[x1][y1]=g[x2][y2]=1;
	scoregreen();
	int cnt=0;
	for(int i=0;i<2;++i){
		int f=0;
		for(int j=0;j<4;++j){
			if(g[i][j]){
				f=1;break;
			}
		}
		if(f)	cnt++;
	}
	if(cnt)	delgreen(5, cnt);
}
void moveblue(int x1, int y1, int x2, int y2){
	while(y2<6 && !b[x1][y1] && !b[x2][y2])	y1++, y2++;
	y1--, y2--;
	b[x1][y1]=b[x2][y2]=1;
	scoreblue();
	int cnt=0;
	for(int i=0;i<2;++i){
		int f=0;
		for(int j=0;j<4;++j){
			if(b[j][i]){
				f=1;break;
			}
		}
		if(f)	cnt++;
	}
	if(cnt)	delblue(5, cnt);
}
int main(){
	scanf("%d", &N);
	while(N--){
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if(t==1){
			movegreen(1, y, 1, y);
			moveblue(x, 1, x, 1);
		}else if(t==2){
			movegreen(1, y, 1, y+1);
			moveblue(x, 0, x, 1);
		}else{
			movegreen(0, y, 1, y);
			moveblue(x, 1, x+1, 1);
		}
	}
	int sum=0;
	for(int i=0;i<6;++i)for(int j=0;j<4;++j)	sum+=g[i][j]+b[j][i];
	printf("%d\n%d\n", ans, sum);
	return 0;
}
