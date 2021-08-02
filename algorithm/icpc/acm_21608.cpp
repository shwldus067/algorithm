#include<cstdio>
int main(){
	int N, M, arr[20][20]={0, };
	int cnt[401], fav[401][4], st, x, y, z, w;
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	scanf("%d", &N);
	M=N*N;
	for(int k=0;k<M;++k){
		scanf("%d %d %d %d %d", &st, &x, &y, &z, &w);
		fav[st][0]=x;fav[st][1]=y;fav[st][2]=z;fav[st][3]=w;
		int et=-1, fv=-1, r=0, c=0, d=0, f=0, e=0;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(arr[i][j])	continue;
				f=e=0;
				for(int d=0;d<4;++d){
					int nr=i+dr[d], nc=j+dc[d], tp;
					if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
					if(tp=arr[nr][nc]){
						if(tp==x || tp==y || tp==z || tp==w)	++f;
					}else{
						++e;
					}
				}
				if(fv<f){
					fv=f;
					et=e;
					r=i, c=j;
				}else if(fv==f && et<e){
					et=e;
					r=i, c=j;
				}
			}
		}
		arr[r][c]=st;
		cnt[st]=fv;
		for(int d=0;d<4;++d){
			int rr=r+dr[d], cc=c+dc[d], nb;
			if(rr<0 || rr>=N || cc<0 || cc>=N)	continue;
			if(nb=arr[rr][cc]){
				for(int k=0;k<4;++k){
					if(fav[nb][k]==st){
						cnt[nb]++;
						break;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=M;++i){
		if(cnt[i]==1)	ans++;
		else if(cnt[i]==2)	ans+=10;
		else if(cnt[i]==3)	ans+=100;
		else if(cnt[i]==4)	ans+=1000;
	}
	printf("%d\n", ans);
	return 0;
}
