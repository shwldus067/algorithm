#include<cstdio>
using namespace std;
int main(){
	int H, W, X, Y, h, w, t;
	int B[600][600];
	scanf("%d %d %d %d", &H, &W, &X, &Y);
	h=H+X;w=W+Y;
	for(int i=0;i<h;++i)for(int j=0;j<w;++j)	scanf("%d", &B[i][j]);
	for(int i=X;i<h;++i)for(int j=Y;j<w;++j){
		B[i][j]=B[i][j]-B[i-X][j-Y];
	}
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j)	printf("%d ", B[i][j]);
		printf("\n");
	}
	return 0;
}
