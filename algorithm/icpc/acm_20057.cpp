#include<iostream>
using namespace std;
int N, A[500][500], ans;
int dr[4]={0, 1, 0, -1}, dc[4]={-1, 0, 1, 0};
int add(int r, int c, int p, int a){
	int m=a*p/100;
	if(r<0 || r>=N || c<0 || c>=N){
		ans+=m;
	}
	else	A[r][c]+=m;
	return m;
}
void move(int r, int c, int d){
	int pr=r-dr[d], pc=c-dc[d], sum=0;
	int nr=r+dr[d], nc=c+dc[d], a=A[r][c];
	if(d&1){
		sum+=add(pr, pc-1, 1, a);
		sum+=add(pr, pc+1, 1, a);
		sum+=add(r, c+1, 7, a);
		sum+=add(r, c-1, 7, a);
		sum+=add(r, c+2, 2, a);
		sum+=add(r, c-2, 2, a);
		sum+=add(nr, nc+1, 10, a);
		sum+=add(nr, nc-1, 10, a);
		sum+=add(nr+dr[d], nc+dc[d], 5, a);
		add(nr, nc, 100, a-sum);
	}
	else{
		sum+=add(pr-1, pc, 1, a);
		sum+=add(pr+1, pc, 1, a);
		sum+=add(r+1, c, 7, a);
		sum+=add(r-1, c, 7, a);
		sum+=add(r+2, c, 2, a);
		sum+=add(r-2, c, 2, a);
		sum+=add(nr+1, nc, 10, a);
		sum+=add(nr-1, nc, 10, a);
		sum+=add(nr+dr[d], nc+dc[d], 5, a);
		add(nr, nc, 100, a-sum);
	}
	A[r][c]=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>A[i][j];
	int r=N/2, c=N/2, cnt=1, d=0, f=0;
	while(r || c){
		for(int i=0;i<cnt;++i){
			r+=dr[d], c+=dc[d];
			if(r<0 || r>=N || c<0 || c>=N){
				f=1;break;
			}
			move(r, c, d);
		}
		if(f)	break;
		d=d>2 ? 0:d+1;
		for(int i=0;i<cnt;++i){
			r+=dr[d], c+=dc[d];
			if(r<0 || r>=N || c<0 || c>=N){
				f=1;break;
			}
			move(r, c, d);
		}
		if(f)	break;
		++cnt;
		d=d>2 ? 0:d+1;
	}
	cout<<ans<<"\n";
	return 0;
}
