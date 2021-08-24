#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int> > pip;
int arr[5][5][5], board[5][5][5], ord[5], ans=125;
int dd[6][3]={{-1, 0, 0}, {0, -1, 0}, {0, 0, 1},
			 {0, 1, 0}, {0, 0, -1}, {1, 0, 0}};
bool chk[5];
void bfs(){
	int res=0, size;
	bool visit[5][5][5]={0, };
	queue<pip> Q;
	Q.push({0, {0, 0}});
	visit[0][0][0]=1;
	while(size=Q.size()){
		while(size--){
			int l=Q.front().first;
			int r=Q.front().second.first, c=Q.front().second.second;
			Q.pop();
			if(l==4 && r==4 && c==4){
				if(res==12){
					cout<<"12\n";
					exit(0);
				}
				ans=res;
				return;
			}
			for(int d=0;d<6;++d){
				int nl=l+dd[d][0], nr=r+dd[d][1], nc=c+dd[d][2];
				if(nl<0 || nl>4 || nr<0 || nr>4 || nc<0 || nc>4)	continue;
				if(board[nl][nr][nc]==0)	continue;
				if(visit[nl][nr][nc])	continue;
				visit[nl][nr][nc]=1;
				Q.push({nl, {nr, nc}});
			}
		}
		++res;
		if(ans<=res)	return;
	}
}
void rotation(int idx){
	int narr[5][5];
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			narr[4-j][i]=arr[idx][i][j];
		}
	}
	for(int i=0;i<5;++i)for(int j=0;j<5;++j)	arr[idx][i][j]=narr[i][j];
}
void sol(int n){
	if(n==5){
		if(arr[ord[0]][0][0]==0 || arr[ord[4]][4][4]==0)	return;
		for(int i=0;i<5;++i){
			for(int j=0;j<5;++j)for(int k=0;k<5;++k){
				board[i][j][k]=arr[ord[i]][j][k];
			}
		}
		bfs();
		return;
	}
	for(int d=0;d<4;++d){
		if(arr[ord[0]][0][0]){
			sol(n+1);
		}
		rotation(ord[n]);
	}
}
void per(int n){
	if(n==5){
		sol(0);
		return;
	}
	for(int i=0;i<5;++i){
		if(chk[i])	continue;
		chk[i]=1;
		ord[n]=i;
		per(n+1);
		chk[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<5;++i)for(int j=0;j<5;++j)for(int k=0;k<5;++k)
		cin>>arr[i][j][k];
	per(0);
	if(ans==125)	cout<<"-1\n";
	else	cout<<ans<<"\n";
	return 0;
}
