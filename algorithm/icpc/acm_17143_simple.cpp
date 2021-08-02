#include<stdio.h>
#include<cstring>
struct shark{
	int r, c, s, d, z;
};
struct map{
	int shark, index;
};
shark v[10001];
map board[100][100];
int main(){
	int R, C, M;
	scanf("%d %d %d", &R, &C, &M);
	for(int i=0;i<M;++i){
		scanf("%d %d %d %d %d", &v[i].r, &v[i].c, &v[i].s, &v[i].d, &v[i].z);
		--v[i].r; --v[i].c; --v[i].d;
		if(v[i].d<2)	v[i].s%=((R-1)*2);
		else	v[i].s%=((C-1)*2);
		board[v[i].r][v[i].c].shark=v[i].z;
		board[v[i].r][v[i].c].index=i;
	}
	int ans=0;
	int dr[4]={-1, 1, 0, 0}, dc[4]={0, 0, 1, -1};
	for(int k=0;k<C;++k){
		for(int j=0;j<R;++j){
			if(board[j][k].shark){
				ans+=board[j][k].shark;
				v[board[j][k].index].z=0;
				board[j][k].shark=0;
				break;
			}
		}
		memset(board, 0, sizeof(board));
		for(int i=0;i<M;++i){
			if(!v[i].z)	continue;
			int d=v[i].d;
			int r=v[i].r+v[i].s*dr[d], c=v[i].c+v[i].s*dc[d];
			if(r<0){
				if(r/(R-1)==0)	r=-r, d^=1;
				else	r+=2*(R-1);
			}
			else if(r>=R){
				if(r/(R-1)==1)	r=2*(R-1)-r, d^=1;
				else	r-=2*(R-1);
			}
			if(c<0){
				if(c/(C-1)==0)	c=-c, d^=1;
				else	c+=2*(C-1);
			}
			else if(c>=C){
				if(c/(C-1)==1)	c=2*(C-1)-c, d^=1;
				else	c-=2*(C-1);
			}
			if(!board[r][c].shark)
				board[r][c].shark=v[i].z, board[r][c].index=i;
			else{
				if(board[r][c].shark>v[i].z)	v[i].z=0;
				else{
					v[board[r][c].index].z=0;
					board[r][c].shark=v[i].z;
					board[r][c].index=i;
				}
			}
			v[i].r=r, v[i].c=c, v[i].d=d;
		}
	}
	printf("%d\n", ans);
	return 0;
}
