#include<iostream>
using namespace std;
int N, d[1<<15][16], w[16][16], b[1<<15], ans=1e9;
int main(){	//d[i][j]:도시 방문 bit가 i일 때 j번째 도시 방문 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>w[i][j];
	for(int i=1;i<N;++i)	d[0][i-1]=w[0][i];	//0번째를 시작으로 i번째 도시 방문 
	for(int i=0;i<N-1;++i)	b[1<<i]=i+1;	//몇 번째 bit인지 저장 
	int i, j, k, ii, jj, last=1<<(N-1);
	for(i=1;i<last;++i){	//i:다음 방문 상태, 0에서 출발로 지정해 0번째를 방문하는 경우는 고려하지 않음 
		for(j=i;j;j=k){	//방문한 도시 선택 
			k=j&(j-1);	//1인 마지막 bit off, 다음 방문 상태에서 bit를 하나씩 제거해 출발할 bit 선택 
			int l=b[j^k];	//출발 도시 선택, 첫 방문 도시시가 정해져 있으므로 0~15번 째 bit만 생각 
			int x=d[i^j^k][l-1];	//다른 도시로 이동하기 전 비용 
			if(!x)	continue;	//0일 경우 해당 방문을 하지 못했음을 의미 
			for(ii=~i&(last-1);ii;ii=jj){	//방문하지 않은 도시 선택 
				jj=ii&(ii-1);	//1인 마지막 bit off, 다음 방문할 도 
				int m=b[ii^jj];	//도착 도시 선택 
				int y=w[l][m];	//추가 이동 비용 
				if(!y)	continue;
				if(!d[i][m-1] || d[i][m-1]>x+y)	d[i][m-1]=x+y;
			}
		}
	}
	--last;
	for(i=0;i<N-1;++i){	//처음 도시로 다시 돌아감 
		int x=w[i+1][0], y=d[last^(1<<i)][i];
		if(x && y && ans>x+y)	ans=x+y;
	}
	cout<<ans<<"\n";
	return 0;
}
