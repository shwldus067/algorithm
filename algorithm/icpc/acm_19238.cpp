#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int N, M, K, A[20][20], R, C, P[20][20];
int dr[4]={-1, 0, 0, 1}, dc[4]={0, -1, 1, 0};
pair<int, int> D[401];
int passenger(){
	if(P[R][C]>0)	return P[R][C];
	bool pvisit[20][20]={0, };
	queue<pair<int, int> > Q;
	vector<pair<int, int> > vec;
	Q.push({R, C});
	int size, cost=1, find=0;
	while(size=Q.size()){
		if(cost>K)	break;
		while(size--){
			int r=Q.front().first, c=Q.front().second;
			Q.pop();
			for(int d=0;d<4;++d){
				int nr=r+dr[d], nc=c+dc[d];
				if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
				if(pvisit[nr][nc] || A[nr][nc])	continue;
				if(P[nr][nc]>0){
					find=1;
					vec.push_back({nr, nc});
					continue;
				}
				pvisit[nr][nc]=1;
				Q.push({nr, nc});
			}
		}
		if(find){
			pair<int, int> pas={N, N};
			for(pair<int, int> p:vec){
				if(pas.first>p.first)	pas=p;
				else if(pas.first==p.first && pas.second>p.second)	pas=p;
			}
			R=pas.first, C=pas.second;
			K-=cost;
			return P[R][C];
		}
		++cost;
	}
	return -1;
}
int destination(int des){
	int rr=D[des].first, cc=D[des].second;
	if(R==rr && C==cc)	return 0;
	bool dvisit[20][20]={0, };
	queue<pair<int, int> > qu;
	qu.push({R, C});
	int size, cost=1;
	while(size=qu.size()){
		if(cost>K)	break;
		while(size--){
			int r=qu.front().first, c=qu.front().second;
			qu.pop();
			for(int d=0;d<4;++d){
				int nr=r+dr[d], nc=c+dc[d];
				if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
				if(dvisit[nr][nc] || A[nr][nc])	continue;
				if(nr==rr && nc==cc){
					R=nr, C=nc;
					return cost;
				}
				dvisit[nr][nc]=1;
				qu.push({nr, nc});
			}
		}
		++cost;
	}
	return -1;
}
int run(){
	int fare, psg;
	while(M--){
		psg=passenger();
		if(psg<0){
			return -1;
		}
		P[R][C]=0;
		fare=destination(psg);
		if(fare<0){
			return -1;
		}
		K+=fare;
	}
	return K;
}
int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%d", &A[i][j]);
	scanf("%d %d", &R, &C);
	R--, C--;
	for(int i=1;i<=M;++i){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		P[a-1][b-1]=i;
		D[i]={c-1, d-1};
	}
	printf("%d\n", run());
	return 0;
}
