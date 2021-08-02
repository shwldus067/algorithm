#include<stdio.h>
int main(){
	int r, c, k, A[100][100]={0, }, B[101];
	scanf("%d %d %d", &r, &c, &k);
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)	scanf("%d", &A[i][j]);
	int time=0;
	--r, --c;
	int ns, s=3, m=0;
	while(A[r][c]!=k && time<101){
		++time;
		ns=0;
		for(int i=0;i<s;++i){
			for(int j=0;j<101;++j)	B[j]=0;
			int M=0, L=0;
			for(int j=0;j<100;++j){
				if(!m && A[i][j]){
					B[A[i][j]]++;
					if(M<A[i][j])	M=A[i][j];
					if(L<B[A[i][j]])	L=B[A[i][j]];
				}else if(m && A[j][i]){
					B[A[j][i]]++;
					if(M<A[j][i])	M=A[j][i];
					if(L<B[A[j][i]])	L=B[A[j][i]];
				}
			}
			int idx=0;
			for(int k=1;k<=L;++k){
				for(int j=1;j<=M;++j){
					if(B[j]==k){
						if(m){
							A[idx++][i]=j;A[idx++][i]=k;
						}
						else{
							A[i][idx++]=j;A[i][idx++]=k;
						}
					}
				}
			}
			if(idx>ns)	ns=idx;
			for(int j=idx;j<s;++j){
				if(m) A[j][i]=0;
				else	A[i][j]=0;
			}
		}
		if(s==ns)	m=0;
		else if(s<ns && !m)	m=1, s=ns;
		else if(s<ns && m)	m=0, s=ns;
	}
	if(time>100)	printf("-1\n");
	else printf("%d\n", time);
}
