#include<iostream>
using namespace std;
int N, M, A[8][8], cnt, idx, ans;
int dr[5]={-1, 0, 1, 0, -1}, dc[5]={0, 1, 0, -1, 0};
pair<int, int> cctv[8];
void sol(int n, int sum){
	if(n==idx){
		ans=ans>sum?ans:sum;
		return;
	}
	int r=cctv[n].first, c=cctv[n].second, t=A[r][c];
	int nr, nc, x;
	if(t==1){
		for(int i=0;i<4;++i){
			nr=r+dr[i], nc=c+dc[i], x=0;
			while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
				if(A[nr][nc]==0)	x++, A[nr][nc]=7;
				else if(A[nr][nc]>6) A[nr][nc]+=7;
				nr+=dr[i], nc+=dc[i];
			}
			sol(n+1, sum+x);
			nr-=dr[i], nc-=dc[i];
			while(nr!=r || nc!=c){
				if(A[nr][nc]>6) A[nr][nc]-=7;
				nr-=dr[i], nc-=dc[i];
			}
		}
	}else if(t==2){
		for(int i=0;i<2;++i){
			x=0;
			for(int j=i;j<4;j+=2){
				nr=r+dr[j], nc=c+dc[j];
				while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
					if(A[nr][nc]==0)	x++, A[nr][nc]=7;
					else if(A[nr][nc]>6) A[nr][nc]+=7;
					nr+=dr[j], nc+=dc[j];
				}
			}
			sol(n+1, sum+x);
			for(int j=i;j<4;j+=2){
				nr=r+dr[j], nc=c+dc[j];
				while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
					if(A[nr][nc]>6) A[nr][nc]-=7;
					nr+=dr[j], nc+=dc[j];
				}
			}
		}
	}else if(t==3){
		int a=0;
		nr=r-1, nc=c;
		while(nr>=0 && A[nr][nc]!=6){
			if(A[nr][nc]==0)	a++, A[nr][nc]=7;
			else if(A[nr][nc]>6) A[nr][nc]+=7;
			--nr;
		}
		for(int i=1;i<5;i+=2){
			nr=r+dr[i], nc=c+dc[i], x=0;
			while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
				if(A[nr][nc]==0)	x++, A[nr][nc]=7;
				else if(A[nr][nc]>6) A[nr][nc]+=7;
				nr+=dr[i], nc+=dc[i];
			}
			sol(n+1, sum+x+a);
			a=x;--i;
			nr=r+dr[i], nc=c+dc[i];
			while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
				if(A[nr][nc]>6) A[nr][nc]-=7;
				nr+=dr[i], nc+=dc[i];
			}
		}
		nr=r-1, nc=c;
		while(nr>=0 && A[nr][nc]!=6){
			if(A[nr][nc]>6) A[nr][nc]-=7;
			--nr;
		}
	}else if(t==4){
		x=0;
		for(int i=0;i<4;++i){
			nr=r+dr[i], nc=c+dc[i];
			while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
				if(A[nr][nc]==0)	x++, A[nr][nc]=7;
				else if(A[nr][nc]>6) A[nr][nc]+=7;
				nr+=dr[i], nc+=dc[i];
			}
		}
		int a;
		for(int i=0;i<4;++i){
			nr=r+dr[i], nc=c+dc[i], a=0;
			while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
				if(A[nr][nc]>6) A[nr][nc]-=7;
				if(A[nr][nc]==0)	++a;
				nr+=dr[i], nc+=dc[i];
			}
			sol(n+1, sum+x-a);
			nr=r+dr[i], nc=c+dc[i];
			while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
				if(A[nr][nc]==0)	A[nr][nc]=7;
				else if(A[nr][nc]>6) A[nr][nc]+=7;
				nr+=dr[i], nc+=dc[i];
			}
		}
		for(int i=0;i<4;++i){
			nr=r+dr[i], nc=c+dc[i];
			while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
				if(A[nr][nc]>6) A[nr][nc]-=7;
				nr+=dr[i], nc+=dc[i];
			}
		}
	}else{
		x=0;
		for(int i=0;i<4;++i){
			nr=r+dr[i], nc=c+dc[i];
			while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
				if(A[nr][nc]==0)	x++, A[nr][nc]=7;
				else if(A[nr][nc]>6) A[nr][nc]+=7;
				nr+=dr[i], nc+=dc[i];
			}
		}
		sol(n+1, sum+x);
		for(int i=0;i<4;++i){
			nr=r+dr[i], nc=c+dc[i];
			while(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]!=6){
				if(A[nr][nc]>6) A[nr][nc]-=7;
				nr+=dr[i], nc+=dc[i];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j){
		cin>>A[i][j];
		if(A[i][j]){
			cnt++;
			if(A[i][j]<6)	cctv[idx++]={i, j};
		}
	}
	sol(0, 0);
	cout<<N*M-ans-cnt<<"\n";
	return 0;
}
