#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int N, r1, c1, r2, c2;
	char K[4], S[4], M[4];
	scanf("%s %s %d", K, S, &N);
	c1=K[0]-'A';c2=S[0]-'A';
	r1=7-(K[1]-'1');r2=7-(S[1]-'1');
	while(N--){
		scanf("%s", M);
		int dr=0, dc=0;
		if(strncmp(M, "R", 2)==0)	dc=1;
		else if(strncmp(M, "L", 2)==0)	dc=-1;
		else if(strncmp(M, "B", 2)==0)	dr=1;
		else if(strncmp(M, "T", 2)==0)	dr=-1;
		else if(strncmp(M, "RT", 3)==0)	dr=-1, dc=1;
		else if(strncmp(M, "LT", 3)==0)	dr=-1, dc=-1;
		else if(strncmp(M, "RB", 3)==0)	dr=1, dc=1;
		else if(strncmp(M, "LB", 3)==0)	dr=1, dc=-1;
		int nr=r1+dr, nc=c1+dc;
		if(nr<0 || nr>7 || nc<0 || nc>7)	continue;
		if(nr==r2 && nc==c2){
			int nr2=r2+dr, nc2=c2+dc;
			if(nr2<0 || nr2>7 || nc2<0 || nc2>7)	continue;
			r2=nr2, c2=nc2;
		}
		r1=nr, c1=nc;
	}
	printf("%c%d\n", c1+'A', 8-r1);
	printf("%c%d\n", c2+'A', 8-r2);
	return 0;
}
