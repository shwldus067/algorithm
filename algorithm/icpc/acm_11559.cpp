#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	char arr[12][7], color;
	for(int i=0;i<12;++i)	cin>>arr[i];
	int ans=0, chk=1, cnt=0;
	pii point[72];
	bool visit[12][6];
	while(1){
		for(int i=0;i<12;++i)for(int j=0;j<6;++j)	visit[i][j]=0;
		for(int i=0;i<12;++i){
			for(int j=0;j<6;++j){
				if(arr[i][j]=='.')	continue;
				if(visit[i][j])	continue;
				cnt=1;
				point[0]={i, j};
				color=arr[i][j];
				visit[i][j]=1;
				for(int f=0;f<cnt;++f){
					pii cur=point[f];
					for(int d=0;d<4;++d){
						int nr=cur.first+dr[d], nc=cur.second+dc[d];
						if(nr<0 || nr>11 || nc<0 || nc>5)	continue;
						if(visit[nr][nc])	continue;
						if(arr[nr][nc]!=color)	continue;
						point[cnt++]={nr, nc};
						visit[nr][nc]=1;
					}
				}
				if(cnt>=4){
					chk=0;
					for(int f=0;f<cnt;++f){
						arr[point[f].first][point[f].second]='.';
					}
				}
			}
		}
		if(chk)	break;
		for(int i=0;i<6;++i){
			int row=11;
			for(int j=11;j>=0;--j){
				if(arr[j][i]=='.')	continue;
				if(j==row){
					row--;
					continue;
				}
				arr[row][i]=arr[j][i];
				arr[j][i]='.';
				row--;
			}
		}
		++ans;
		chk=1;
	}
	cout<<ans<<"\n";
	return 0;
}
