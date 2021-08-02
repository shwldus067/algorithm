#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int N, num[50][50], K, mm, MM, pr, pc;
char arr[50][50];
set<int> S;
vector<pair<int, int> > Ks;
int vec[2500], idx=0;
bool visit[50][50];
int mnum[50][50];
int dr[]={-1, -1, 0, 1, 1, 1, 0, -1}, dc[]={0, 1, 1, 1, 0, -1, -1, -1};
int bfsl(int lb){
	if(lb>num[pr][pc])	return -1;
	int ub=num[pr][pc];
	queue<pair<int, int> > Q;
	Q.push({pr, pc});
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			visit[i][j]=0;
			mnum[i][j]=1e9;
		}
	}
	mnum[pr][pc]=ub;
	int cnt=0;
	while(Q.size()){
		int cr=Q.front().first, cc=Q.front().second;
		Q.pop();
		if(arr[cr][cc]=='K' && !visit[cr][cc]){
			cnt++;
			visit[cr][cc]=1;
		}
		for(int i=0;i<8;++i){
			int nr=cr+dr[i], nc=cc+dc[i], tp;
			if(nr<0 || nr>=N || nc<0 || nc>=N || num[nr][nc]<lb)
				continue;
			if(mnum[nr][nc]>(tp=max(mnum[cr][cc], num[nr][nc]))){
				mnum[nr][nc]=tp;
				Q.push({nr, nc});
			}
		}
	}
	if(cnt<K)	return -1;
	for(auto &it:Ks){
		ub=max(ub, mnum[it.first][it.second]);
	}
	return ub;
}
int bfsu(int ub){
	if(ub<num[pr][pc])	return -1;
	int lb=num[pr][pc];
	queue<pair<int, int> > Q;
	Q.push({pr, pc});
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			visit[i][j]=0;
			mnum[i][j]=-1;
		}
	}
	mnum[pr][pc]=lb;
	int cnt=0;
	while(Q.size()){
		int cr=Q.front().first, cc=Q.front().second;
		Q.pop();
		if(arr[cr][cc]=='K' && !visit[cr][cc]){
			cnt++;
			visit[cr][cc]=1;
		}
		for(int i=0;i<8;++i){
			int nr=cr+dr[i], nc=cc+dc[i], tp;
			if(nr<0 || nr>=N || nc<0 || nc>=N || num[nr][nc]>ub)
				continue;
			if(mnum[nr][nc]<(tp=min(mnum[cr][cc], num[nr][nc]))){
				mnum[nr][nc]=tp;
				Q.push({nr, nc});
			}
		}
	}
	if(cnt<K)	return -1;
	for(auto &it:Ks){
		lb=min(lb, mnum[it.first][it.second]);
	}
	return lb;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>arr[i][j];
			if(arr[i][j]=='P')	pr=i, pc=j;
			else if(arr[i][j]=='K')	++K, Ks.push_back({i, j});
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>num[i][j];
			S.insert(num[i][j]);
		}
	}
	for(auto iter:S){
		vec[idx++]=iter;
	}
	int res=1e6;
	for(int i=0;i<idx;){
		int ub=bfsl(vec[i]);
		if(ub==-1)	break;
		int lb=bfsu(ub);
		if(lb==-1)	break;
		res=min(res, ub-lb);
		i=upper_bound(vec, vec+idx, lb)-vec;
	}
	cout<<res<<"\n";
	return 0;
}
