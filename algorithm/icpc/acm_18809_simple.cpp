#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, G, R, arr[50][50], ldx, ans;
int dr[4]={-1, 1, 0, 0}, dc[4]={0, 0, -1, 1};
int visit[50][50], p[10];
pii land[10];
void bfs(){
	int flw=0, cnt=2;
	queue<pii> rq, gq;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)	visit[i][j]=arr[i][j];
	for(int i=0;i<ldx;++i){
		if(p[i]==1){
			gq.push(land[i]);
			visit[land[i].first][land[i].second]=0;
		}
		else if(p[i]==2){
			rq.push(land[i]);
			visit[land[i].first][land[i].second]=0;
		}
	}
	while(gq.size() && rq.size()){
		int sz=gq.size();
		int x, y;
		while(sz--){
			x=gq.front().first, y=gq.front().second;
			gq.pop();
			if(visit[x][y]<0)	continue;
			if(x>0 && visit[x-1][y]==1){
				visit[x-1][y]=cnt;
				gq.push({x-1, y});
			}
			if(y>0 && visit[x][y-1]==1){
				visit[x][y-1]=cnt;
				gq.push({x, y-1});
			}
			if(x<N-1 && visit[x+1][y]==1){
				visit[x+1][y]=cnt;
				gq.push({x+1, y});
			}
			if(y<M-1 && visit[x][y+1]==1){
				visit[x][y+1]=cnt;
				gq.push({x, y+1});
			}
		}
		sz=rq.size();
		while(sz--){
			x=rq.front().first, y=rq.front().second;
			rq.pop();
			if(x>0){
				if(visit[x-1][y]==1){
					visit[x-1][y]=-cnt;
					rq.push({x-1, y});
				}
				else if(visit[x-1][y]==cnt){
					visit[x-1][y]=-cnt;
					flw++;
				}
			}
			if(y>0){
				if(visit[x][y-1]==1){
					visit[x][y-1]=-cnt;
					rq.push({x, y-1});
				}
				else if(visit[x][y-1]==cnt){
					visit[x][y-1]=-cnt;
					flw++;
				}
			}
			if(x<N-1){
				if(visit[x+1][y]==1){
					visit[x+1][y]=-cnt;
					rq.push({x+1, y});
				}
				else if(visit[x+1][y]==cnt){
					visit[x+1][y]=-cnt;
					flw++;
				}
			}
			if(y<M-1){
				if(visit[x][y+1]==1){
					visit[x][y+1]=-cnt;
					rq.push({x, y+1});
				}
				else if(visit[x][y+1]==cnt){
					visit[x][y+1]=-cnt;
					flw++;
				}
			}
		}
		cnt++;
	}
	if(flw>ans)	ans=flw;
}
void solr(int x, int r){
	if(r==R){
		bfs();
		return;
	}
	for(int i=x;i<ldx;++i){
		if(!p[i]){
			p[i]=2;
			solr(i+1, r+1);
			p[i]=0;
		}
	}
}
void solg(int x, int g){
	if(g==G){
		solr(0, 0);
		return;
	}
	for(int i=x;i<ldx;++i){
		if(!p[i]){
			p[i]=1;
			solg(i+1, g+1);
			p[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>G>>R;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>arr[i][j];
			if(arr[i][j]==2){
				land[ldx++]={i, j};
				arr[i][j]=1;
			}
		}
	}
	solg(0, 0);
	cout<<ans<<"\n";
	return 0;
}
