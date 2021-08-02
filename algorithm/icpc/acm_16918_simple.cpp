#include<stdio.h>
int main(){
	int R, C, N;
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	char A[2][201][201];
	scanf("%d %d %d", &R, &C, &N);
	if(!(N&1)){
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j)
				printf("O");
			printf("\n");
		}
		return 0;
	}
	N>>=1;
	for(int i=0;i<R;++i){
		scanf("%s", A[0][i]);
	}
	if(N>2)	N=(N-4)%2+2;
	int t=0, p=1;
	while(N--){
		for(int i=0;i<R;++i)for(int j=0;j<C;++j){
			if(A[t][i][j]=='.')	A[p][i][j]='O';
			else	A[p][i][j]='.';
		}
		for(int i=0;i<R;++i)for(int j=0;j<C;++j){
			if(A[t][i][j]=='O'){
				for(int d=0;d<4;++d){
					int r=i+dr[d], c=j+dc[d];
					if(r>=0 && r<R && c>=0 && c<C){
						A[p][r][c]='.';
					}
				}
			}
		}
		t=p;
		p^=1;
	}
	for(int i=0;i<R;++i){
		printf("%s\n", A[t][i]);
	}
	return 0;
}
