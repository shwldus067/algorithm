#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
int N, num[50][50], K, mm, MM, pr, pc;
char arr[50][50];
set<int> S;
int vec[2500], idx=0;
bool visit[50][50];
int dr[]={-1, -1, 0, 1, 1, 1, 0, -1}, dc[]={0, 1, 1, 1, 0, -1, -1, -1};
bool bfs(){
	queue<pair<int, int> > Q;
	int cnt=0;
	Q.push({pr, pc});
	visit[pr][pc]=true;
	while(Q.size()){
		int cr=Q.front().first, cc=Q.front().second;
		Q.pop();
		for(int i=0;i<8;++i){
			int nr=cr+dr[i], nc=cc+dc[i];
			if(nr<0 || nr>=N || nc<0 || nc>=N || visit[nr][nc])
				continue;
			if(num[nr][nc]<mm || num[nr][nc]>MM)	continue;
			if(arr[nr][nc]=='K')	cnt++;
			if(cnt==K)	return true;
			visit[nr][nc]=true;
			Q.push({nr, nc});
		}
	}
	return false;
}
bool sol(int s, int e){
	mm=vec[s], MM=vec[e];
	if(num[pr][pc]<mm || num[pr][pc]>MM)	return false;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	visit[i][j]=0;
	return bfs();
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
			else if(arr[i][j]=='K')	++K;
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
	int l=0, r=0, res=1e6, ch=1;
	while(ch && l<=r && r<idx && vec[l]<=num[pr][pc]){
		if(sol(l, r)){
			int s=l, e=r;
			while(s<=e){
				int m=(s+e)/2;
				if(sol(m, r))	l=m, s=m+1;
				else	e=m-1;
			}
			res=min(res, vec[r]-vec[l]);
			l++;
		}
		else{
			int s=r, e=idx-1;
			ch=0;
			while(s<=e){
				int m=(s+e)/2;
				if(sol(l, m))	e=m-1, r=m, ch=1;
				else	s=m+1;
			}
			if(ch)	res=min(res, vec[r]-vec[l]);
			l++;
		}
	}
	cout<<res<<"\n";
	return 0;
}
