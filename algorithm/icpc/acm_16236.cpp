#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const int inf=~(1<<31);
int N, M, arr[20][20], res, size=2, cnt=0, dis;
int dr[]={-1, 0, 0, 1}, dc[]={0, -1, 1, 0};
bool visit[20][20];
pii cur, to;
bool chk(int r, int c){
	return r>=0 && r<N && c>=0 && c<N;
}
bool dist(){
	int d=0, r, c, s;
	queue<pii> Q;
	vector<pii> lis;
	Q.push(cur);
	pii fir;
	dis=1;
	fill(&visit[0][0], &visit[N-1][N], false);
	visit[cur.first][cur.second]=true;
	while(s=Q.size()){
		while(s--){
			fir=Q.front();
			Q.pop();
			for(int i=0;i<4;i++){
				r=fir.first+dr[i], c=fir.second+dc[i];
				if(!chk(r, c) || visit[r][c])	continue;
				if(arr[r][c]==0 || arr[r][c]==size){
					visit[r][c]=true;
					Q.push({r, c});
				}
				else if(arr[r][c]<size){
					lis.push_back({r, c});
				}
			}
		}
		if(lis.size()){
			sort(lis.begin(), lis.end());
			to=lis[0];
			return true;
		}
		dis++;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int t;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>t;
			arr[i][j]=t;
			if(t>=1 && t<=6)	M++;
			else if(t==9)	cur={i, j};
		}
	}
	while(M--){
		if(dist()){
			arr[cur.first][cur.second]=0;
			arr[to.first][to.second]=9;
			cur=to;
			cnt++;
			res+=dis;
			if(size==cnt){
				size++;
				cnt=0;
			}
		}
		else{
			break;
		}
	}
	cout<<res<<"\n";
	return 0;
}
