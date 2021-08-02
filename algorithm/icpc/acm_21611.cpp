#include<cstdio>
int main(){
	int N, M, A[2][50][50];
	int dr[4]={0, 1, 0, -1}, dc[4]={-1, 0, 1, 0};
	int cnt[4]={0, };
	int d, s, t=0, nt=1;
	scanf("%d %d", &N, &M);
	int n=N/2;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%d", &A[0][i][j]);
	A[1][n][n]=0;
	int rr, cc, dd, a, b, tp, f;
	int er, ec, ed;
	while(M--){
		scanf("%d %d", &d, &s);
		d=d==1?3:d==2?1:d==3?0:2;
		for(int i=1;i<=s;++i){
			int nr=n+i*dr[d], nc=n+i*dc[d];
			A[t][nr][nc]=0;
		}
		while(1){
			rr=n, cc=n-1, dd=0, a=-1, b=0, f=0;
			while(rr>=0 && cc>=0){
				if(tp=A[t][rr][cc]){
					if(tp==a){
						b++;
					}else{
						if(a>0 && b>=4){
							while(er!=rr || ec!=cc){
								A[t][er][ec]=0;
								if((er<=n && (er==ec+1 || er+ec==N-1)) || (er>n && (er==ec || er+ec==N-1)))
									ed=ed==3?0:ed+1;
								er+=dr[ed], ec+=dc[ed];
							}
							cnt[a]+=b;
							f=1;
						}
						a=tp;
						b=1;
						er=rr, ec=cc, ed=dd;
					}
				}
				if((rr<=n && (rr==cc+1 || rr+cc==N-1)) || (rr>n && (rr==cc || rr+cc==N-1)))
					dd=dd==3?0:dd+1;
				rr+=dr[dd], cc+=dc[dd];
			}
			if(a>0 && b>=4){
				while(er!=rr || ec!=cc){
					A[t][er][ec]=0;
					if((er<=n && (er==ec+1 || er+ec==N-1)) || (er>n && (er==ec || er+ec==N-1)))
						ed=ed==3?0:ed+1;
					er+=dr[ed], ec+=dc[ed];
				}
				cnt[a]+=b;
				f=1;
			}
			if(!f)	break;
		}
		rr=n, cc=n-1, dd=0, a=-1, b=0, f=0;
		er=n, ec=n-1, ed=0;
		while(rr>=0 && cc>=0){
			if(tp=A[t][rr][cc]){
				if(tp==a){
					b++;
				}else{
					if(a>0 && !(er<0 || ec<0)){
						A[nt][er][ec]=b;
						if((er<=n && (er==ec+1 || er+ec==N-1)) || (er>n && (er==ec || er+ec==N-1)))
							ed=ed==3?0:ed+1;
						er+=dr[ed], ec+=dc[ed];
						if(!(er<0 || ec<0)){
							A[nt][er][ec]=a;
							if((er<=n && (er==ec+1 || er+ec==N-1)) || (er>n && (er==ec || er+ec==N-1)))
								ed=ed==3?0:ed+1;
							er+=dr[ed], ec+=dc[ed];
						}
					}
					a=tp;
					b=1;
				}
			}
			if((rr<=n && (rr==cc+1 || rr+cc==N-1)) || (rr>n && (rr==cc || rr+cc==N-1)))
				dd=dd==3?0:dd+1;
			rr+=dr[dd], cc+=dc[dd];
		}
		if(a>0 && !(er<0 || ec<0)){
			A[nt][er][ec]=b;
			if((er<=n && (er==ec+1 || er+ec==N-1)) || (er>n && (er==ec || er+ec==N-1)))
				ed=ed==3?0:ed+1;
			er+=dr[ed], ec+=dc[ed];
			if(!(er<0 || ec<0)){
				A[nt][er][ec]=a;
				if((er<=n && (er==ec+1 || er+ec==N-1)) || (er>n && (er==ec || er+ec==N-1)))
				ed=ed==3?0:ed+1;
				er+=dr[ed], ec+=dc[ed];
			}
		}
		while(er>=0 && ec>=0){
			A[nt][er][ec]=0;
			if((er<=n && (er==ec+1 || er+ec==N-1)) || (er>n && (er==ec || er+ec==N-1)))
			ed=ed==3?0:ed+1;
			er+=dr[ed], ec+=dc[ed];
		}
		nt=t;
		t^=1;
	}
	printf("%d\n", cnt[1]+2*cnt[2]+3*cnt[3]);
	return 0;
}
