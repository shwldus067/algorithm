#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int R, C, dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
char arr[100][101];
void drop(int r, int c){
	int chk[100][100]={0, }, cnt;
	int rmax, rmove=R, top=0, rear=0;
	pii Q[10000];
	for(int i=0;i<4;++i){
		int nr=r+dr[i], nc=c+dc[i];
		if(nr<0 || nr>=R || nc<0 || nc>=C)	continue;
		if(arr[nr][nc]=='x' && !chk[nr][nc]){
			rmax=nr;
			cnt++;
			chk[nr][nc]=cnt;
			top=rear=0;
			Q[rear++]={nr, nc};
			while(top<rear){
				pii cur=Q[top++];
				for(int d=0;d<4;++d){
					int rr=cur.first+dr[d], cc=cur.second+dc[d];
					if(rr<0 || rr>=R || cc<0 || cc>=C)	continue;
					if(chk[rr][cc])	continue;
					if(arr[rr][cc]=='x'){
						chk[rr][cc]=cnt;
						Q[rear++]={rr, cc};
						rmax=max(rmax, rr);
					}
				}
			}
			if(rmax!=R-1){
				for(top=0;top<rear;++top){
					int k, curc=Q[top].second;
					for(k=Q[top].first+1;k<R;++k){
						if(arr[k][curc]=='x')	break;
					}
					if(k<R && chk[k][curc]==cnt)	continue;
					rmove=min(rmove, k-Q[top].first-1);
				}
				for(top=0;top<rear;++top){
					int y=Q[top].first, x=Q[top].second;
					if(chk[y][x]==cnt)
						arr[y][x]='.';
					arr[y+rmove][x]='x';
					chk[y+rmove][x]=0;
				}
				return;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, r, c, t=0, dd[2]={1, -1};
	cin>>R>>C;
	for(int i=0;i<R;++i)	cin>>arr[i];
	cin>>N;
	while(N--){
		cin>>r;
		r=R-r;
		c=t?C-1:0;
		for(int i=0;i<C;++i){
			if(arr[r][c]=='x'){
				arr[r][c]='.';
				drop(r, c);
				break;
			}
			c+=dd[t];
		}
		t^=1;
	}
	for(int i=0;i<R;++i)	cout<<arr[i]<<"\n";
	return 0;
}
